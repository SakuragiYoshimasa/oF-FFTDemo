#include "ofApp.h"

void ofApp::setup(){
    

    window_width = ofGetWindowWidth();
    window_height = ofGetWindowWidth() * 0.375;
    window_top = (ofGetWindowHeight() - window_height) / 2;

    ofSetFrameRate(60);
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    soundPlayer.loadSound("39.mp3");
    soundPlayer.setLoop(true);
    soundPlayer.play();
    
    for(int i = 0; i < BOX_NUM; i++){
        soundBlocks.push_back(new SoundBlock(i));
    }
    
    for (int i = 0; i< WAVE_NUM; i++) {
        soundWaves.push_back(new SoundWave(i));
    }
    
    SpectrumAmount = 0;
    waveGenarate = false;
    
    receiver.setup(2000);
    
    firstPerson = Person();
    kinectSendData = false;
    
    cameraStop = false;

}

void ofApp::update(){
    
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(BOX_NUM);
    SpectrumAmount = 0;

    while(receiver.hasWaitingMessages()){
        ofxOscMessage message;
        receiver.getNextMessage(&message);
        if(message.getAddress()=="/osc/jointPosition"){
           
            firstPerson.initJointPosition();
            for(int i = 0; i < message.getNumArgs()/3 - 1; i++){
                ofPoint joint;
                joint.x = 100*message.getArgAsFloat(3*i);
                joint.y = 100*message.getArgAsFloat(1 + 3*i) + MAX_HEIGHT + 50;
                joint.z = -100*message.getArgAsFloat(2 + 3*i);
                firstPerson.pushJointPosition(joint);
            }
        }
        if(message.getAddress()=="/osc/cameraSystem"){
            
              if(message.getArgAsInt64(0) == 10){
                    cameraStop = true;
                }
                if(message.getArgAsInt64(0) == 20){
                    cameraStop = false;
                }
        }
    }
}

void ofApp::draw(){

    //glViewport(0, 0, window_width/2, window_height);
    if(firstPerson.jointPositions.size() > 0){
        if(!cameraStop){
          //  if(flaf){
            camera.setPosition(firstPerson.jointPositions[1]);
            camera.lookAt(firstPerson.jointPositions[0]);
          //  }
        }
    }
    drawScene();
    
   /* glViewport(window_width/2, 0, window_width/2, window_height);
    
    drawScene();
    */

}

void ofApp::drawScene(){
    
    camera.begin();
    
    ofPushMatrix();
    ofRotateY(90);
    ofTranslate(-650, 0,-1900);
    
    for(int i=0; i<BOX_NUM; i++){
        
        soundBlocks.at(i) -> updateSpectrumPower(fft[i]);
        soundBlocks.at(i) -> drawSoundBox();
        
        if(fft[i]*SPECTRUM_GAIN > 14){
            SpectrumAmount += 1;
        }
    }
    
    if(SpectrumAmount > BOX_NUM * 0.9){
        waveGenarate = true;
    }
    
    if(waveGenarate){
        for (int i=0; i<WAVE_NUM; i++) {
            soundWaves.at(i) -> DrawSoundWave();
        }
        if(SpectrumAmount < BOX_NUM * 0.6){
            waveGenarate = false;
        }
    }
    
    ofPopMatrix();
    
    ofSetColor(255, 255, 255, 150);
    
    firstPerson.drawPerson();
    
    camera.end();
}
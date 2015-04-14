#pragma once
#include "ofMain.h"
#include "SoundBlock.h"
#include "SonudWave.h"
#include "Definition.h"
#include "Person.h"
#include "ofxOsc.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void drawScene();
    
    
    vector<SoundBlock *> soundBlocks;
    vector<SoundWave *> soundWaves;
    Person firstPerson;
    
    ofSoundPlayer soundPlayer;
    ofCamera camera;
    
    float * fft;
    short SpectrumBand;
    short SpectrumAmount;
    bool waveGenarate;
    bool kinectSendData;
    
    ofxOscReceiver receiver;

    
    float window_width ;
    float window_height;
    float window_top ;
    
    bool cameraStop;
    bool flaf;
    
};
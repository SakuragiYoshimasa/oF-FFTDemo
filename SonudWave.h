//
//  SonudWave.h
//  lit_leaders
//
//  Created by 櫻木善将 on 2015/03/11.
//
//
#define MAX_RADIUS 50


#include "ofMain.h"
#include "Definition.h"

class SoundWave{
    
private:
    
    float radius = 10;
    float resizeRate;
    ofPoint center;
    ofColor color;
    
public:
    
    SoundWave(int i){
        
        radius *= ofRandom(i,MAX_RADIUS);
        center = ofPoint(ofRandom(0,POLYGON_SIDE_LENGTH * 32),ofRandom(0,MAX_HEIGHT ),ofRandom(0, POLYGON_SIDE_LENGTH * 32));
        color = ofColor(ofRandom(256),ofRandom(256),ofRandom(256));
        resizeRate = ofRandom(1.03, 1.1);
        
    }
    ~SoundWave(){}
    
    void DrawSoundWave(){
        
        ofSetCircleResolution(50);
        ofSetColor(color);
        ofSpherePrimitive soundWave;
        soundWave.setPosition(center);
        soundWave.set(radius, 20);
        soundWave.drawWireframe();
        radius *= resizeRate;
        if(radius > MAX_RADIUS){
            radius = 10;
            SoundWave(10);
        }
    }
};
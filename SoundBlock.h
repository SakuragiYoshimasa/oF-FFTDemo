//
//  SoundBlock.h
//  lit_leaders
//
//  Created by 櫻木善将 on 2015/03/10.
//
//

#include "ofMain.h"
#include "BlockHeightAjuster.h"
#include "Definition.h"

class SoundBlock {
    
private:
    float boxNumber;
    BlockState state = BlockState();
    ofColor color;
    ofPoint soundBlockSizePojition;
    
public:
    
    SoundBlock(int i){
        
        soundBlockSizePojition.set((POLYGON_SIDE_LENGTH+INSET)*( i % NUM_BOX_LINE ) , 0 , (POLYGON_SIDE_LENGTH + INSET )*(i /NUM_BOX_LINE) );
        boxNumber = i;
    
    }
    
    ~SoundBlock(){
        
    }
    
    void updateSpectrumPower(float newSpectrumPower){

        state = BlockHeightAjuster::AjustHeight(newSpectrumPower, state);
    }
    
    void drawSoundBox(){
        
        soundBlockSizePojition.y = state.height/2;
        color.setHsb((boxNumber/ BOX_NUM) * 255, 255, 50);
        ofSetColor(color, 150*(1.0-state.height/MAX_HEIGHT) + 105);
        ofBoxPrimitive box;
        box.set(POLYGON_SIDE_LENGTH,state.height,POLYGON_SIDE_LENGTH);
        box.setPosition(soundBlockSizePojition);
        box.draw();
    }
};
//
//  BlockHeightAjuster.h
//  lit_leaders
//
//  Created by 櫻木善将 on 2015/03/10.
//
//

#include "Definition.h"
#include "BlockState.h"


class BlockHeightAjuster {
public:
    static BlockState AjustHeight(float newSpectrum,BlockState nowState){
        
        BlockState nextState = BlockState();
        
        switch (nowState.transformState) {
            case 1:
                
                if(newSpectrum*SPECTRUM_GAIN > nowState.height){
                    
                    nextState.transformState = 1;
                    nextState.height = nowState.height + (newSpectrum*SPECTRUM_GAIN - nowState.height)/TRANSFORM_SPEED;
                    
                    if(nextState.height > MAX_HEIGHT){
                        nextState.height = MAX_HEIGHT;
                    }
                    
                }else{
                    nextState.transformState = 0;
                    nextState.height = nowState.height;
                    
                }
                return nextState;
            
            case 0:
     
                if(newSpectrum*SPECTRUM_GAIN > nowState.height){
                    nextState.transformState = 1;
                    nextState.height = nowState.height + (newSpectrum*SPECTRUM_GAIN - nowState.height)/TRANSFORM_SPEED;
                    return nextState;
                }else{
                    nextState.transformState = -1;
                    nextState.height = nowState.height - (nowState.height - newSpectrum*SPECTRUM_GAIN )/TRANSFORM_SPEED;
                    return nextState;
                }
                
                break;
                
            case -1:
                
                if(newSpectrum*SPECTRUM_GAIN < nowState.height){
                    
                    nextState.transformState = -1;
                    nextState.height = nowState.height - (nowState.height - newSpectrum*SPECTRUM_GAIN)/TRANSFORM_SPEED;
                    
                    if(nextState.height < MIN_HEIGHT){
                        nextState.height = MIN_HEIGHT;
                    }
                    
                }else{
                    nextState.transformState = 0;
                    nextState.height = nowState.height;
                    
                }
                return nextState;
                break;
            default:
                break;
        }
    }
};
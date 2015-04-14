//
//  BlockState.h
//  lit_leaders
//
//  Created by 櫻木善将 on 2015/03/10.
//
//

class BlockState {
    
public:
    
    short transformState = 0; //1:up 0:stop -1:down
    float height = 10;
    BlockState(){}
    ~BlockState(){}
    
};
//
//  Person.h
//  lit_leaders
//
//  Created by 櫻木善将 on 2015/03/11.
//
//
#include "ofMain.h"

class Person {

public:
    vector<ofPoint> jointPositions;
    bool hasJointInfo;
    float offset = 0;
  
    Person(){
        hasJointInfo = false;
    }
    ~Person(){}
    
    void initJointPosition(){
        jointPositions.clear();
    }
    
    void pushJointPosition(ofPoint jointPosition){
        jointPositions.push_back(jointPosition);
        cout << "Add joint!" << endl;
    }
    
    
    void drawPerson(){
        cout << jointPositions.size() << endl;
        for(int i = 0; i < jointPositions.size(); i++){
            
            
            
                jointPositions[i].y += offset;
                //ofSetColor(255, 255, 255, 150);
                ofSpherePrimitive joint;
                joint.set(3, 10);
                joint.setPosition(jointPositions[i]);
                joint.draw();
            
        }
    }
    
    void updateOffset(float newOffset){
        offset = newOffset;
    }
    
    void checkLocation(){
        float x = jointPositions[0].x;
        float y = jointPositions[0].y;
        float z = jointPositions[0].z;

    }
};

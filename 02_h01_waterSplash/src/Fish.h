//
//  Fish.h
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#pragma once
#include "ofMain.h"

class Fish : public ofPoint {
    
public:
    ofPoint vel;
    ofPoint acc;
    float topSpeed;
    float angle = 0;

    ofPoint update(ofPoint track); //returns velocity ofPoint
    void draw();
    
};

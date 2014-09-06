//
//  Water.h
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#pragma once
#include "ofMain.h"

class Water {
    
public:
    
    Water(float X, float Y, float H, float SPD, float TH);
    
    float x;
    float y;
    float h;
    float spd;
    float targetHeight;
    
    void update(float DAMP, float TEN);
    void display();
    
};
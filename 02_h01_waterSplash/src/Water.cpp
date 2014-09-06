//
//  Water.cpp
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#include "Water.h"

Water::Water(float X, float Y, float H, float SPD, float TH) {
    x = X;
    y = Y;
    h = TH;
    spd = SPD;
    targetHeight = H;
}

void Water::update(float DAMP, float TEN) {
    float x = targetHeight - h;
    spd += TEN * x - spd * DAMP;
    h += spd;
}

void Water::display() {
    ofSetColor(120,160,190);
    ofFill();
    ofRect(x,h,5,ofGetHeight()*1.5);
}
//
//  Spawner.h
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#pragma once
#include "ofMain.h"

class Spawner {
    
public:
    ofPoint center;
    
    bool update();
    void draw();
    
    vector<ofPoint> tail;

};
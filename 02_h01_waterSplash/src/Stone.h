//
//  Stone.h
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#pragma once
#include "ofMain.h"

class Stone {
    
public:
    
    Stone(ofPoint p);
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofPoint alpha;
    
    void run();
    void display();

};
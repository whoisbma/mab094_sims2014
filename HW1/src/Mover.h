//
//  Mover.h
//  HW1
//
//  Created by Bryan Ma on 9/3/14.
//
//

#ifndef __HW1__Mover__
#define __HW1__Mover__

#include <iostream>

#include "ofMain.h"

#endif /* defined(__HW1__Mover__) */

class Mover {
    public:
        void update(float DX, float DY, int sizemod);
        void draw();
        void setPos(float X, float Y);
    
    private:
        ofPoint pos;
        float w = 50;
        int r = ofRandom(200);
        int g = ofRandom(120);
        int b = ofRandom(200);
    
};
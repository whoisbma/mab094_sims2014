//
//  Follower.h
//  HW1
//
//  Created by Bryan Ma on 9/3/14.
//
//

#ifndef __HW1__Follower__
#define __HW1__Follower__

#include <iostream>
#include "ofMain.h"


class Follower {
    public:
    
        Follower();
        void update(float X, float Y);
        void draw();
        ofPoint pos;
        float w = 20;
        float c = 255;
        float offset;
};


#endif /* defined(__HW1__Follower__) */
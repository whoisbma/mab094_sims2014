//
//  Stone.cpp
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#include "Stone.h"


Stone::Stone(ofPoint p) {
    pos.set(p);
    acc.set(0, 0.12);
    vel.set(0, 0);
}

void Stone::run() {
    vel = vel + acc;
    pos = pos + vel;
}

void Stone::display() {
    ofSetColor(120,160,190);
    ofFill();
    ofCircle(pos, 2);
}
//
//  Follower.cpp
//  HW1
//
//  Created by Bryan Ma on 9/3/14.
//
//

#include "Follower.h"

Follower::Follower() {
    offset = 0.03;
}

void Follower::draw() {
    ofFill();
    ofSetColor(c);
    ofEllipse(pos.x, pos.y, w, w);
}

void Follower::update(float X, float Y) {
    pos.x = offset * X + (1-offset) * pos.x;
    pos.y = offset * Y + (1-offset) * pos.y;
}
//
//  Fish.cpp
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#include "Fish.h"

ofPoint Fish::update(ofPoint track) {
    //set(0.03 * track + (1. - 0.03) * (*this));
    
    ofPoint dir = track - *this;
    
    angle = ofLerp(angle, atan2(dir.y, dir.x), 0.1);
    
    if (angle < -PI) angle += PI*2.;
    if (angle > PI) angle -= PI*2.;
    
    dir.normalize();
    dir = dir * ofRandom(1);
    acc = dir;
    vel = vel + acc;
    vel.limit(3.0);
    return vel; //not sure if there's a way to add vector to *this so i'm returning it
}

void Fish::draw() {
    ofPushMatrix();
    ofTranslate(*this);
    ofRotate(ofRadToDeg(angle));
    ofPushStyle();
    ofSetColor(255);
    ofFill();
    //ofSetRectMode(OF_RECTMODE_CENTER);
    ofTriangle(-5,5,0,-5,5,5);
    //ofRect(0, 0, 5, 5);
    ofPopStyle();
    ofPopMatrix();
}
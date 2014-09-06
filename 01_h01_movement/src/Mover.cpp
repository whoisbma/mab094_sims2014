//
//  Mover.cpp
//  HW1
//
//  Created by Bryan Ma on 9/3/14.
//
//

#include "Mover.h"



void Mover::update(float DX, float DY, int sizemod) {
    pos.x += DX;
    pos.y += DY;
    r = (int)(pos.x + pos.y) % 255 ;
    g = (int)(pos.x - pos.y) % 255;
    b = (int)(pos.x + (w * 2)) % 255;
    
    //w = (int)pos.x % int(ofGetWidth()*0.15);
    w = (int)pos.x % (ABS(sizemod) + 1);
    
    if (pos.x > ofGetWidth()) {
        pos.x = 0;
        pos.y += 50;
    }
}

void Mover::draw() {
    ofSetColor(r, g, b);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(w + pos.y);
    ofRect(0, 0, w, w);
    ofPopMatrix();
}

void Mover::setPos(float X, float Y) {
    pos.x = X;
    pos.y = Y;
}
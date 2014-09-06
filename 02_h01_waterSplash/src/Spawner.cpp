//
//  Spawner.cpp
//  HW2
//
//  Created by Bryan Ma on 9/5/14.
//
//

#include "Spawner.h"
#include "ofApp.h"

bool Spawner::update() {
    int frame = ofGetFrameNum();
    
    tail.push_back(center);
    if (tail.size() > 150) {
        tail.erase(tail.begin());
    }
    
    center.x = center.x + sin((float)frame * 0.03) * 5;
    center.y = center.y + cos((float)frame * 0.03);
    
    if (frame % 8 == 0) {
        return true;
    } else {
        return false;
    }
}

void Spawner::draw() {
    ofPushStyle();
    ofSetColor(255);
    ofFill();
    //ofBeginShape();
    for(int i = 0; i < tail.size(); i++) {
        //ofVertex(tail[i]);
        if ( i % 2 == 0 ) {
            ofSetColor(255, i * 0.5);
            ofCircle(tail[i].x, tail[i].y, (i * 0.5));
        }
    }
    //ofEndShape();
    ofPopStyle();
    
    
}
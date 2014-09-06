#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numCols = 160;
    water = new Water*[numCols];
    fish = new Fish*[100];
    for (int i = 0; i < numCols; i++) {
        water[i] = new Water(i*5, 500, 440, 0, 440);
    }
    for (int i = 0; i < 100; i++) {
        fish[i] = new Fish();
        fish[i]->x = ofRandom(ofGetWidth());
        fish[i]->y = 440 + ofRandom(100);
    }
    ofPoint pt;
    pt.x = ofRandom(ofGetWidth());
    pt.y = -30;
    //stone = new Stone(pt);
    cloud.center.x = ofGetWidth() * 0.3;
    cloud.center.y = ofGetHeight() * 0.15;
}

//--------------------------------------------------------------
void ofApp::update(){
    mouse.x = mouseX;// + ofRandom(-(440-mouseY),(440-mouseY));
    mouse.y = mouseY;// + ofRandom(-100,100);
    for (int i = 0; i < 100; i++) {
        ofPoint newVel = fish[i]->update(mouse);
        fish[i]->x += newVel.x;
        if (mouse.y > 440) {
            if (fish[i]->y + newVel.y > 440) {
                fish[i]->y += newVel.y;
            }
        }
    }
    
    if (cloud.update()) {
        ofPoint rainPoint = cloud.center;
        rainPoint.x += ofRandom(-10,10);
        rainPoint.y += ofRandom(40,60);
//        stones.push_back(cloud.center);
        stones.push_back(rainPoint);
    }
    
    for (int i = 0; i < stones.size(); i++) {
        stones[i].run();
        if (stones[i].pos.y > 440) {
            stones.erase(stones.begin()+i);
        }
    }
        
        for (int k = 0; k < numCols; k++) {
            water[k]->update(damp, ten);
            
            if (stones.size()) {  // not sure if this fixes the bug
                for (int i = 0; i < stones.size(); i++) {
                    if (stones[i].pos.y < 440 && stones[i].pos.y + stones[i].vel.y >= 440) {
                        water[int(stones[i].pos.x/5)]->h = stones[i].pos.y + stones[i].vel.y * 2;
                    }
                }
            }
        
            float lDeltas[numCols];
            float rDeltas[numCols];
        
            for (int j = 0; j < 8; j++) {
                for (int l = 0; l < numCols; l++) {
                    if (l > 0) {
                        lDeltas[l] = spread * (water[l]->h - water[l-1]->h);
                        water[l-1]->spd += lDeltas[l];
                    }
                    if (l < numCols-1){
                        rDeltas[l] = spread * (water[l]->h - water[l+1]->h);
                        water[l+1]->spd += rDeltas[l];
                    }
                }
                for (int r = 0; r < numCols; r++) {
                    if ( r > 0 ) {
                        water[r-1]->h += lDeltas[r];
                    }
                    if (r < numCols - 1) {
                        water[r+1]->h += rDeltas[r];
                    }
                }
            }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofNoFill();
    ofSetColor(120,160,190);
    ofBeginShape();
    ofVertex(0,ofGetHeight());
    for (int i = 0; i < numCols; i++) {
        ofVertex(water[i]->x, water[i]->h);
        //water[i]->display();
    }
    ofVertex(ofGetWidth(),water[numCols-1]->h);
    ofVertex(ofGetWidth(),ofGetHeight());
    ofEndShape();
    
    for (int i = 0; i < stones.size(); i++) {
        stones[i].display();
    }
    
    for (int i = 0; i < 100; i++) {
        fish[i]->draw();
    }
    cloud.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mouse.x = mouseX;
    mouse.y = mouseY;
    
    stones.push_back(mouse);
    for (int i = 0; i < 100; i++) {
        fish[i]->vel.x += fish[i]->vel.x * 0.5;
        fish[i]->vel.y += fish[i]->vel.y * 0.5;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouse.x = mouseX;
    mouse.y = mouseY;
    
    stones.push_back(mouse);
    
    for (int i = 0; i < 100; i++) {
        fish[i]->vel.x = ofRandom(-1000,1000);
        fish[i]->vel.y = ofRandom(-1000,1000);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

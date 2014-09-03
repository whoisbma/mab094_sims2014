#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(20, 20, 20);
    slowMover.setPos(25,ofGetHeight()*0.5);
    quickMover.setPos(25,25);
    ofSetBackgroundAuto(false);
    
    for (int i = 0; i < 20; i++) {
        followers[i].pos.x = ofGetWidth() * 0.5;
        followers[i].pos.y = ofGetHeight() * 0.5;
        followers[i].offset = (i+1) * 0.03;
        followers[i].w = 100-i*5;
        followers[i].c = 255-i*10;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetColor(20,20,20,2);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    int mousePosMod = (int)mouseX;
    
    slowMover.update(0.01, 0.0, mousePosMod);
    quickMover.update(2, 0, mousePosMod);

    followers[0].update(mouseX,mouseY);
    for (int i = 1; i < 20; i++) {
        followers[i].update(followers[i-1].pos.x, followers[i-1].pos.y);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    slowMover.draw();
    quickMover.draw();
    for (int i = 0; i < 20; i++) {
        followers[i].draw();
    }
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (pointCounter % 2 == 0) {
        pointA.x = mouseX;
        pointA.y = mouseY;
        pointCounter ++;
        cout << "point A changed to " << pointA << endl;
    } else {
        pointB.x = mouseX;
        pointB.y = mouseY;
        pointCounter ++;
        cout << "point B changed to " << pointB << endl;
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

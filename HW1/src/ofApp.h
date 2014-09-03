#pragma once

#include "ofMain.h"
#include "Mover.h"
#include "Follower.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        Mover slowMover;
        Mover quickMover;
    
        ofPoint pointA;
        ofPoint pointB;
        int pointCounter = 0;
    
        Follower followers[20];
    
    
};

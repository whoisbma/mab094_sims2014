#pragma once

#include "ofMain.h"
#include "Water.h"
#include "Stone.h"
#include "Spawner.h"
#include "Fish.h"

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
    
        ofPoint mouse;
    
        vector<Stone> stones;
    
    private:
        Water** water;
        Fish** fish;
        int numCols = 160;
        float ten = 0.025;
        float damp = 0.015;
        float spread = 0.001;

        //Stone* stone;
    
        Spawner cloud;
};

#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        ofPolyline noiseCircle(int cx, int cy, int r, int num);
        ofPolyline noiseCircleTwo(int cx, int cy, int r, int num);
    
        vector <ofPolyline> lines;
    
        ofParameter<int> diameter;
        ofParameter<float> jitter;
        ofParameter<float> jitter_percent;
    
        ofxPanel gui;
        bool capture;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

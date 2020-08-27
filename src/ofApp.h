#pragma once

#include "ofMain.h"
#include "FractalRoot.h"
#include "Branch.h"
#include "ofxGui.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    FractalRoot pentagon;
    Branch branch;
    ofImage myImage;
    
    // parameter of GUI
    ofxPanel gui;
    ofxColorSlider bgColor, lineColor;
    ofxIntSlider lineWidth;
    ofxIntSlider startAngle;
    ofxFloatSlider strutFactor;
    bool bHide;
    };

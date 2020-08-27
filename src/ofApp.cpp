#include "ofApp.h"
#include "ofxGui.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(6);
    ofEnableSmoothing();
    
    // set GUI
    gui.setup();
    gui.add(bgColor.setup("bgColor", ofColor(153, 214, 189), ofColor(0, 0, 0), ofColor(255, 255, 255))); //背景色
    gui.add(lineColor.setup("lineColor", ofColor(255, 255, 255), ofColor(0, 0, 0), ofColor(255, 255, 255))); //ラインの色
    gui.add(lineWidth.setup("lineWidth", 5, 5, 8)); //ラインの太さ
    gui.add(startAngle.setup("startAngle", 0, -45, 45));
    gui.add(strutFactor.setup("strutFactor", -0.39118606, -1.0, 2.0)); //支柱の長さ
    
    bHide = false;
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(bgColor);
    
    pentagon.setup(startAngle, strutFactor);
    pentagon.drawShape(bgColor, lineColor, lineWidth);
    
    myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    
    if(!bHide){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key)
    {
        case 'h':
        {
            bHide = !bHide;
        }
            break;
            
        case 's':
        {
            myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.png", OF_IMAGE_QUALITY_BEST);
        }
            break;
        default:
            break;
    }

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

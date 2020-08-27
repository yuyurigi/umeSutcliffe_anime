
#include "FractalRoot.h"

FractalRoot::FractalRoot(){
    
}

void FractalRoot::setup(float startAngle, float strutFactor){
    pointArr.clear();
    
    float centX = ofGetWidth()/2;
    float centY = ofGetHeight()/2;
    int count = 0;
    int _numSides = 8; //頂点の数
    float angleStep = 360.0f/_numSides;
     for(int i = 0; i < 360; i+=angleStep){
        float x = centX + (380 * cos(ofDegToRad(startAngle + i)));
        float y = centY + (380 * sin(ofDegToRad(startAngle + i)));
        ofVec2f pp (x, y);
        pointArr.push_back(pp);
        count++;
    }
    rootBranch.setup(0, 0, pointArr, strutFactor);
}

void FractalRoot::drawShape(ofColor bgColor, ofColor lineColor, int lineWidth){
    rootBranch.drawMe(bgColor, lineColor, lineWidth);
}

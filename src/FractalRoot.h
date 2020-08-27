#ifndef FractalRoot_h
#define FractalRoot_h

#include "ofMain.h"
#include "Branch.h"

class FractalRoot {
public:
    FractalRoot();
    void setup(float startAngle, float strutFactor);
    void drawShape(ofColor bgColor, ofColor lineColor, int lineWidth);
    
    vector <ofVec2f> pointArr;
    Branch rootBranch;
};

 

#endif /* FractalRoot_h */


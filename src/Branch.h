#ifndef Branch_h
#define Branch_h

#include "ofMain.h"

class Branch{
public:
    Branch();
    void setFlower();
    void setup(int lev, int n, vector <ofVec2f> points, float _strutFactor);
    void drawMe(ofColor bgColor, ofColor _lineColor, int _lineWidth);
    void drawFlower(float x, float y, int radius);
    
    vector<ofVec2f> calcMidPoints();
    ofVec2f calcMidPoint(ofVec2f end1, ofVec2f end2);
    
    vector <ofVec2f> calcStrutPoints();
    ofVec2f calcProjPoint(ofVec2f mp, ofVec2f op);
    
public:
    int level, num;
    float strutFactor;
    int maxlevels;
    ofColor bgColor, lineColor;
    int lineWidth;
    
    vector <ofVec2f> outerPoints;
    
    vector <ofVec2f> midPoints;
    vector <ofVec2f> midPoints2;
    vector <ofVec2f> projPoints;
    vector <Branch> myBranches;

    //flower parameter
    int flowerKaiten, flowerRadius, circleResolution;
    int hh[5], hh2[5], hh3[5];
    float rr[10], rr2[10];
    ofVec2f umeMaru, tubomi, ume;
    float maruW, maruH, tubomiRadius;
    bool level1;
    ofColor umeColor, osibeColor, osibeColor2;
};


#endif /* Branch_h */

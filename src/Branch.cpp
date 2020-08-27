#include "Branch.h"


Branch::Branch(){
    level = 0;
    num = 0;
    maxlevels = 4;
    
    setFlower();
}

void Branch::setup(int _lev, int _n, vector <ofVec2f> _points, float _strutFactor){
    level = _lev;
    num = _n;
    outerPoints = _points;
    strutFactor = _strutFactor;
    midPoints = calcMidPoints();
    projPoints = calcStrutPoints();
    
    myBranches.clear();
    
    int newLevel = level + 1;
    if ((newLevel) < maxlevels) {
        Branch childBranch;
        childBranch.setup(newLevel, 0, projPoints, strutFactor);
        myBranches.emplace_back(childBranch);
        
        
        for (int k = 0; k < outerPoints.size(); k++) {
            int nextk = k-1;
            if (nextk < 0) {nextk += outerPoints.size();}
            vector <ofVec2f> newPoints = { projPoints[k], midPoints[k], outerPoints[k], midPoints[nextk], projPoints[nextk]};
            childBranch.setup(newLevel, k+1, newPoints, strutFactor);
            myBranches.emplace_back(childBranch);
        }
    }
    
    if (newLevel == 1) {
        level1 = true;
    }
    
             
}


void Branch::drawMe(ofColor _bgColor, ofColor _lineColor, int _lineWidth){
    bgColor = _bgColor;
    lineColor = _lineColor;
    lineWidth = _lineWidth;
    ofSetLineWidth(lineWidth - level);
    for (int i = 0; i < outerPoints.size(); i++){
        int nexti = i+1;
        if (nexti == outerPoints.size()) { nexti = 0; }
        
        ofSetColor(lineColor);
        ofDrawLine(outerPoints[i].x, outerPoints[i].y, outerPoints[nexti].x, outerPoints[nexti].y);
    }
    
    
    for (int j = 0; j < midPoints.size(); j++) {
        ofSetColor(umeColor);
        if (j == 3){
            //ellipse(fill)
            ofFill();
             ofSetColor(umeColor);
            ofDrawEllipse(midPoints[j].x + tubomi.x, midPoints[j].y + tubomi.y, tubomiRadius, tubomiRadius);
            
            //ellipse(stroke)
            ofNoFill();
            ofSetColor(bgColor);
            ofDrawEllipse(midPoints[j].x + tubomi.x, midPoints[j].y + tubomi.y, tubomiRadius, tubomiRadius);

            
        }
    }
    
    for (int k = 0; k < myBranches.size(); k++) {
        myBranches[k].drawMe(bgColor, lineColor, lineWidth);
    }
    
    
    for (int l=0; l < midPoints2.size(); l++) {
        if (level1) {
            setFlower();
        }
        if(l == 4){
            drawFlower(midPoints2[l].x + ume.x, midPoints2[l].y + ume.y, flowerRadius);
        }
        
    }
    
}

vector <ofVec2f> Branch::calcMidPoints(){
    vector <ofVec2f> mpArray;
    mpArray.resize(outerPoints.size());
    for (int i = 0; i<outerPoints.size(); i++) {
        int nexti = i+1;
        if (nexti == outerPoints.size()) {nexti = 0;}
        ofVec2f thisMP = calcMidPoint(outerPoints[i], outerPoints[nexti]);
        mpArray[i] = thisMP;
    }
    return mpArray;
}

ofVec2f Branch::calcMidPoint(ofVec2f end1, ofVec2f end2){
    float mx, my;
    if (end1.x > end2.x) {
        mx = end2.x + ((end1.x - end2.x)/2);
    } else {
        mx = end1.x + ((end2.x - end1 .x)/2);
    }
    if (end1.y > end2.y) {
        my = end2.y + ((end1.y - end2.y)/2);
    } else {
        my = end1.y + ((end2.y - end1.y)/2);
    }
    ofVec2f uuu;
    uuu.set(mx, my);
    midPoints2.push_back(uuu);
    
    return ofVec2f(mx, my);
}


vector <ofVec2f> Branch::calcStrutPoints(){
    vector <ofVec2f> strutArray;
    strutArray.resize(midPoints.size());
    for (int i = 0; i < midPoints.size(); i++) {
        int nexti = i+3;
        if (nexti >= midPoints.size()) {nexti -= midPoints.size();}
        ofVec2f thisSP = calcProjPoint(midPoints[i], outerPoints[nexti]);
        strutArray[i] = thisSP;
    }
    return strutArray;
}

ofVec2f Branch::calcProjPoint(ofVec2f mp, ofVec2f op){
    float px, py;
    float adj, opp;
    if (op.x > mp.x) {
        opp = op.x - mp.x;
    } else {
        opp = mp.x - op.x;
    }
    if (op.y > mp.y) {
        adj = op.y - mp.y;
    } else {
        adj = mp.y - op.y;
    }
    if (op.x > mp.x) {
        px = mp.x + (opp * strutFactor);
    } else {
        px = mp.x - (opp * strutFactor);
    }
    if (op.y > mp.y) {
        py = mp.y + (adj * strutFactor);
    } else {
        py = mp.y - (adj * strutFactor);
    }
    return ofVec2f(px, py);
}

void Branch::setFlower(){
    for (int i = 0; i < 5; i++) {
         hh[i] = ofRandom(4);
         hh2[i] = ofRandom(4);
         hh3[i] = ofRandom(4);
     }
     
     flowerKaiten = ofRandom(360); //花の回転
     flowerRadius = ofRandom(40, 60); //花の大きさ
     umeMaru = ofVec2f(ofRandom(-3, 3), ofRandom(-3, 3)); //梅の真ん中の丸の位置
     tubomiRadius = ofRandom(8, 20); //つぼみの大きさ
     maruW = ofRandom(-3, 3); //花のまんなかのまるい黄色のところの幅
     maruH = ofRandom(-3, 3); //花のまんなかのまるい黄色のところの高さ
     circleResolution = ofRandom(8, 10); //おしべの数
     for (int j = 0; j < circleResolution; j++){
         rr[j] = ofRandom(-4, 4); //おしべの角度
         rr2[j] = ofRandom(-5, 0); //おしべの長さ
     }
    tubomi = ofVec2f(ofRandom(-6, 6), ofRandom(-6, 6)); //つぼみの位置
    ume = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); //梅の位置
     
     int c1 = int(ofRandom(10));
     switch (c1) {
             
         case 0: //pink
             umeColor.set(245, 141, 182);
             osibeColor.set(255);
             osibeColor2.set(255);
             break;
         case 1: //red
             umeColor.set(242, 23, 23);
             osibeColor.set(255);
             osibeColor2.set(255);
             break;
         case 2: //orange
             umeColor.set(243, 165, 47);
             osibeColor.set(255);
             osibeColor2.set(255);
             break;
         case 3: //yellow
             umeColor.set(254, 242, 97);
             osibeColor.set(172, 120, 33);
             osibeColor2.set(172, 120, 33);
             break;
         default: //white
             umeColor.set(255);
             osibeColor.set(172, 120, 33);
             osibeColor2.set(172, 120, 33);
             break;
     }
    
}

void Branch::drawFlower(float x, float y, int radius){
    float R = radius* 0.6;
    float R2 = R * 0.7;
    float R3 = R2 * 0.8;
    float R4 = R* 0.8; //花のまんなかのまるい黄色のところ
    int h = 5; //花びらの枚数
    int a = 2; //花びらの丸み調整
    
        ofPushMatrix();
        
        ofTranslate(x, y);
        ofRotateDeg(flowerKaiten);
    
        //花
        ofSetColor(umeColor);
        ofFill();
        for (int i=0; i<h; i++) {
            ofPushMatrix();
            ofTranslate(R2*cos(ofDegToRad(360*i/h))+hh2[i], R2*sin(ofDegToRad(360*i/h))+hh3[i]);
            ofRotateDeg(360*i/h + 180 + hh[i]);
            ofBeginShape();
            for (float t = 0; t < TWO_PI; t += 0.1) {
                float r = 1/ (a*sin(t/2)+1);
                ofVertex(R * r * cos(t), R * r * sin(t));
            }
            ofEndShape(true);
            ofPopMatrix();
        }
        
    //花の輪郭
        ofSetColor(bgColor);
        ofNoFill();
        ofSetLineWidth(2 + lineWidth - maxlevels);
        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
        
        ofPushMatrix();
        ofBeginShape();
    
    for(int i = 0; i < h; i++){
        for (float t = 0; t < TWO_PI; t += 0.1) {
            float r = 1/ (a*sin(t/2)+1);
            ofVertex(R2*cos(ofDegToRad(360*i/h))+hh2[i] + R * r * cos(t + ofDegToRad(360*i/h + 180 + hh[i])), R2*sin(ofDegToRad(360*i/h))+hh3[i] + R * r * sin(t + ofDegToRad(360*i/h + 180 + hh[i])));
        }
    }
        
        ofEndShape(true);
        ofPopMatrix();
    
    //花のまんなかの丸いところ
        ofFill();
        ofSetColor(226, 209, 77, 150);
        ofDrawEllipse(umeMaru.x, umeMaru.y, R4+maruW, R4+maruH);
        
    //おしべ
        ofFill();
        ofSetLineWidth(3);
        for (int ang = 0; ang < circleResolution; ang ++) {
            float angle = TWO_PI/circleResolution;
            ofSetColor(osibeColor);
            float rad = ofDegToRad(rr[ang]);
            float x2 = (R3 + rr2[ang]) * cos(angle * ang + rad);
            float y2 = (R3 + rr2[ang]) * sin(angle * ang + rad);
            
            float x3 = (R3 + rr2[ang]) * cos(angle * ang + rad);
            float y3 = (R3 + rr2[ang]) * sin(angle * ang + rad);
            ofDrawEllipse(0, 0, 10, 10);
            ofDrawLine(0, 0, x2, y2);
            
            ofSetColor(osibeColor2);
            ofDrawEllipse(x3, y3, 5, 5);
             
        }
    
        
        ofPopMatrix();
}

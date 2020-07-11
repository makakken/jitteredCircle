#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(128);
     
     gui.setup();
     gui.add(diameter.set("Element Diameter",70,1,500));
     gui.add(jitter.set("Jitter",.15,.01,1));
     gui.add(jitter_percent.set("JitterPercent",0.001,0,1));
     
     capture = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(capture) {
        ofBeginSaveScreenAsSVG("screenshot.svg");
    }
    ofEnableAlphaBlending();
    ofBackground(0);
    ofSetColor( ofColor(255));
    for(auto &line : lines) {
        line.draw();
    }
    if(capture) {
        ofEndSaveScreenAsSVG();
        capture = false;
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') { capture = true; }
    if(key == 'c') {
        lines.clear();
    }
    if(key == 'a') {
        lines.push_back(noiseCircleTwo(300, 300, diameter, 24));
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

//--------------------------------------------------------------
ofPolyline ofApp::noiseCircle(int cx, int cy, int r, int num) {
    ofPolyline line;
    float a = TWO_PI / num;
    for (int i = 0; i < num; i++) {
        float rand = ofRandom(-1 * jitter, jitter);
        int x = r * (1-rand) * cos(a*(i+rand));
        int y = r * (1-rand) * sin(a*(i+rand));
        ofVec3f v = ofVec3f(x,y,0);
        // line.addVertex(v);
        line.curveTo(v);
    }
    line.close();
    float s = ofRandom(0,jitter_percent) + 1;
    line.scale(s,s-0.01);
    line.rotateDeg(45, ofVec3f(0,0,1));
    line.translate(ofVec3f(cx,cy,0));
    return line;
}

ofPolyline ofApp::noiseCircleTwo(int cx, int cy, int r, int num) {
    ofPolyline line;
    float a = TWO_PI / num;
    vector<ofVec3f> linePoints;
    for (int i = 0; i < num; i++) {
        float rand = ofRandom(-1 * jitter, jitter);
        int x = r * (1-rand) * cos(a*(i+rand));
        int y = r * (1-rand) * sin(a*(i+rand));
        ofVec3f v = ofVec3f(x,y,0);
        // line.addVertex(v);
        line.curveTo(v);
        linePoints.push_back(v);
    }
    if(num > 4)
    {
        for(int i = 0 ; i < 3; i++)
        {
            
            line.curveTo(linePoints[i]);
        }
    }
    line.close();
    float s = ofRandom(0,jitter_percent) + 1;
    line.scale(s,s-0.01);
    line.rotateDeg(45, ofVec3f(0,0,1));
    line.translate(ofVec3f(cx,cy,0));
    return line;
}

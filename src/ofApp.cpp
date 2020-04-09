#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i = 0; i < 100; i++) {
        birds0.push_back(Bird(birds0, i, ofColor(255,0,0), birds1, birds2));
    }

    for (int i = 0; i < 100; i++) {
        birds1.push_back(Bird(birds1, i, ofColor(255,255,0), birds2, birds3));
    }

    for (int i = 0; i < 100; i++) {
        birds2.push_back(Bird(birds2, i, ofColor(255,0,255), birds0, birds1));
    }

    for (int i = 0; i < 100; i++) {
        birds3.push_back(Bird(birds3, i, ofColor(0,0,255), birds2, birds1));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto& b : birds0) b.update();
    for (auto& b : birds1) b.update();
    for (auto& b : birds2) b.update();
    for (auto& b : birds3) b.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto& b : birds0) b.draw();
    for (auto& b : birds1) b.draw();
    for (auto& b : birds2) b.draw();
    for (auto& b : birds3) b.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

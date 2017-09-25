#include "ofApp.h"

ofApp::ofApp() : model(2, 2, 3, 2.4, 2.5, true, false, 1, 2, 4, 1, 2, 3, 4, 5, 1) {
    this->dbWriter = Writer();
    this->frame = 0;
}

//--------------------------------------------------------------
void ofApp::setup(){
    this->dbWriter.prepare(this->model);
}

//--------------------------------------------------------------
void ofApp::update(){
    frame++;

    this->model.frame = frame;

    if (frame % this->writeFrequency == 0) {
        this->dbWriter.write(this->model);
    }

    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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

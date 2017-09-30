#include "ofApp.h"
#include <cppconn/exception.h>

void handleSQLException(sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

ofApp::ofApp() : model(2, 2, 3, 2.4, 2.5, true, false, 1, 2, 4, 1, 2, 3, 4, 5, 1) {
    frame = 0;
}

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

    model.frame = frame;

    std::stringstream stream;

    stream << frame << " ";

    try {
        if (frame % saveFrequency == 0) {
            dbWriter.add(model);
        }
        if (frame % writeFrequency == 0) {
            dbWriter.clear();
            dbWriter.write();
        }
    } catch(sql::SQLException &e) {
        handleSQLException(e);
    }

    frame++;

    stream << std::endl;
    cout << stream.str();

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

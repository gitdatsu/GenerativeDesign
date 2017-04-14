#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	agentColor = ofFloatColor(0.0,1.0);
	bgColor = ofFloatColor(1.0);

	ofBackground(bgColor);
	ofSetFrameRate(30);

	ofSetBackgroundAuto(false);
	pos = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

	mode = 0;
	radius = 1.0;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	float mouseY = ofGetMouseY();
	float height = ofGetHeight();
	agentColor = ofFloatColor(mouseY / height, 0.1);
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < ofGetMouseX(); i++) {
		int horizontal = (int)ofRandom(3) - 1;
		int vertical = (int)ofRandom(3) - 1;
		ofVec2f vec = ofVec2f(horizontal, vertical);

		if (mode == 1) {
			radius = (int)ofRandom(5);
			vec *= radius;
		}
		pos += vec;

		if (pos.x > ofGetWidth()) pos.x = 0;
		else if (pos.x < 0) pos.x = ofGetWidth();
		else if (pos.y > ofGetHeight())pos.y = 0;
		else if (pos.y < 0)pos.y = ofGetHeight();

		ofSetColor(agentColor);
		ofDrawCircle(pos, radius);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if ('0' <= key&&key <= '9') mode = key - '0';
	if (mode < 0) mode = 0;

	if (key == 'c') {
		ofBackground(bgColor);
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

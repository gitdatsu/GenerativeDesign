#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSetWindowShape(800,600);
	ofBackground(0);

	ofSetRectMode(OF_RECTMODE_CENTER);

	num_x = 10;
	num_y = 10;


}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	float width = ofGetWidth()*0.8;
	float height = ofGetHeight()*0.8;
	float gridW = width / num_x;
	float gridH = height / num_y;
	float paddingW = ofGetWidth()*0.1 + gridW / 2.0;
	float paddingH = ofGetHeight()*0.1 + gridH / 2.0;

	for (int x = 0; x < num_x; ++x) {
		for (int y = 0; y < num_y; ++y) {
			ofPushMatrix();

			ofVec2f pos = ofVec2f(paddingW + x*gridW, paddingH + y*gridH);
			ofVec2f vec = ofVec2f(ofGetMouseX(), ofGetMouseY()) - pos;
			ofVec2f base = ofVec2f(1, 0);

			ofVec2f vectomouse = ofVec2f(ofGetMouseX(), ofGetMouseY()) - pos;
			float lengthmouse = ofMap(vectomouse.length(), 0, sqrt(ofGetWidth()*ofGetWidth() + ofGetHeight()*ofGetHeight()),1.0,0.0);

			ofTranslate(pos);
			ofRotate(base.angle(vec));
			ofSetColor(0, 160, 255);
			ofRect(0, 0, gridW*lengthmouse, gridH*lengthmouse);

			ofPopMatrix();
		}
	}

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

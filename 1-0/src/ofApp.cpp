#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(720, 720);
	ofHideCursor();
	ofSetRectMode(OF_RECTMODE_CENTER);

	w = ofGetWidth();
	h = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//background
	ofFloatColor bg;
	bg.setHsb(ofGetMouseY() / h, 1.0, 1.0);
	ofBackground(bg);

	//rect
	ofFloatColor c;
	float hue = 0.5 + ofGetMouseY() / h;
	if (hue > 1.0) hue -= 1.0;
	c.setHsb(hue, 1.0, 1.0);
	ofSetColor(c);
	int mousex = ofGetMouseX();
	ofRect(w / 2, h / 2, mousex, mousex);

	//info
	string info;
	info = "mouseX:" + ofToString(ofGetMouseX()) + ", mouseY:" + ofToString(ofGetMouseY());
	ofSetColor(255);
	ofDrawBitmapString(info, 30, 30);

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

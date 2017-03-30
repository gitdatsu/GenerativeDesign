#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800, 600);
	ofBackground(0);

	ofNoFill();
	
	numW = 20;
	numH = 20;

	windowW = 600;
	windowH = 400;


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float paddingW = (ofGetWidth() - windowW) / 2.0;
	float paddingH = (ofGetHeight() - windowH) / 2.0;

	ofTranslate(paddingW + windowW / numW / 2.0, paddingH + windowH / numH / 2.0);;

	for (int gridX = 0; gridX < windowW; gridX += windowW / numW) {
		for (int gridY = 0; gridY < windowH; gridY += windowH / numH) {

			float shiftX = ofRandom(0, mouseX)*(windowW / numW) / ofGetWidth();
			float shiftY = ofRandom(0, mouseX)*(windowW / numW) / ofGetWidth();

			int posX = gridX + shiftX;
			int posY = gridY + shiftY;

			ofFloatColor color = ofFloatColor(0.0, 0.4, 0.8, 0.8);
			ofSetColor(color);

			float length = min(windowW / numW, windowH / numH);
			ofCircle(posX, posY, mouseY*length / ofGetHeight() / 2.0);

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

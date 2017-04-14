#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(60);
	ofNoFill();

	tileWidth = 100;
	tileHeight = 100;
	tileCountX = 10;
	tileCountY = 10;

	tileNum = tileCountX*tileCountY;
	delete[] toggle;
	toggle = new int[tileNum];

	changeToggle();

	moduleNum = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	drawModule(moduleNum);
}

void ofApp::changeToggle() {
	for (int i = 0; i < tileNum; i++) {
		toggle[i] = (int)ofRandom(4);
	}
}

void ofApp::drawModule(int num)
{
	switch (num) {
	case 0: {
		int circleCount = ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 10);
		if (circleCount == 1) changeToggle();

		float endSize = ofMap(ofGetMouseX(), 0, ofGetWidth(), tileCountX / 2.0, 0);
		float endOffset = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, (tileWidth - endSize) / 2.0);
		if (endOffset < (tileWidth - endSize) / 2.0 / 20.0) changeToggle();

		for (int gridY = 0; gridY <= tileCountY; gridY++) {
			for (int gridX = 0; gridX <= tileCountX; gridX++) {
				ofPushMatrix();

				ofTranslate(tileWidth*gridX, tileHeight*gridY);
				ofScale(1, tileHeight / tileWidth);
				ofRotate(toggle[gridY*tileCountX + gridX] * 90);
				for (int i = 0; i < circleCount; i++) {
					float diameter = ofMap(i, 0, circleCount - 1, tileWidth, endSize);
					float offset = ofMap(i, 0, circleCount - 1, 0, endOffset);
					ofEllipse(offset, 0, diameter, diameter);
				}

				ofPopMatrix();
			}
		}
		break;
	}
	case 1: {

		for (int gridY = 0; gridY <= tileCountY; gridY++) {
			for (int gridX = 0; gridX <= tileCountX; gridX++) {
				ofPushMatrix();

				ofTranslate(tileWidth*gridX, tileHeight*gridY);
				ofScale(1, tileHeight / tileWidth);

				float mouseX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, tileWidth);
				float mouseY = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, tileHeight);

				int lineNum = 5;
				float wX = tileWidth / lineNum;
				float wY = tileHeight / lineNum;

				for (int numY = 0; numY <= lineNum; numY++) {

					int gradient;
					if (numY == 0 || numY == lineNum) gradient = 1;
					else gradient = lineNum;

					for (int numX = 0; numX <= lineNum; numX += gradient) {
						ofDrawLine(ofVec2f(wX*numX, wY*numY), ofVec2f(mouseX, mouseY));
					}

				}
				
				ofPopMatrix();
			}
		}

		break;
	}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	moduleNum = key - '0';
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

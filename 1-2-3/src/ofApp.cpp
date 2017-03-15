#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	colorChange('1');

	rand = ofRandom(-10,10);
}

//--------------------------------------------------------------
void ofApp::update(){
	currentTileCountX = (int)ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, tileCountX);
	currentTileCountY = (int)ofMap(ofGetMouseY(), 0, ofGetHeight(), 1, tileCountY);
	tileWidth = ofGetWidth() / currentTileCountX;
	tileHeight = ofGetHeight() / currentTileCountY;


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofColor color;
	for (int x = 0; x < currentTileCountX; ++x) {
		for (int y = 0; y < currentTileCountY; ++y) {
			int index = (x + y*rand);
			while (index < 0)index = currentTileCountX + index;
			index %= tileCountX;
			color.setHsb(hueValues[index], saturationValues[index], brightnessValues[index]);
			ofSetColor(color);
			ofRect(x*tileWidth, y*tileHeight, tileWidth, tileHeight);
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	colorChange(key);
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

void ofApp::colorChange(int key) {
	switch (key) {
	case '1'://all random
		for (int i = 0; i < tileCountX; ++i) {
			hueValues[i] = ofRandom(255);
			saturationValues[i] = ofRandom(255);
			brightnessValues[i] = ofRandom(255);
		}
		rand = ofRandom(-10,10);
		break;
	case '2'://brightness is all 100% 
		for (int i = 0; i < tileCountX; ++i) {
			hueValues[i] = ofRandom(255);
			saturationValues[i] = ofRandom(255);
			brightnessValues[i] = 255;
		}
		rand = ofRandom(-10,10);
		break;
	case '3'://saturation is all 100% 
		for (int i = 0; i < tileCountX; ++i) {
			hueValues[i] = ofRandom(255);
			saturationValues[i] = 255;
			brightnessValues[i] = ofRandom(255);
		}
		rand = ofRandom(-10,10);
		break;
	case '4'://hue is all 0~127
		for (int i = 0; i < tileCountX; ++i) {
			hueValues[i] = ofRandom(255/2);
			saturationValues[i] = ofRandom(255);
			brightnessValues[i] = ofRandom(255);
		}
		rand = ofRandom(-10,10);
		break;
	case '5'://saturation and brightness is all 100%
		for (int i = 0; i < tileCountX; ++i) {
			hueValues[i] = ofRandom(255);
			saturationValues[i] = 255;
				brightnessValues[i] = 255;
		}
		rand = ofRandom(-10, 10);
		break;
	}
}
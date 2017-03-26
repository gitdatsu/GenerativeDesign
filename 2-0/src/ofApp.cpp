#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800, 800);
	ofBackground(0);

	//ofSetBackgroundAuto(false);

	mesh.setMode(OF_PRIMITIVE_LINES);

	fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGB32F);

}

//--------------------------------------------------------------
void ofApp::update(){
	radius = abs(ofGetMouseX() - ofGetWidth() / 2);
	resolution = ofMap(ofGetMouseY(), 0, ofGetHeight(), 3, 8);
	rotate = 2 * PI / resolution;
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		img.grabScreen(0, 0, 800, 800);
		img.saveImage("img_" + ofToString(ofGetYear()) + ofToString(ofGetMonth()) + ofToString(ofGetDay()) + ofToString(ofGetHours()) + ofToString(ofGetMinutes()) + ".png");
	}
	if (key == 127) {//delete
		mesh.clear();
		ofBackground(0);
		img.draw(0,0);
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
	fbo.begin();

	mesh.clear();
	for (int i = 0; i < resolution; ++i) {
		float x = cos(rotate*i - PI / 2)*radius + ofGetWidth() / 2;
		float y = sin(rotate*i - PI / 2)*radius + ofGetHeight() / 2;

		mesh.addVertex(ofVec2f(x, y));
		mesh.addColor(ofColor(0, 255, 255, 100));

		mesh.addIndex(i);
		if (i + 1 < resolution) mesh.addIndex(i + 1);
		else mesh.addIndex(0);
	}
	mesh.draw();

	fbo.end();
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(WIDTH, HEIGHT);
	ofBackground(0);

	gui.setup();
	gui.add(mode.setup("mode", 0, 0, 1));
	gui.add(resolution.setup("resolution", 12, 3, 64));
	gui.add(radius.setup("radius", 200.0, 10.0, WIDTH));
}

//--------------------------------------------------------------
void ofApp::update(){
	mesh.clear();
	mesh.clearColors();

	float radian = 2.0*PI / resolution;

	switch (mode) {
	case 0://triangles
		mesh.setMode(OF_PRIMITIVE_TRIANGLES);

		for (int i = 0; i < resolution; i++) {
			mesh.addVertex(ofVec3f(WIDTH / 2.0, HEIGHT / 2.0, 0.0));
			mesh.addVertex(ofVec3f(radius*cos(i*radian) + WIDTH / 2.0, radius*sin(i*radian) + HEIGHT / 2.0, 0.0));
			mesh.addVertex(ofVec3f(radius*cos((i + 1)*radian) + WIDTH / 2.0, radius*sin((i + 1)*radian) + HEIGHT / 2.0, 0.0));
			ofFloatColor c;
			c.setHsb(ofMap(radian*i, 0.0, 2.0*PI, 0.0, 1.0), 1.0, 1.0);
			for (int j = 0; j < 3; j++) {
				mesh.addColor(c);
			}
		}
		break;

	case 1://triangle fan
		mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);

		mesh.addVertex(ofVec3f(WIDTH / 2.0, HEIGHT / 2.0, 0.0));
		mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
		for (int i = 0; i < resolution; i++) {
			mesh.addVertex(ofVec3f(radius*cos(radian*i) + WIDTH / 2, radius*sin(radian*i) + HEIGHT / 2, 0.0));
			ofFloatColor c;
			c.setHsb(ofMap(radian*i, 0.0, 2.0*PI, 0.0, 1.0), 1.0, 1.0);
			mesh.addColor(c);
		}
		mesh.addVertex(ofVec3f(radius + WIDTH / 2.0, HEIGHT / 2.0, 0.0));
		ofFloatColor c;
		c.setHsb(0.0, 1.0, 1.0);
		mesh.addColor(c);

		break;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);
	mesh.draw();

	img.grabScreen(0,0,ofGetWidth(),ofGetHeight());

	ofBackground(0);
	img.draw(0, 0);

	ofColor color = img.getColor(ofGetMouseX(),ofGetMouseY());// [index];
	ofSetColor(color);
	ofDrawRectangle(0, ofGetHeight()-50, 50, 50);
	
	string strColor = "r:" + ofToString((int)color.r) + ",g:" + ofToString((int)color.g) + ",b:" + ofToString((int)color.b);
	ofSetColor(255);
	ofDrawBitmapString(strColor, 60, ofGetHeight() - 10);

	gui.draw();
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

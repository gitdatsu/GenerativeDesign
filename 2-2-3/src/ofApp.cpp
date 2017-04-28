#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800,800);
	//ofToggleFullscreen();
	ofBackground(0);

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F_ARB);
	fboTemp.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F_ARB);

	init_r = ofGetWidth() / 4;
	init_rad = 2*PI / RESOLUTION;
	for (int i = 0; i < RESOLUTION; i++) {
		float x = init_r*cos(i*init_rad);
		float y = init_r*sin(i*init_rad);
		pos[i] = ofVec2f(x,y);
		base[i] = ofVec2f(x, y);

		xNoise[i] = ofRandom(10);
		yNoise[i] = ofRandom(10);
	}
	step = 4.0;

	rotate = ofVec2f(3, 0);
	rotate.rotate(ofRandom(360));
	rotateNoise = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < RESOLUTION; i++) {
		pos[i].x += step * (ofNoise(xNoise[i]) - 0.5);//+base[i].x;
		pos[i].y += step * (ofNoise(yNoise[i]) - 0.5);// *200 + base[i].y;
		xNoise[i] += 0.002;
		yNoise[i] += 0.002;
	}
	rotate.rotate(2*(ofNoise(rotateNoise) - 0.5));
	rotateNoise += 0.005;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofBackground(0);
	fbo.begin();
	ofClear(0, 0);
	fboTemp.draw(rotate);//,fbo.getWidth()*0.9,fbo.getHeight()*0.9);
	ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
	ofScale(1, -1);
	ofFill();
	ofBeginShape();
	ofSetColor(0,50,200,170);
	ofCurveVertex(pos[RESOLUTION-1].x, pos[RESOLUTION - 1].y);
	for (int i = 0; i < RESOLUTION; i++) {
		ofCurveVertex(pos[i].x, pos[i].y);
		//ofDrawEllipse(pos[i], 10, 10);
	}
	ofCurveVertex(pos[0].x, pos[0].y);
	ofCurveVertex(pos[1].x, pos[1].y);
	ofNoFill();
	ofEndShape();
	fbo.end();

	fboTemp.begin();
	fbo.draw(0, 0);
	fboTemp.end();

	fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::setCircle()
{
	for (int i = 0; i < RESOLUTION; i++) {
		float x = init_r*cos(i*init_rad);
		float y = init_r*sin(i*init_rad);
		pos[i] = ofVec2f(x, y);
		base[i] = ofVec2f(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') setCircle();
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

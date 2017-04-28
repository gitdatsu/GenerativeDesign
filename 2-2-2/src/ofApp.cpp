#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(600, 600);
	ofBackground(0);

	fbo.allocate(ofGetWidth(), ofGetHeight(),GL_RGB32F_ARB);

	ofEnableAntiAliasing();
	ofEnableSmoothing();
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	pos = ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
	ppos = ofVec2f(pos);

	vec = ofVec2f(1, 0);
	vec.rotate(ofRandom(360));

	lineLength = 0.0;
	maxLength = sqrt(ofGetWidth()*ofGetWidth() + ofGetHeight()*ofGetHeight());
	lineWidth = 1;
	lineColor.set(255,0,0);

	drawing = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	//pos update
	pos += vec;
	x = (int)pos.x;
	y = (int)pos.y;

	//rotate Agent
	inWindow = true;
	if (pos.x < 0) {
		inWindow = false;
		rotateAgent(ofVec2f(1, 0)); inWindow = false;
	}
	else if (pos.x > ofGetWidth()) {
		inWindow = false;
		rotateAgent(ofVec2f(-1, 0));
	}
	else if (pos.y < 0) {
		inWindow = false;
		rotateAgent(ofVec2f(0, 1));
	}
	else if (pos.y > ofGetHeight()) {
		inWindow = false;
		rotateAgent(ofVec2f(0, -1));
	}

	int index = x + y*ofGetWidth();
	if (0<=index && index < pix.size()) {
		if (inWindow) {
			if (pix.getColor(x, y) != ofGetBackgroundColor()) {//== lineColor
				rotateAgent(vec);
			}
		}
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (drawing) {
		//fbo
		fbo.begin();
			ofSetLineWidth(lineWidth);
			ofSetColor(lineColor);
			if(lineWidth>=2.0) ofDrawLine(ppos, pos);
		fbo.end();
		fbo.readToPixels(pix);

		//ppos update
		ppos.set(pos);

		drawing = false;
	}

	fbo.draw(0, 0);
}

void ofApp::rotateAgent(ofVec2f base)
{
	if (inWindow) {
		int index = x + y*ofGetWidth();
		if (0 <= index && index < pix.size()) {			
			ofColor c = pix.getColor(x, y);
			while (c == pix.getColor(x, y)) {
				pos += vec;
				x = (int)pos.x;
				y = (int)pos.y;
				index = x + y*ofGetWidth();
				if (0 <= index && index < pix.size()) break;
			}			
		}
	}

	//vec update
	int rand;
	do {
		rand = (int)ofRandom(7) - 3;
	} while (rand == 0);
	vec = base.rotate(rand * 10);
	pos += vec;
	x = (int)pos.x;
	y = (int)pos.y;

	//line setting
	lineLength = pos.distance(ppos);
	lineWidth = ofMap(lineLength, 0.0, maxLength, 1.0, 20.0);
	lineColor.setSaturation(255);
	lineColor.setHue(ofRandom(255));

	drawing = true;
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

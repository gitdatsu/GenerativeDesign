#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(WIDTH, HEIGHT);

	ofxGuiSetDefaultWidth(300);
	ofxGuiSetDefaultHeight(18);

	gui.setup();
	gui.add(step.setup("step", 32, 1, WIDTH / 2));
	gui.add(brightness.setup("brightness", 1.0, 0.0, 1.0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//rect grid
	for (int i = 0; i < WIDTH; i += step) {
		for (int j = 0; j < HEIGHT; j += step) {
			ofFloatColor color;
			color.setHsb(ofMap(i, 0.0, WIDTH, 0.0, 1.0), ofMap(j, 0.0, HEIGHT, 1.0, 0.0), brightness);
			ofSetColor(color);
			ofRect(i, j, step, step);
		}
	}
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

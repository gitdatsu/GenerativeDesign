#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetVerticalSync(true);

	ofxGuiSetDefaultWidth(300);
	ofxGuiSetDefaultHeight(18);

	gui.setup();
	gui.add(step.setup("step", 32, 1, WIDTH / 2));
	gui.add(brightness.setup("brightness", 1.0, 0.0, 1.0));

	}

//--------------------------------------------------------------
void ofApp::update(){
	fbo.clear();
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
	ofSetColor(255);
	fbo.begin();
	//rect grid

	for (int i = 0; i < WIDTH; i += step) {
		for (int j = 0; j < HEIGHT; j += step) {
			float hue = ofMap(i, 0.0, WIDTH, 0.0, 1.0);
			float saturation = ofMap(j, 0.0, HEIGHT, 1.0, 0.0);

			ofFloatColor color;
			color.setHsb(hue, saturation, brightness);
			ofSetColor(color);
			ofDrawRectangle(i, j, step, step);
		}
	}
	ofSetColor(brightness);
	fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.draw(0, 0);


	ofPixels pix;
	fbo.readToPixels(pix);
	float w = ofGetWidth(); float h = ofGetHeight();

	float mouseX = ofGetMouseX(); float mouseY = ofGetMouseY();
	string str = "mouseX:" + ofToString(mouseX) + ", mouseY:" + ofToString(mouseY) + ", w*h:" + ofToString(w*h) + ",pix_size:" + ofToString(pix.size());
	ofSetColor(0);
	ofDrawBitmapString(str, 10, h -10);

	int index = (mouseY*w + mouseX)*3;
	if (index < 0 || pix.size()-1<index) return;
	ofColor color = pix.getColor(index);
	ofSetColor(color);
	ofDrawRectangle(w-70,20,50,50);
	
	
	
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

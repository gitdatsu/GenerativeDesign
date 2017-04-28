#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(800, 400);
	ofSetFrameRate(60);
	ofBackground(0);
	ofEnableAlphaBlending();

	//color width for gui
	ofFloatColor initColor = ofFloatColor(0.5, 0.5, 0.5);
	ofFloatColor minColor = ofFloatColor(0.0, 0.0, 0.0);
	ofFloatColor maxColor = ofFloatColor(1.0, 1.0, 1.0);

	//gui setting
	gui.setup();
	gui.add(color1.setup("colorLeft",initColor,minColor,maxColor));
	gui.add(color2.setup("colorRight", initColor, minColor, maxColor));
	gui.add(resolution.setup("resolution", 8, 2, 64));

	guishow = true;
}

//--------------------------------------------------------------
void ofApp::update(){

	colorRGB.clear();
	colorHSB.clear();

	for (int i = 0; i < resolution; i++) {
		ofFloatColor rgb,hsb;
		ofFloatColor c1 = color1;
		ofFloatColor c2 = color2;

		rgb.r = c1.r + i*((c2.r - c1.r) / (resolution - 1));
		rgb.g = c1.g + i*((c2.g - c1.g) / (resolution - 1));
		rgb.b = c1.b + i*((c2.b - c1.b) / (resolution - 1));

		float hue = c1.getHue() + i*((c2.getHue() - c1.getHue()) / (resolution - 1));
		float saturation = c1.getSaturation() + i*((c2.getSaturation() - c1.getSaturation()) / (resolution - 1));
		float brightness = c1.getBrightness() + i*((c2.getBrightness() - c1.getBrightness()) / (resolution - 1));
		hsb.setHsb(hue, saturation, brightness, 1.0);

		colorRGB.emplace_back(rgb);
		colorHSB.emplace_back(hsb);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	float w = 600 / resolution;
	for (int i = 0; i < resolution; i++) {
		ofFloatColor c = colorRGB[i];
		ofSetColor(c);
		ofRect(100 + w*i, 100, w, 100);
		c = colorHSB[i];
		ofSetColor(c);
		ofRect(100 + w*i, 200, w, 100);
	}

	if(guishow) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') guishow = !guishow;
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

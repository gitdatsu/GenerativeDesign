#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableSmoothing();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	img.loadImage("image.JPG");
	imgW = img.getWidth();
	imgH = img.getHeight();
	windowW = ofGetWidth();
	windowH = ofGetHeight();

	resolution = 64;
	colors_length = windowW / resolution * windowH / resolution;
	colors = new ofColor[colors_length]();
	nums = new int[colors_length]();

	mode = -1;
	imgDrawing = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	int count = 0;
	if (imgDrawing) {
		img.draw(0, 0, windowW, windowH);

		img.grabScreen(0, 0, windowW, windowH);
		ofPixels pixels = img.getPixels();

		for (int i = 0; i < windowW; i += resolution) {
			for (int j = 0; j < windowH; j += resolution) {
				img.getColor(i, j);
				ofColor color = pixels.getColor(i, j);
				colors[count] = color;
				count++;
			}
		}

		for (int i = 0; i < colors_length; i++) {
			nums[i] = i + 1;
		}
	}

	sortColor(mode);

	count = 0;
	for (int i = 0; i < windowW; i += resolution) {
		for (int j = 0; j < windowH; j += resolution) {
			ofColor c;
			
			switch (mode) {
			case 0://hue
				c.setHsb(colors[count].getHue(), 255, 255);
				break;
			case 1://saturation
				c.setHsb(colors[count].getHue(), colors[count].getSaturation(), 255);
				break;
			case 2://brightness
				c.setHsb(colors[count].getHue(), 255, colors[count].getBrightness());
				break;
			default:
				c = colors[count];
				break;
			}

			ofSetColor(c);
			ofRect(i, j, resolution, resolution);
			
			ofSetColor(0);
			string str = ofToString(nums[count]);
			ofDrawBitmapString(str,i+resolution/2,j+resolution/2);

			count++;
		}
	}
}

void ofApp::sortColor(int mode) {

	bool finish;
	int count=0;

	switch (mode) {
	case 0://sort by Hue
		for (int i = 0; i < colors_length - 1; i++) {
			finish = true;
			for (int j = 0; j < colors_length - 1 - i; j++) {
				if (colors[j].getHue() > colors[j + 1].getHue()) {
					ofColor c = colors[j];
					colors[j] = colors[j + 1];
					colors[j + 1] = c;

					int n = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = n;

					finish = false;
				}
			}
			if (finish) break;
		}
		break;

	case 1://sort by Saturation
		for (int i = 0; i < colors_length - 1; i++) {
			finish = true;
			for (int j = 0; j < colors_length - 1 - i; j++) {
				if (colors[j].getSaturation() > colors[j + 1].getSaturation()) {
					ofColor c = colors[j];
					colors[j] = colors[j + 1];
					colors[j + 1] = c;

					int n = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = n;

					finish = false;
				}
			}
			if (finish) break;
		}
		break;
	case 2://sort by brightness
		for (int i = 0; i < colors_length - 1; i++) {
			finish = true;
			for (int j = 0; j < colors_length - 1 - i; j++) {
				if (colors[j].getBrightness() > colors[j + 1].getBrightness()) {
					ofColor c = colors[j];
					colors[j] = colors[j + 1];
					colors[j + 1] = c;

					int n = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = n;

					finish = false;
				}
			}
			if (finish) break;
		}
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if ('0' <= key&&key <= '9') mode = key - '0';
	if (key == ' ')imgDrawing = !imgDrawing;
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

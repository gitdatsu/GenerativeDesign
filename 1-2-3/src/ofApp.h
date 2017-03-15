#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void colorChange(int key);

	private:
		static const int tileCountX = 50;
		static const int tileCountY = 10;

		int currentTileCountX;
		int currentTileCountY;
		float tileWidth;
		float tileHeight;

		int hueValues[tileCountX];
		int saturationValues[tileCountX];
		int brightnessValues[tileCountX];

		int rand;
};

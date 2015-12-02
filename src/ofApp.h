#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"

#define HEIGHT 60
#define WIDTH 60
#define NUM_PARTICLES HEIGHT * WIDTH

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofSoundPlayer beat;
    int initialBufferSize;
    
    vector<vector<float> > fftHistory;
    int nBandsToGet;
    
    ofVboMesh myVbo;
    ofVec3f myVerts[NUM_PARTICLES];
    ofFloatColor myColor[NUM_PARTICLES];
    
    ofEasyCam cam;
    
    ofxEasyFft fft;    // ofxEasyFftインスタンス
    vector<float> buffer;
    
    //カメラアングル
    float angle;
    // fade in
    float fade;
};

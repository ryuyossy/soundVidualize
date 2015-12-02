#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowPosition(2881, 0);
    ofSetWindowShape(1920,1080);
    ofToggleFullscreen();
    
    ofBackground(0,0,0);
    
    cam.setDistance(100);
    
    myVbo.setMode(OF_PRIMITIVE_POINTS);
    
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 12.0));
    
    // -- prepare vboz
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            myVbo.addVertex(ofVec3f(i - WIDTH, j - HEIGHT));
        }
    }
    
    fade = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update(); // FFT更新
    myVbo.clear();
    buffer = fft.getBins();
    
    if (fade < 1) {
        fade += 0.001;
    }
    
    // -- update vertex coodinates
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            float x = i - WIDTH/2;
            float y = j - HEIGHT/2;
            //float z = fft.at(j) * 50;
            float z = buffer[i] * 50;
            
            //myVerts[i * WIDTH + j] = ofVec3f(x, y, z);
            myVbo.addVertex(ofVec3f(x, y, z));
            myVbo.addColor(ofFloatColor(0.5 + 0.5*buffer[j], 0.8, 1.0, fade));
            //myColor[i * WIDTH + j].set(0.5 + 0.5*buffer[j], 0.8, 1.0, 0.2+0.8*buffer[j]);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // float型の配列にFFT結果を格納
    angle+=0.4;
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    cam.begin();
    ofRotateX(angle);
    ofRotateZ(-angle);
    ofRotateY(angle/2);
    
    glPointSize(2);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    myVbo.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        angle += 1.4;
        
        ofTranslate(ofGetWindowWidth(), ofGetWindowHeight());
        
        cam.begin();
        ofRotateX(angle*sin(100));
        ofRotateZ(-angle);
        ofRotateY(angle*10+sin(100));
        
        glPointSize(2);
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        myVbo.draw();
        cam.end();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

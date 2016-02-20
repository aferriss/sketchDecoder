#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    w = 360;
    h= w;
    
    ofSetWindowShape(w, h);
    
    string path = "sketchData";
    ofDirectory dir(path);
    dir.listDir();
    
    for(int i =0; i<dir.size(); i++){
        paths.push_back(dir.getPath(i));
    }
    
    index = 0;
    fileIndex = 0;
    
    loadNewDrawing();
    
    ofSetBackgroundAuto(false);
}
//--------------------------------------------------------------
void ofApp::loadNewDrawing(){
    drawing.clear();
    index = 0;
    cout<<paths[fileIndex]<<endl;
    
    vector<string> lines  = ofSplitString(ofBufferFromFile(paths[fileIndex]), "\n");
    
    for(int i = 0; i<lines.size()-1; i++){
        
        vector<string> line = ofSplitString(lines[i], ",");
        
        float x = ofToFloat(line[0]);
        float y = ofToFloat(line[1]);
        float z = ofToFloat(line[2]);
        drawing.push_back(ofVec3f(x,y,z));
    }
    
    fileIndex++;
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(index == 0){
        ofSetColor(255);
        ofDrawRectangle(0, 0, w, h);
    }
    
    float alpha = ofMap(drawing[index].z, 1,10,0,255);
    if(drawing[index].z > 7.5){
        ofSetColor(255, 0, 0, alpha);
    } else if(drawing[index].z <1.5){
        ofSetColor(0,255,0, alpha);
    } else{
        ofSetColor(0, alpha);
    }
    
    ofDrawCircle(drawing[index].x, drawing[index].y,  drawing[index].z );
    
    if(ofGetFrameNum() > 10 && index < drawing.size()){
        index++;
    } else if(index == drawing.size()){
        loadNewDrawing();
    }
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

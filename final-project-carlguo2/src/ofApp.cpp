#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	current_state_ = START;
	score_ = 0;

	// instantiate player image
	player_img_.loadImage("player.png");
	player_.setup(&player_img_);
}

//--------------------------------------------------------------
void ofApp::update(){
	// check current game states
	if (current_state_ == START) {

	} else if (current_state_ == IN_GAME) {

	} else if (current_state_ == END) {

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// check current game states
	if (current_state_ == START) {

	}
	else if (current_state_ == IN_GAME) {

	}
	else if (current_state_ == END) {

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// check for the movement buttons
	if (current_state_ == IN_GAME) {
		if (key == 'W') {
			player_.is_w_pressed_ = true;
		}

		if (key == 'A') {
			player_.is_a_pressed_ = true;
		}
		
		if (key == 'S') {
			player_.is_s_pressed_ = true;
		}
		
		if (key == 'D') {
			player_.is_d_pressed_ = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// check current game states
	if (current_state_ == START) {
		// move state to in game
		current_state_ = IN_GAME;
	}
	else if (current_state_ == IN_GAME) {
		// check if key released for movement buttons
		if (key == 'W') {
			player_.is_w_pressed_ = false;
		}
		
		if (key == 'A') {
			player_.is_a_pressed_ = false;
		}
		
		if (key == 'S') {
			player_.is_s_pressed_ = false;
		}
		
		if (key == 'D') {
			player_.is_d_pressed_ = false;
		}
	}
	else if (current_state_ == END) {

	}
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	current_state_ = IN_GAME;
	score_ = 0;

	// instantiate player image
	player_img_.load("player.png");  //TODO: turn this into a constant
	float width = player_img_.getWidth();
	float height = player_img_.getHeight();
	player_.setup(&player_img_, width, height,
		ofGetWidth() / 2, ofGetHeight() - height, 5);
}

//--------------------------------------------------------------
void ofApp::update(){
	// check current game states
	if (current_state_ == START) {

	} else if (current_state_ == IN_GAME) {
		// update player action
		player_.update();

	} else if (current_state_ == END) {

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// check current game states
	if (current_state_ == START) {

	}
	else if (current_state_ == IN_GAME) {
		player_.draw();
	}
	else if (current_state_ == END) {

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// check for the movement buttons
	// TODO: create constants for these chars
	if (current_state_ == IN_GAME) {
		if (key == 'w') {
			player_.is_w_pressed_ = true;
		}

		if (key == 'a') {
			player_.is_a_pressed_ = true;
		}
		
		if (key == 's') {
			player_.is_s_pressed_ = true;
		}
		
		if (key == 'd') {
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
		// TODO: create constants for these chars
		if (key == 'w') {
			player_.is_w_pressed_ = false;
		}
		
		if (key == 'a') {
			player_.is_a_pressed_ = false;
		}
		
		if (key == 's') {
			player_.is_s_pressed_ = false;
		}
		
		if (key == 'd') {
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

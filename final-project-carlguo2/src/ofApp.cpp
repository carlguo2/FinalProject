#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	current_state_ = IN_GAME;
	score_ = 0;

	// instantiate player image
	player_img_.load("player.png");  //TODO: turn this into a constant
	player_.setup(&player_img_, ofGetWidth() / 2,
		ofGetHeight() - player_img_.getHeight(), 5);

	// instantiate bullet images
	player_bullet_img_.load("player_bullet.png");  // TODO: turn string to constant
	enemy_bullet_img_.load("enemy_bullet.png");

}

void ofApp::update_bullets_vector() {
	// loop through each bullet to manage them all
	for (int i = 0; i < bullets_.size(); i++) {
		// update all the bullets
		bullets_[i].update();
		// check when a bullet goes out of screen
		if (bullets_[i].position_.y - bullets_[i].b_width_ / 2 < 0 ||
			bullets_[i].position_.y - bullets_[i].b_width_ / 2 > ofGetHeight()) {
			// when bullet about to go out screen, erase it from vector
			bullets_.erase(bullets_.begin() + i);
		}
	}

	// check for collision
}

//--------------------------------------------------------------
void ofApp::update(){
	// check current game states
	if (current_state_ == START) {

	} else if (current_state_ == IN_GAME) {
		// update game objects action
		player_.update();
		update_bullets_vector();

	} else if (current_state_ == END) {

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// check current game states
	if (current_state_ == START) {

	}
	else if (current_state_ == IN_GAME) {
		// draw game objects
		player_.draw();
		
		for (int i = 0; i < bullets_.size(); i++) {
			bullets_[i].draw();
		}
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
	if (button == 0) {
		Bullet b;
		b.setup(&player_bullet_img_, true, player_.speed_, player_.position_);
		bullets_.push_back(b);
	}
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

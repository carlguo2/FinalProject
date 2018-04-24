#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	current_state_ = IN_GAME;
	score_ = 0;

	// instantiate player image
	player_img_.load("player.png");  //TODO: turn this into a constant
	player_.setup(&player_img_, ofGetWidth() / 2,
		ofGetHeight() - player_img_.getHeight() / 2, 5);

	// instantiate enemy 
	max_enemy_amplitude_ = 3.0;
	max_enemy_shoot_interval_ = 1.5;
	enemy_img_.load("enemy.png");

	// instantiate bullet images
	player_bullet_img_.load("player_bullet.png");  // TODO: turn string to constant
	enemy_bullet_img_.load("enemy_bullet.png");


	// test to see if enemy can work or not.
	Enemy e;
	e.setup(max_enemy_shoot_interval_, &enemy_img_);
	enemies_.push_back(e);
}

void ofApp::check_hit_enemy() {
	// loop through bullets vector
	for (int b = 0; b < bullets_.size(); b++) {
		// check if bullet is from player
		if (bullets_[b].from_player_) {
			// loop through enemy array
			for (int e = 0; e < enemies_.size(); e++) {
				// check distance of bullet from enemy
				if (ofDist(bullets_[b].position_.x, bullets_[b].position_.y,
					enemies_[e].position_.x, enemies_[e].position_.y)
					< enemies_[e].width_ / 2) {
					// if bullet is close enough to hit the enemy, erase the bullet and enemy
					bullets_.erase(bullets_.begin() + b);
					enemies_.erase(enemies_.begin() + e);
				}
			}
		}
	}
}

void ofApp::check_hit_player() {
	// loop through bullet vector
	for (int b = 0; b < bullets_.size(); b++) {
		// check if bullets are from the enemy
		if (!bullets_[b].from_player_) {
			if (ofDist(bullets_[b].position_.x, bullets_[b].position_.y,
				player_.position_.x, player_.position_.y) < (player_.height_ / 2)) {
				//erase bullet and decrement player life
				bullets_.erase(bullets_.begin() + b);
				player_.lives--;
				// if player life is 0 then switch to end gamestate
				if (player_.lives <= 0) {
					current_state_ = END;
				}
			}
		}
	}
}

void ofApp::update_bullets_vector() {
	// loop through each bullet to manage them all
	for (int i = 0; i < bullets_.size(); i++) {
		// update all the bullets
		bullets_[i].update();
		// check when a bullet goes out of screen   
		// TODO: Get rid of magic numbers
		if (bullets_[i].position_.y - bullets_[i].b_width_ / 8 < 0 ||
			bullets_[i].position_.y - bullets_[i].b_width_ / 8 > ofGetHeight()) {
			// when bullet about to go out screen, erase it from vector
			bullets_.erase(bullets_.begin() + i);
		}
	}

	// check for collision
	check_hit_enemy();
	check_hit_player();
}

//--------------------------------------------------------------
void ofApp::update(){
	// check current game states
	if (current_state_ == START) {

	} else if (current_state_ == IN_GAME) {
		// update game objects action
		player_.update();
		update_bullets_vector();

		// loop through enemy vector to update each enemy
		for (int i = 0; i < enemies_.size(); i++) {
			// have the enemy "move down"
			enemies_[i].update();

			// check if enemy can shoot or not
			if (enemies_[i].time_to_shoot()) {
				Bullet b;
				// create the "enemy" bullet to setup
				// TODO: change magic number
				b.setup(&enemy_bullet_img_, false,
					enemies_[i].speed_ + 3, enemies_[i].position_);
				bullets_.push_back(b);
			}

			// if enemies go offscreen then erase from the vector
			if (enemies_[i].position_.y > ofGetHeight() + 50) {
				enemies_.erase(enemies_.begin() + i);
			}
		}

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
		// draw each bullet in vector
		for (int i = 0; i < bullets_.size(); i++) {
			bullets_[i].draw();
		}
		// draw each enemy in vector
		for (int i = 0; i < enemies_.size(); i++) {
			enemies_[i].draw();
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

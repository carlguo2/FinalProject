#include "ofApp.h"

//--------------------------------------------------------------
// set up all the instance variables 
// like the current state, score, images, enemies, player, bullets
void ofApp::setup(){
	current_state_ = START;
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
}

// method especially made to create bullet fired from enemy
// Enemy parameter needed so bullet originates from enemy's position
void ofApp::create_enemy_bullet(Enemy e) {
	Bullet b;
	// create the "enemy" bullet to setup
	// TODO: change magic number
	b.setup(&enemy_bullet_img_, false, e.speed_ + 3, e.position_);
	bullets_.push_back(b);
}

// method made to create a bullet fired from the player
void ofApp::create_player_bullet() {
	Bullet b;
	b.setup(&player_bullet_img_, true, player_.speed_, player_.position_);
	bullets_.push_back(b);
}

void ofApp::create_new_enemy() {
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
				player_.position_.x, player_.position_.y) < (player_.height_ / 5)) {
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

		// get level controller to update and check when to spawn next enemy
		if (level_controller_.should_spawn_enemy()) {
			create_new_enemy();
		}

		// loop through enemy vector to update each enemy
		for (int i = 0; i < enemies_.size(); i++) {
			// have the enemy "move down"
			enemies_[i].update();

			// check if enemy can shoot or not
			if (enemies_[i].time_to_shoot()) {
				create_enemy_bullet(enemies_[i]);
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
		// draw string for start screen
		string start_message = "S to start game!\n";
		ofDrawBitmapString(start_message,
			ofGetWindowWidth() / 2,
			ofGetWindowHeight() / 2);
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
		// draw end screen
		string restart_message = "Game Over! \nR to start game!\n";
		ofDrawBitmapString(restart_message,
			ofGetWindowWidth() / 2,
			ofGetWindowHeight() / 2);
	}
}

void ofApp::reset() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (current_state_ == START) {
		if (key == 's') {
			// move state to in game
			current_state_ = IN_GAME;
			// set up level controller to begin the game
			level_controller_.setup(ofGetElapsedTimeMillis());
		}
	}
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
	else if (current_state_ == END) {
		if (key == 'r') {
			// move state to in game
			current_state_ = IN_GAME;
			// reset the state of everything
			setup();
			// set up level controller to begin the game
			level_controller_.setup(ofGetElapsedTimeMillis());
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// check current game states
	if (current_state_ == IN_GAME) {
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
		create_player_bullet();
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

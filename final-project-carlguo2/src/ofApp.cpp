#include "ofApp.h"

//--------------------------------------------------------------
// set up all the instance variables 
// like the current state, score, images, enemies, player, bullets
void ofApp::setup(){
	current_state_ = START;
	score_ = 0;

	// set up start screen and load
	game_screen_img_.load("start_screen.png");
	// set up game font
	game_font_.load("Gota_Light.otf", 35);
	// smaller font
	small_game_font_.load("Gota_Light.otf", 28);

	// instantiate player image
	player_img_.load("player.png");  //TODO: turn this into a constant
	player_.setup(&player_img_, ofGetWidth() / 2,
		ofGetHeight() - player_img_.getHeight() / 2, 5);

	// instantiate enemy 
	max_enemy_shoot_interval_ = 1.5;
	enemy_img_.load("enemy.png");

	// instantiate bullet images
	player_bullet_img_.load("player_bullet.png");  // TODO: turn string to constant
	enemy_bullet_img_.load("enemy_bullet.png");

	// instantiate power up image
	life_img.load("extra_life_image.png");

	// set up game audio
	player_bullet_sound.loadSound("player_bullet.wav");
	player_bullet_sound.setVolume(5);

	// set up osc tester
	osc_tester_ = oscCommunicator();
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

// spawns a new enemy when it is necessary 
void ofApp::create_new_enemy() {
	Enemy e;
	e.setup(max_enemy_shoot_interval_, &enemy_img_);
	enemies_.push_back(e);
}

// check for collision between bullet and object.
// if player is "hit" the bullet will be erased from vector 
// and the program will transition to end gamestate.
// if an enemy is deemed "hit" then erase specific enemy and bullet '
// from their respective vectors.
void ofApp::check_hit() {
	// loop through bullet vector
	for (int b = 0; b < bullets_.size(); b++) {
		// check if bullets are from the enemy
		if (!bullets_.at(b).from_player_) {
			if (player_.did_hit_player(bullets_.at(b), player_)) {
				//erase bullet and decrement player life
				bullets_.erase(bullets_.begin() + b);
				player_.lives--;
				// if player life is 0 then switch to end gamestate
				if (player_.lives <= 0) {
					current_state_ = END;
				}
			}
		}
		else {
			// loop through enemy array
			for (int e = enemies_.size() - 1; e >= 0; e--) {
				// check distance of bullet from enemy
				if (b < bullets_.size() &&
					enemies_.at(e).did_hit_enemy(
						bullets_.at(b), enemies_.at(e))) {
					// if bullet is close enough to hit the enemy, erase the bullet and enemy
					bullets_.erase(bullets_.begin() + b);
					enemies_.erase(enemies_.begin() + e);
					// increment score
					score_++;
				}
			}
		}
	}
}

// constantly updating the bullet vector, which keeps track of
// all bullets in the game. Checks when bullet goes offscreen that
// it is erased from the bullet vector.
void ofApp::update_bullets_vector() {
	// loop through each bullet to manage them all
	for (int i = 0; i < bullets_.size(); i++) {
		// update all the bullets
		bullets_.at(i).update();
		// check when a bullet goes out of screen   
		// TODO: Get rid of magic numbers
		if (bullets_.at(i).position_.y - bullets_.at(i).b_width_ / 8 < 0 ||
			bullets_.at(i).position_.y - bullets_.at(i).b_width_ / 8 > ofGetHeight()) {
			// when bullet about to go out screen, erase it from vector
			bullets_.erase(bullets_.begin() + i);
		}
	}

	// check for collision
	check_hit();
}

// consistently updates the amount of extra life bonuses that exist in the game. 
void ofApp::update_power_ups() {
	// loop through each bonus to manage them all
	for (int i = extra_lives_.size() - 1; i >= 0; i--) {
		// update the extra life
		extra_lives_.at(i).update();
		// check when extra life collides with player
		if (ofDist(extra_lives_.at(i).position_.x, extra_lives_.at(i).position_.y,
			player_.position_.x, player_.position_.y) < (player_.height_ / 5)) {
			// increment player life
			extra_lives_.erase(extra_lives_.begin() + i);
			player_.lives++;
		}
		// check when a power up goes off screen
		if (extra_lives_.at(i).position_.y - extra_lives_.at(i).width_ / 2 > ofGetHeight()) {
			// when extra life about to go out screen, erase it from vector
			extra_lives_.erase(extra_lives_.begin() + i);
		}
	}
}

//--------------------------------------------------------------
// constantly check for changes with player or bullet
// or if new enemy should be spawned or not. 
// update function also tracks movement of player and enemy
// if enemy goes offscreen then will erase enemy from enemy vector
void ofApp::update(){
	// check current game states
	if (current_state_ == START) {

	} else if (current_state_ == IN_GAME) {
		// update game objects action
		player_.update();
		update_bullets_vector();
		update_power_ups();

		// get level controller to update and check when to spawn next enemy
		if (level_controller_.should_spawn_enemy()) {
			create_new_enemy();
		}

		// loop through enemy vector to update each enemy
		for (int i = 0; i < enemies_.size(); i++) {
			// have the enemy "move down"
			enemies_.at(i).update();

			// check if enemy can shoot or not
			if (enemies_.at(i).time_to_shoot()) {
				create_enemy_bullet(enemies_.at(i));
			}

			// if enemies go offscreen then erase from the vector
			if (enemies_.at(i).position_.y > ofGetHeight() + 50) {
				enemies_.erase(enemies_.begin() + i);
			}
		}

		// update the osc tester when testing boolean is true
		if (is_testing_) {
			osc_tester_.update();
			player_.is_w_pressed_ = osc_tester_.move_up_;
			player_.is_a_pressed_ = osc_tester_.move_left_;
			player_.is_s_pressed_ = osc_tester_.move_down_;
			player_.is_d_pressed_ = osc_tester_.move_right_;
		}
	} else if (current_state_ == END) {

	}
}

// draw the screen for start game state
void ofApp::draw_game_start() {
	// draw string for start screen
	std::string start_message = "Press 'S' to start game!\n";
	game_font_.drawString(start_message,
		ofGetWindowWidth() / 3,
		ofGetWindowHeight() / 2);
}

// draw the screen for in_game game state
void ofApp::draw_in_game() {
	// draw game objects
	player_.draw();
	// draw each bullet in vector
	for (int i = 0; i < bullets_.size(); i++) {
		bullets_.at(i).draw();
	}
	// draw each enemy in vector
	for (int i = 0; i < enemies_.size(); i++) {
		enemies_.at(i).draw();
	}
	// draw each power up in vector
	for (int i = 0; i < extra_lives_.size(); i++) {
		extra_lives_.at(i).draw();
	}

	// draw game score on top of the screen
	game_font_.drawString(std::to_string(score_), 30, 72);
}

// draw the screen for paused game state
void ofApp::draw_game_paused() {
	string pause_message = "P to Unpause!\n";
	game_font_.drawString(pause_message, ofGetWindowWidth() / 2.5, ofGetWindowHeight() / 2);
}

// draw the screen for end game state
void ofApp::draw_game_end() {
	std::string game_over_message = std::string("Game Over! \n") +
		"Final Score: " + std::to_string(score_);
	game_font_.drawString(game_over_message,
		ofGetWindowWidth() / 3,
		ofGetWindowHeight() / 5);

	std::string restart_message = std::string("Press R to restart \n") +
		"Press C to close";
	small_game_font_.drawString(restart_message,
		ofGetWindowWidth() / 25,
		ofGetWindowHeight() / 15);

	// add score to high_score_ array
	addScoreToHighScore(score_);
	// draw high score
	string high_scores = getHighScoreStr();
	game_font_.drawString(high_scores,
		ofGetWindowWidth() / 3,
		ofGetWindowHeight() / 2.5);
}

//--------------------------------------------------------------
// draws each object using its respective png image stored in the bin folder
// also draws text 
void ofApp::draw(){
	// draw game screen
	game_screen_img_.draw(0, 0);
	// check current game states
	if (current_state_ == START) {
		draw_game_start();
	}
	else if (current_state_ == IN_GAME) {
		draw_in_game();
	}
	else if (current_state_ == PAUSED) {
		draw_game_paused();
	}
	else if (current_state_ == END) {
		draw_game_end();
	}
}

// private method to add a score to high score vector
void ofApp::addScoreToHighScore(int new_score) {
	if (high_score_.size() < 5 && score_flag_) {
		high_score_.push_back(new_score);
		score_flag_ = false;
		// sort the vector in descending order
		std::sort(high_score_.begin(), high_score_.end());
	} // check if score is large enough when theres already 10 high scores
	else if (high_score_.size() == 5 && score_flag_) {
		int index = -1;
		// get index where score is larger than high score
		for (int i = 0; i < high_score_.size(); i++) {
			if (high_score_.at(i) > new_score) {
				break;
			}
			index = i;
		}

		// move each score down from that index
		for (int i = 1; i <= index; i++) {
			high_score_.at(i - 1) = high_score_.at(i);
		}
		// change score at index to new high score
		if (index >= 0) {
			high_score_.at(index) = new_score;
		}
		score_flag_ = false;
	}
}

std::string ofApp::getHighScoreStr() {
	string high_scores = "Your high scores are: \n";
	for (int i = high_score_.size() - 1; i >= 0; i--) {
		// print out scores
		string score = std::to_string((long)high_score_.at(i)) + "\n";
		high_scores += score;
	}

	return high_scores;
}

// resets all values once game is restarted
void ofApp::reset() {
	// resets all objects in the game and scores in game
	player_.reset(ofGetWidth() / 2, ofGetHeight() - player_img_.getHeight() / 2);
	bullets_.clear();
	enemies_.clear();
	score_ = 0;
	score_flag_ = true;
}

//--------------------------------------------------------------
// tracks keys pressed
void ofApp::keyPressed(int key){
	// set key 'p' for pause or unpause, this works only 
	// in the in game gamestate and paused gamestate
	if (key == 'p' && current_state_ != END && current_state_ != START) {
		// Pause or unpause
		current_state_ = (current_state_ == IN_GAME) ? PAUSED : IN_GAME;
	}

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
			// reset the state of everything
			reset();
			// move state to in game
			current_state_ = IN_GAME;
			// set up level controller to begin the game
			level_controller_.setup(ofGetElapsedTimeMillis());
		}
		else if (key == 'c') {
			// exit the app
			OF_EXIT_APP(0);
		}
	}
}

//--------------------------------------------------------------
// tracks keys released
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
void ofApp::mousePressed(int x, int y, int button){
	for (Enemy e : enemies_) {
		// make sure that player can't shoot when at a certain close
		// distance from enemy. This cuts down on a bug that makes
		// the game crash.
		if (button == 0 && !is_mouse_pressed &&
			ofDist(player_.position_.x, player_.position_.y,
				e.position_.x, e.position_.y) > player_.width_) {
			create_player_bullet();
			player_bullet_sound.play();
			is_mouse_pressed = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	is_mouse_pressed = false;
}

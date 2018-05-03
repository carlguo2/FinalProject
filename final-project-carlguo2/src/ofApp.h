#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "ofMain.h"
#include "Bullet.h"  // added game components in
#include "Enemy.h"
#include "LevelController.h"
#include "Player.h"
#include "oscCommunicator.h"

// Enum to represent the current state of the game
enum GameState {
	START = 0,
	IN_GAME,
	PAUSED,
	END
};

class ofApp : public ofBaseApp {
private:
	// start screen
	ofImage game_screen_img_;
	std::string screen_file_name = "start_screen.png";

	// font type
	ofTrueTypeFont game_font_;
	ofTrueTypeFont small_game_font_;
	std::string font_type = "Gota_Light.otf";
	int font_size = 35;
	int smaller_font_size = 28;

	// game audio
	ofSoundPlayer player_bullet_sound;
	std::string sound_file_name = "player_bullet.wav";
	float sound_vol = 5;


	// bool to make sure bullet fired once per mouse click
	bool is_shoot_key_pressed = false;

	// high score vector
	std::vector<int> high_score_;
	// makes sure the high_score_ array doesn't get looped when pushing back
	bool score_flag_ = true;  

	GameState current_state_ = START;
	int score_;

	// player properties in game
	Player player_;
	ofImage player_img_;
	std::string player_img_name = "player.png";
	double player_speed_ = 5;

	// bullet properties in game
	std::vector<Bullet> bullets_;
	ofImage player_bullet_img_;
	std::string player_bullet_img_name_ = "player_bullet.png";
	ofImage enemy_bullet_img_;
	std::string enemy_bullet_img_name_ = "enemy_bullet.png";

	// enemy properties
	std::vector<Enemy> enemies_;
	ofImage enemy_img_;
	float max_enemy_shoot_interval_;
	std::string enemy_image_name_ = "enemy.png";

	// LevelController 
	LevelController level_controller_;

	// private helper function for helper methods
	std::string getHighScoreStr();
	void addScoreToHighScore(int new_score);

	// private tester 
	bool is_testing_ = false;
	oscCommunicator osc_tester_;

	// flag for buttons so only registers for one push
	bool is_shoot_button_pressed_ = false;
	bool is_button_pause_ = false;

	// key maps for the game
	char up_key = 'w';
	char down_key = 's';
	char left_key = 'a';
	char right_key = 'd';
	
	char start_key = 's';
	char restart_key = 'r';
	char close_key = 'c';
	char pause_key = 'p';
public:
	// autogenerated methods from openFrameworks
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	//own methods
	void draw_game_start();
	void draw_in_game();
	void draw_game_paused();
	void draw_game_end();

	void check_hit();

	void create_new_enemy();
	void create_enemy_bullet(Enemy e);
	void create_player_bullet();

	void update_bullets_vector();

	void reset();
};

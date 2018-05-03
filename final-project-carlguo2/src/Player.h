#pragma once

#include "ofMain.h"
#include "Bullet.h"

class Player { 
public:
	// tracks position of the player x and y
	ofPoint position_;

	// set dimensions of the player
	double width_;
	double height_;
	double speed_;

	// check if keyboard buttons pressed or not
	// having these makes sure that the player can press multiple keys
	// since OF keyPressed() only checks the last key pressed
	bool is_left_key_pressed_;
	bool is_right_key_pressed_;
	bool is_down_key_pressed_;
	bool is_up_key_pressed_;

	// get image of objects in the game
	ofImage* player_img_;
	float player_draw_x;
	float player_draw_y;

	ofImage* enemy_bullet_img_;

	void setup(ofImage* _img, float x, float y, double speed);
	void update();
	void draw();
	void calculate_movement();
	bool did_hit_player(Bullet b, Player p); 
	void reset(float x, float y);
};

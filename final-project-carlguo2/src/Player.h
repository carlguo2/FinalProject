#pragma once

#include "ofMain.h"

class Player { //TODO: separate public from private
public:
	// tracks position of the player x and y
	ofPoint position_;

	// set dimensions of the player
	double width_;
	double height_;
	double speed_;

	// count lives of the player
	int lives;

	// check if keyboard buttons pressed or not
	// having these makes sure that the player can press multiple keys
	// since OF keyPressed() only checks the last key pressed
	bool is_a_pressed_;
	bool is_d_pressed_;
	bool is_s_pressed_;
	bool is_w_pressed_;

	// get image of objects in the game
	ofImage* player_img_;
	ofImage* enemy_bullet_img_;

	void setup(ofImage* _img, float x, float y, double speed);
	void update();
	void draw();
	void calculate_movement();
};

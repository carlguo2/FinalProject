#pragma once

#include "ofMain.h"

class Player {
	public:
		// tracks position of the player x and y
		ofPoint position;

		// set dimensions of the player
		double width;
		double height;
		double speed;

		// count lives of the player
		int lives;

		// check if keyboard buttons pressed or not
		// having these makes sure that the player can press multiple keys
		// since OF keyPressed() only checks the last key pressed
		bool is_a_pressed_;
		bool is_d_pressed_;
		bool is_s_pressed_;
		bool is_w_pressed_;

		// get image of the player 
		ofImage* player_img;

		void setup(ofImage* _img);
		void update();
		void draw();
		void shoot();
		void calculate_movement();
		bool check_can_shoot();
};

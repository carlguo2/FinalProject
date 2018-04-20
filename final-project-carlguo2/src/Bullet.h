#pragma once

#include "ofMain.h"

class Bullet {
public:
	// tracks position of the bullet x and y
	ofPoint position_;
	// set dimensions of the bullet
	double b_width_;
	double b_speed_;
	// check if bullet is from player or not
	bool from_player_;
	//image of bullet
	ofImage* b_img_;

	void setup(ofImage* img, bool is_players, double speed, ofPoint pos);
	void update();
	void draw();
};
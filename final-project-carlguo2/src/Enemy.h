#pragma once

#include "ofMain.h"
class Enemy {
public:
	ofPoint position_;
	float speed_;
	float width_;
	ofImage* img_;
	// control enemy shooting by time
	float start_shoot_;
	float shoot_interval_;

	void setup(float max_shoot_interval, ofImage* enemy_img);
	void update();
	void draw();
	bool time_to_shoot();
};
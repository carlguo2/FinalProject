#pragma once

#include "ofMain.h"
#include "Bullet.h"

class Enemy {
public:
	ofPoint position_;
	//enemy start positions
	float enemy_start_x_left_lim_;
	float enemy_start_x_right_lim_;
	float enemy_start_y;

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
	bool did_hit_enemy(Bullet b, Enemy e);
};
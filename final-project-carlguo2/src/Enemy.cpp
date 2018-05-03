#include "Enemy.h"

void Enemy::setup(float max_shoot_interval, ofImage* enemy_img) {
	img_ = enemy_img;
	width_ = img_->getWidth();
	speed_ = ofRandom(2, 4);

	// enemy start positions
	enemy_start_x_left_lim_ = width_ / 2;
	enemy_start_x_right_lim_ = ofGetWidth() - width_ / 2;
	enemy_start_y = -enemy_img->getWidth() / 2;
	// set position
	position_.x = ofRandom(enemy_start_x_left_lim_, enemy_start_x_right_lim_);
	// get the enemy to start behind the screen
	position_.y = enemy_start_y;

	// interval between enemy shots
	float minimum_interval = 0.5;
	shoot_interval_ = ofRandom(minimum_interval, max_shoot_interval);
	// ofElapsedTime gets the current time in seconds since program started
	start_shoot_ = ofGetElapsedTimef();
}

void Enemy::update() {
	// update enemy to move down
	position_.y += speed_;
}

void Enemy::draw() {
	float enemy_draw_x = position_.x - width_ / 2;
	float enemy_draw_y = position_.y - width_ / 2;
	img_->draw(enemy_draw_x, enemy_draw_y);
}

bool Enemy::time_to_shoot() {
	// check if time has elapsed passed the shoot_interval_
	if (ofGetElapsedTimef() - start_shoot_ > shoot_interval_) {
		// update the start_shoot_ to measure time interval again
		start_shoot_ = ofGetElapsedTimef();
		return true;
	}
	return false;
}

bool Enemy::did_hit_enemy(Bullet b, Enemy e) {
	float did_hit_enemy_distance = e.width_ / 2;
	if (ofDist(b.position_.x, b.position_.y, e.position_.x, e.position_.y) <
		did_hit_enemy_distance) {
		return true;
	}

	return false;
}
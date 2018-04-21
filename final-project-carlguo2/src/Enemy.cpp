#include "Enemy.h"

void Enemy::setup(float max_amplitude,
	float max_shoot_interval, ofImage* enemy_img) {
	position_.x = ofRandom(ofGetWidth());
	position_.y = 0;

	img_ = enemy_img;
	width_ = img_->getWidth();
	speed_ = ofRandom(2, 7);

	// amplitude of movement on x plane
	amplitude_ = ofRandom(max_amplitude);
	// interval between enemy shots
	shoot_interval_ = ofRandom(0.5, max_shoot_interval);
	// ofElapsedTime gets the current time in seconds since program started
	start_shoot_ = ofGetElapsedTimef();
}

void Enemy::update() {
	// update enemy to move down
	position_.y += speed_;
	// have enemy move in sine wave motion
	position_.x += amplitude_ * sin(ofGetElapsedTimef());;
}

void Enemy::draw() {
	img_->draw(position_.x - width_ / 2, position_.y - width_ / 2);
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
#include "ExtraLife.h"

void ExtraLife::setup(ofImage* img) {
	// set up image 
	img_ = img;
	width_ = img_->getWidth();

	speed_ = 5;

	// set position
	position_.x = ofRandom(width_ / 2, ofGetWidth() - width_ / 2);
	// get the enemy to start behind the screen
	position_.y = -img->getWidth() / 2; 
}

void ExtraLife::draw() {
	img_->draw(position_.x - width_ / 2, position_.y - width_ / 2);
}

void ExtraLife::update() {
	position_.y += speed_;
}
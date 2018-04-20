#include "Player.h"

void Player::setup(ofImage* img, double wid, double hi,
	float x, float y, double spd) {
	// TODO: check for null edge case
	// set player attributes
	speed_ = spd;

	// load image of the player
	player_img = img;
	width_ = wid;
	height_ = hi;
	position_.x = x;
	position_.y = y;
}

void Player::update() {
	calculate_movement();
}

void Player::draw() {
	player_img->draw(position_.x - width_ / 2, position_.y - height_ / 2);
}

void Player::shoot() {

}

void Player::calculate_movement() {
	// if 'a' key is pressed, move left of screen (subtract by x)
	if (is_a_pressed_ && (position_.x - width_ / 4) > 0) {
		// move to the left by speed
		position_.x -= speed_;
	}
	if (is_d_pressed_ && position_.x < (ofGetWidth() - width_ / 4)) {
		position_.x += speed_;
	}
	if (is_w_pressed_ && (position_.y - height_ / 2) > 0) {
		position_.y -= speed_;
	}
	if (is_s_pressed_ && position_.y < (ofGetHeight() - height_ / 2)) {
		position_.y += speed_;
	}
}

bool Player::check_can_shoot() {
	return true;
}
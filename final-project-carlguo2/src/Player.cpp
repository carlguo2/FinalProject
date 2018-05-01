#include "Player.h"

void Player::setup(ofImage* img, float x, float y, double spd) {
	// TODO: check for null edge case
	// set player attributes
	speed_ = spd;

	// load image of the player
	player_img_ = img;
	width_ = img->getWidth();
	height_ = img->getHeight();
	position_.x = x;
	position_.y = y;
}

void Player::update() {
	calculate_movement();
}

void Player::draw() {
	player_img_->draw(position_.x - width_ / 2, position_.y - height_ / 2);
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

bool Player::did_hit_player(Bullet b, Player p) {
	// can't calculate collision by hitmap without using another library or addon.
	if (ofDist(b.position_.x, b.position_.y,
		p.position_.x, p.position_.y) < (p.width_ / 7.5)) {
		return true;
	}
	return false;
}

void Player::reset(float x, float y) {
	// reset player attributes
	position_.x = x;
	position_.y = y;
	// reset key press booleans back to false
	is_w_pressed_ = false;
	is_a_pressed_ = false;
	is_s_pressed_ = false;
	is_d_pressed_ = false;
}
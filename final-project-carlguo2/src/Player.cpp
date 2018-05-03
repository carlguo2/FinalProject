#include "Player.h"

void Player::setup(ofImage* img, float x, float y, double spd) {
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
	player_draw_x = position_.x - width_ / 2;
	player_draw_y = position_.y - height_ / 2;
	player_img_->draw(player_draw_x, player_draw_y);
}

void Player::calculate_movement() {
	// if 'a' key is pressed, move left of screen (subtract by x)
	float player_left_limit = position_.x - width_ / 4;
	float player_right_limit = ofGetWidth() - width_ / 4;
	float player_up_limit = position_.y - height_ / 2;
	float player_down_limit = ofGetHeight() - height_ / 2;

	if (is_left_key_pressed_ && player_left_limit > 0) {
		// move to the left by speed
		position_.x -= speed_;
	}
	if (is_right_key_pressed_ && position_.x < player_right_limit) {
		position_.x += speed_;
	}
	if (is_up_key_pressed_ && player_up_limit > 0) {
		position_.y -= speed_;
	}
	if (is_down_key_pressed_ && position_.y < player_down_limit) {
		position_.y += speed_;
	}
}

bool Player::did_hit_player(Bullet b, Player p) {
	// can't calculate collision by hitmap without using another library or addon.
	float did_hit_player_distance = p.width_ / 7.5;
	if (ofDist(b.position_.x, b.position_.y,
		p.position_.x, p.position_.y) < did_hit_player_distance) {
		return true;
	}
	return false;
}

void Player::reset(float x, float y) {
	// reset player attributes
	position_.x = x;
	position_.y = y;
	// reset key press booleans back to false
	is_up_key_pressed_ = false;
	is_left_key_pressed_ = false;
	is_down_key_pressed_ = false;
	is_right_key_pressed_ = false;
}
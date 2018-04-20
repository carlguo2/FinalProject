#include "Player.h"

void Player::setup(ofImage* img) {
	player_img = img;
	width = player_img->getWidth();
	height = player_img->getWidth();
	position.x = ofGetWidth() / 2;
	position.y = ofGetHeight() - height;
}

void Player::update() {

}

void Player::draw() {
	player_img->draw(position.x - width / 2, position.y - height / 2);
}

void Player::shoot() {

}

void Player::calculate_movement() {

}

bool Player::check_can_shoot() {
	return true;
}
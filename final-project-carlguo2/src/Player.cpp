#include "Player.h"

void Player::setup(ofImage* img) {
	// set player attributes
	speed = 5;

	// load image of the player
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
	// if 'a' key is pressed, move left of screen (subtract by x)
	if (is_a_pressed_ && (position.x - width/2) > 0) {
		// move to the left by speed
		position.x -= speed;
	}


}

bool Player::check_can_shoot() {
	return true;
}
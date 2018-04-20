#include "Bullet.h"

void Bullet::setup(ofImage* img, bool is_players, double speed, ofPoint pos) {
	from_player_ = is_players;
	b_img_ = img;
	b_width_ = img->getWidth();
	b_speed_ = speed;
	position = pos;
}

void Bullet::update() {
	if (from_player_) {
		// bullet from player will shoot "up"
		position.y -= b_speed_;
	}
	else {
		// shoot "down" if bullet from enemy
		position.y += b_speed_;
	}
}

void Bullet::draw() {
	b_img_->draw(position.x - b_width_ / 2, position.y - b_width_ / 2);
}
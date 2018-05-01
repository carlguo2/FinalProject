#include "Bullet.h"

void Bullet::setup(ofImage* img, bool is_players, double speed, ofPoint pos) {
	from_player_ = is_players;
	b_img_ = img;
	b_width_ = img->getWidth();
	b_speed_ = speed;
	position_ = pos;
}

void Bullet::update() {
	if (from_player_) {
		// bullet from player will shoot "up"
		position_.y -= b_speed_;
	}
	else {
		// shoot "down" if bullet from enemy
		position_.y += b_speed_;
	}
}

void Bullet::draw() {
	b_img_->draw(position_.x - b_width_ / 2, position_.y - b_width_ / 2);
}

// new methods used for collision test
void Bullet::set_x(float new_x) {
	position_.x = new_x;
}

void Bullet::set_y(float new_y) {
	position_.y = new_y;
}
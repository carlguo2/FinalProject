#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "src/ofApp.h"


TEST_CASE("Check if collision works on player") {
	GIVEN("A player and a bullet") {
		// instantiate player image
		ofImage player_img;
		player_img.load("player.png");
		// instantiate bullet images
		ofImage enemy_bullet_img;
		enemy_bullet_img.load("player_bullet.png");
		
		// set up player
		Player pl;
		pl.setup(&player_img, 100, 100, 1);

		// set up bullet
		Bullet b;
		ofPoint b_point;
		b_point.x = 0;
		b_point.y = 0; 
		b.setup(&enemy_bullet_img, false, 1, b_point);

		WHEN("bullet is not close to the player") {
			REQUIRE(pl.did_hit_player(b, pl));
		}

		WHEN("bullet is in player range vertically") {
			b.set_x(100);
			b.set_y(100 - pl.width_ / 7.5);
			REQUIRE(pl.did_hit_player(b, pl));
		}

		WHEN("bullet is in player range horizontally") {
			b.set_x(100 - pl.width_ / 7.5);
			b.set_y(100);
			REQUIRE(pl.did_hit_player(b, pl));
		}
	}
}

TEST_CASE("check if bullet collisions apply to enemy") {
	GIVEN("An enemy and a bullet") {
		// instantiate images, this doesn't matter just fill the parameter
		ofImage enemy_img;
		enemy_img.load("player.png");
		ofImage player_bullet_img;
		player_bullet_img.load("player_bullet.png");

		// set up player
		Enemy e;
		e.setup(1, &enemy_img);

		// set up bullet
		Bullet b;
		ofPoint b_point;
		b_point.x = 50;
		b_point.y = 50;
		b.setup(&player_bullet_img, true, 1, b_point);

		WHEN("bullet is not close to the player") {
			REQUIRE(e.did_hit_enemy(b, e));
		}

		WHEN("bullet is in player range vertically") {
			b.set_x(e.position_.x);
			b.set_y(e.position_.y - e.width_ / 2);
			REQUIRE(e.did_hit_enemy(b, e));
		}

		WHEN("bullet is in player range horizontally") {
			b.set_x(e.position_.x - e.width_ / 2);
			b.set_y(e.position_.y);
			REQUIRE(e.did_hit_enemy(b, e));
		}
	}
}
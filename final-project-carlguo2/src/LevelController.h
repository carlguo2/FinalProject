#pragma once

#include "ofMain.h"
class LevelController {
public:
	float start_time_;
	float spawn_enemy_time_interval_;

	void setup(float strt_time);
	bool should_spawn_enemy();
};
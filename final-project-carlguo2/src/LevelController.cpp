#include "LevelController.h"

void LevelController::setup(float strt_time) {
	start_time_ = strt_time;
	spawn_enemy_time_interval_ = 1000;//500; // enemy spawns every .5 seconds
}

bool LevelController::should_spawn_enemy() {
	// check if the time interval has passed for a new enemy to spawn
	if (ofGetElapsedTimeMillis() - start_time_ > spawn_enemy_time_interval_) {
		// reset start time to the current time in order to continue
		// to test when to spawn next enemy for each time interval
		start_time_ = ofGetElapsedTimeMillis();
		return true;
	}
	return false;
}
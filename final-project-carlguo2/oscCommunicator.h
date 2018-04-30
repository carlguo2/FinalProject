#pragma once

#include <iostream>
#include "ofxOsc.h"

class oscCommunicator {
public:
	ofxOscReceiver receiver_;
	ofxOscSender sender_;
	// osc message that we receive
	ofxOscMessage message_;

	// values we want to change
	bool create_power_up_;
	int enemy_shoot_interval_;

	oscCommunicator();
	void setup();
	void update();
};
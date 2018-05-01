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
	bool move_up_ = false;
	bool move_down_ = false;
	bool move_left_ = false;
	bool move_right_ = false;
	bool shoot_ = false;

	oscCommunicator();
	void setup();
	void update();
};
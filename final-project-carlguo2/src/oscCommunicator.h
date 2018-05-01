#pragma once

#include <iostream>
#include <string>
#include "ofxOsc.h"

class oscCommunicator {
private:
	// ip address of sender (the iphone)
	std::string sender_host_ = "10.195.150.2";
	// ports that send and receive data
	int sender_port_ = 8000;
	int receiver_port_ = 8001;
	// root of messages to be sent
	std::string message_address_root_ = "/game";

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
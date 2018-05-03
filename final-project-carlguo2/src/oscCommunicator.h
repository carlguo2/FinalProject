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
	// string messages of commands
	std::string left_message = "/game/move_left";
	std::string right_message = "/game/move_right";
	std::string up_message = "/game/move_up";
	std::string down_message = "/game/move_down";
	std::string left_down_message = "/game/diag/left_down";
	std::string right_down_message = "/game/diag/right_down";
	std::string left_up_message = "/game/diag/left_up";
	std::string right_up_message = "/game/diag/right_up";
	std::string shoot_message = "/game/shoot";
	std::string start_message = "/game/start";
	std::string pause_message = "/game/pause";

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
	bool start_game_ = false;
	bool pause_game_ = false;

	oscCommunicator();
	
	void update();
};
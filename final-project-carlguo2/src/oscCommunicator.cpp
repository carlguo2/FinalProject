#include "oscCommunicator.h"

// standard constructor
oscCommunicator::oscCommunicator() {
	// set up the ip address and port that receives data
	sender_.setup(sender_host_, sender_port_);
	// set up port that receives data from device
	receiver_.setup(receiver_port_);

	// set up the root of message path 
	message_.setAddress(message_address_root_);
}

void oscCommunicator::update() {
	// check if osc communicator is sending messages
	while (receiver_.hasWaitingMessages()) {
		// take messages
		ofxOscMessage m;
		// get the message
		receiver_.getNextMessage(&m);

		// check if message is to move left
		if (m.getAddress() == "/game/move_left") {  //todo: split this stuff into methods so stick to DRY principle
			// update the get left boolean
			move_left_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/move_right") {
			move_right_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/move_up") {
			move_up_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/move_down") {
			move_down_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/diag/left_down") {
			move_left_ = m.getArgAsInt(0);
			move_down_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/diag/right_down") {
			move_right_ = m.getArgAsInt(0);
			move_down_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/diag/left_up") {
			move_left_ = m.getArgAsInt(0);
			move_up_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/diag/right_up") {
			move_right_ = m.getArgAsInt(0);
			move_up_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/shoot") {
			shoot_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/start") {
			start_game_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == "/game/pause") {
			pause_game_ = m.getArgAsInt(0);
		}
	}
}


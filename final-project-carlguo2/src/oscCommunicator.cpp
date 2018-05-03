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
		if (m.getAddress() == left_message) {  
			// update the get left boolean
			move_left_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == right_message) {
			move_right_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == up_message) {
			move_up_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == down_message) {
			move_down_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == left_down_message) {
			move_left_ = m.getArgAsInt(0);
			move_down_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == right_down_message) {
			move_right_ = m.getArgAsInt(0);
			move_down_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == left_up_message) {
			move_left_ = m.getArgAsInt(0);
			move_up_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == right_up_message) {
			move_right_ = m.getArgAsInt(0);
			move_up_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == shoot_message) {
			shoot_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == start_message) {
			start_game_ = m.getArgAsInt(0);
		}
		if (m.getAddress() == pause_message) {
			pause_game_ = m.getArgAsInt(0);
		}
	}
}


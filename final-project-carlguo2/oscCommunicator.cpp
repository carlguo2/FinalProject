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
		std::cout << "message" << endl;
		// take messages
		ofxOscMessage m;
		// create a message to send back to host
		ofxOscMessage send_back_to_host;
		// get the message
		receiver_.getNextMessage(&m);

		// check if message is to move left
		if (m.getAddress() == "/game/move_left") {
			// update the get left boolean
			move_left_ = m.getArgAsInt32(0);
			// check if message is properly received
			std::cout << "moved left" << endl;
			// send back message
			send_back_to_host.addIntArg(move_left_);
			send_back_to_host.setAddress("/updatedVals/move_left");
			sender_.sendMessage(send_back_to_host);
		}
	}
}

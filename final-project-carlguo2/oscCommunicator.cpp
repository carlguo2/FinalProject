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

oscCommunicator::setup() {

}

oscCommunicator::update() {

}

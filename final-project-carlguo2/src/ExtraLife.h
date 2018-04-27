#pragma once

#include "ofMain.h"

class ExtraLife {
// class for the extra life power up
public:
	ofPoint position_;
	float speed_;
	float width_;
	ofImage* img_;

	void setup(ofImage* img);
	void update();
	void draw();
};
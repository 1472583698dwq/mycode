#pragma once
#include"zuobiao.h"

class rectangle1
{public:

	zuobiao left;//左上角的坐标
	zuobiao right;//右下角的坐标
	int blood;
	bool judgmet(zuobiao&left1) {
		
		if (left1.x > left.x && left1.x<right.x && left1.y>left.y && left1.y < right.y) {
			return false;
		}
		else {
			return true;
		}
	}
	virtual void view() {

	}
	virtual  void fly1() {

	}
	virtual void blood() {

	}
};


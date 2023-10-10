#pragma once
#include<graphics.h>
#include"rectangle.h"
#include<iostream>
using namespace std;
class bullet:public rectangle1
{public:
	
	IMAGE fire,fire1;
	int blood = 10;//血量
	bullet(int x, int y) {
		left.x = x + 40;
		left.y = y;
		loadimage(&fire, "bullet2.png");
		loadimage(&fire1, "bullet1.png");
		right.x = fire1.getwidth() + x;
		right.y = y + fire1.getwidth();
}
	void fly() {
		putimage(left.x, left.y, &fire);
		right.y -= 8;
		left.y -= 8;
	}
	void fly1() {
		putimage(left.x, left.y, &fire1);
		right.y-= 8;
		left.y -= 8;
	}
	void blood() {
		blood = 1;
	}
};


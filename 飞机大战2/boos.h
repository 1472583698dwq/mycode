#pragma once

#include"bullet.h"
#include <cstdlib>
#include<vector>
#include<iostream>
#include"rectangle.h"
class boos :public rectangle1
{
public:
	//vector<bullet>zidan;
	//rectangle rect;
	int blood = 30;
	IMAGE boss;
	boos() {
		loadimage(&boss, "enemy1.png");
		left.x = (rand() % 30 + 1) * 10;//随机生成敌机的x坐标
		left.y = -10;//生成的y坐标
		right.x = boss.getwidth() + left.x;
		right.y = boss.getheight() + left.y;
		blood = 30;

	}
	void view() {

		putimage(left.x, left.y, &boss);

		left.y += 4;
		right.y += 4;
		//坐标变化
	}
	bool xiaohui() {
		if (right.y > 720) {
			return false;
		}
		else {
			return true;
		}
	}
	
};


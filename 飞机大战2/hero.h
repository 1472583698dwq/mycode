#pragma once
#include<graphics.h>
#include<vector>
#include"bullet.h"
#include<easyx.h>
#include<iostream>
#include"rectangle.h"
using namespace std;
class hero:public rectangle1
{public:
	int blood=100;

	IMAGE player;//玩家的飞机
	ExMessage mo;
	vector<bullet>Bullet;
	hero() {
		loadimage(&player, "me1.png");
	//初始化飞机
		left.x = 240;
		left.y = 600;
		right.x = left.x + player.getwidth();
		right.y = left.y + player.getheight();

	 }
	//绘制飞机的移动
	void movie() {
		
		left.x = mo.x;
		left.y = mo.y;
		
		if (peekmessage(&mo, EM_MOUSE)) {
			switch (mo.message)
			{
			case WM_MOUSEMOVE: {
				putimage(mo.x-20, mo.y, &player);
			}
			default:
				break;
			}
		
		}
		else {
			putimage(mo.x-20, mo.y, &player);
		}
		

	}

	bool dead(vector<rectangle1*>&a) {
		auto a1 = a.begin();
		for (a1; a1 < a.end(); a1++) {
			if (!judgmet((*a1)->left)) {
				return false;
			}
		}
		return true;
	}
	
};


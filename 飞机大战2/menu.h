#pragma once
#include<graphics.h>
#include<easyx.h>
#include<iostream>
#include"hero.h"
#include"bullet.h"
#include<vector>
#include"boos.h"
using namespace std;
/*用vector来操作使用继承多态的类时，并不能储存类的本体因为在释放内存时基类无法被释放，应让父类指针指向基类，
容器中只保存父类指针*/
class menu
{
public:
	vector<rectangle1*> bos;//用来储存敌机的弹匣
	int bos1 = 0;//用来记录何时出现敌机
	vector<rectangle1*>Bullet;//子弹的弹夹
	void menuview() {
		IMAGE img1;
		loadimage(&img1, "bk.png");
		putimage(0, 0, &img1);
		roundrect(160, 400, 350, 450, 5, 5);
		roundrect(160, 300, 350, 350, 5, 5);
		settextcolor(WHITE);
		settextstyle(30, 20, "宋体");
		outtextxy(200, 420, "开始游戏");
		outtextxy(160, 300, "结束游戏");
		
	}
	//游戏的主循环
	void begin(bool &a1) {
		IMAGE img1, img2;//加载背景
		loadimage(&img1, "bk.png");
		loadimage(&img2, "bk.png");
		int y=0, y1=-700; 
		hero player;
		
		
		while (a1) {//游戏的主要循环
			
			Sleep(1);
			
			putimage(0, y, &img1);//绘制背景
			putimage(0, y1, &img2);
			
			if (bos1%5 ==0){//控制何时发射子弹
				rectangle1* a= new bullet (player.left.x, player.left.y);
				Bullet.push_back(a);
			}
			
			auto it = Bullet.begin();
			
			for (it; it != Bullet.end(); it++) {
				(*it)->fly1();
			}
			deletebullet();
			Sleep(1);
			flushmessage();
			Sleep(1);
			a1=player.dead(bos);//判定飞机死亡
			cout << a1 << endl;
			player.movie();
			
			bos1++;//用来计数
			if (bos1 == 25) {//产生敌机
				rectangle1 *a=new boos;
				bos.push_back(a);
				bos1 = 0;
			}
			bos2();
			vector<rectangle1*>::iterator it1;//绘制敌机
			for (it1 = bos.begin(); it1 != bos.end(); it1++) {
				(*it1)->view();
			}
			FlushBatchDraw();
			y++, y1++;
			if (y1 == 0) {//重置背景
				y = 0;
				y1 = -700;

			}
			cleardevice();
		}
		
	}
	void choose(bool &start) {//选择界面
		ExMessage mag;
		if (peekmessage(&mag, EM_MOUSE)) {
			switch (mag.message)
			{
			case WM_LBUTTONDOWN:
				if (mag.x >= 160 && mag.x <= 350 && mag.y >= 400 && mag.y <= 450) {
					cout << "00000" << endl;
					begin(start);
				}
				else if (mag.x >= 160 && mag.x <= 350 && mag.y >= 300 && mag.y <= 350) {
					start = false;
				}

			default:
				break;
			}
		}
	}
	void bos2() {//检测敌机是否被判定死亡.
		
			auto it = bos.begin();
			while (it!=bos.end())
			{
				bool tre = true;//用来判断是否执行删除操作
				if ((*it)->left.y > 700) {
					delete (*it);
					it = bos.erase(it);
					cout << "chujie" << endl;
					tre = false;
					
				}
				if (tre) {//界外和击中时互斥不能同时发生
					auto it1 = Bullet.begin();//执行删除操作
					for (it1; it1 < Bullet.end(); it1++) {
						if (!(*it)->judgmet((*it1)->left)) {
							delete(*it);
							(boos)(*it)->blood -= 5;
							if((*it)->blood==0)it = bos.erase(it);
							
							cout << "siwang" << endl;
							tre = false;
							break;//删除敌机后指针变空停止循环
							
						}
					}
				}
				if (tre) {
					it++;
			}
			}
			
}
	void deletebullet() {//删除越界的子弹
		auto it = Bullet.begin();
	while(it!=Bullet.end()) {
			if ((*it)->left.y < 0) {
				delete (*it);
				it = Bullet.erase(it);
				cout << ".........." << endl;
			}
			else {
				it++;
			}
		}
	}

};


// 飞机大战2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<graphics.h>
#include"menu.h"
using namespace std;
int main()
{
    initgraph(480, 700, EW_SHOWCONSOLE);
    BeginBatchDraw();
    bool start = true;
    menu a1;
    
    //a1.begin(start);
    while (start) {
      
        a1.menuview();
        FlushBatchDraw();
        a1.choose(start);
		}
  
        
    
   EndBatchDraw();
   return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <conio.h>

#include "animation.hpp"
#include "global.hpp"
#include "utils.hpp"
#include "raise.hpp"
#include "bomb.hpp"
#include "firework.hpp"
#include "frame.hpp"



void animation::first_animation::Display()
{
	initgraph(animation::scrW, animation::scrH);
	InitPositionSystem();
	
	BeginBatchDraw();
	IMAGE logo;
	loadimage(&logo, _T("D:/ChromDownload/firework/firework/firework/res_1.png"),200,100);
	
	DWORD* pScreen = GetImageBuffer(nullptr);	// 获取屏幕显存
	animation::frame calFrame(0);			// 限制帧数为60, 若改为0则不限制帧数 
	//calFrame.Begin();
	
	/*for (int i = 0; i < 640; i++)
	{
		setlinecolor(i);
		line(i, 0, i, 479);
	}
	cleardevice();
	setbkmode(TRANSPARENT);*/

	const int maxFireNums = 50;		// 最大烟花个数
	std::list<animation::firework> arr;

	srand(static_cast<unsigned>(time(nullptr)));
	for (int i = 0; i < 30; ++i)		// 初始化3个烟花
	{
		animation::firework tmp;
		arr.push_back(tmp);
	}

	while (!_kbhit())
	{
		animation::ClearScreen(pScreen, animation::scrW, animation::scrH);
		//cleardevice();
		//putimage(0, 0, &logo,PATPAINT);

		// 所有的烟花每帧进行更新烟花属性和绘画
		for (std::list<animation::firework>::iterator it = arr.begin(); it != arr.end();)
		{
			it->Update();

			it->Draw();
			
			if (it->IsStop())
			{
				it = arr.erase(it);
			}
			else
			{
				it++;
			}
		}

		setaspectratio(1.0, 1.0);		// 设置缩放比例 以及坐标方向， 在这里不设置回来的话，文字输出是镜面反转的
		setorigin(0, 0);				// 设置坐标原点
		putimage(0, 0, &logo, SRCCOPY);
		InitPositionSystem();

		//绘制帧数 
		DrawFrame(calFrame.Value(), animation::scrW/4, animation::scrH/4);
		FlushBatchDraw();
		calFrame.Flush();

		if (!animation::genRand.GetInt(0, 40) && arr.size() < maxFireNums) // 随机生成数字 0,1,2,...,40  数字为0的话，随机生成一个烟花
		{
			animation::firework tmp;
			arr.push_back(tmp);
		}
	}
	EndBatchDraw();
	while (!_kbhit());
	return ;
}

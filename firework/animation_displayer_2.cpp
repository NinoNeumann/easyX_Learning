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
void animation::second_animation::Display() {

	initgraph(animation::scrW, animation::scrH);
	InitPositionSystem();

	BeginBatchDraw();
	IMAGE logo;
	loadimage(&logo, _T("D:/ChromDownload/firework/firework/firework/res_1.png"), 200, 100);

	DWORD* pScreen = GetImageBuffer(nullptr);	// 获取屏幕显存
	animation::frame calFrame(0);			// 限制帧数为60, 若改为0则不限制帧数 
	
	EndBatchDraw();
	while (!_kbhit());


}
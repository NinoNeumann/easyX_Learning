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

	DWORD* pScreen = GetImageBuffer(nullptr);	// ��ȡ��Ļ�Դ�
	animation::frame calFrame(0);			// ����֡��Ϊ60, ����Ϊ0������֡�� 
	
	EndBatchDraw();
	while (!_kbhit());


}
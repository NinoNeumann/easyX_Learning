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
	
	DWORD* pScreen = GetImageBuffer(nullptr);	// ��ȡ��Ļ�Դ�
	animation::frame calFrame(0);			// ����֡��Ϊ60, ����Ϊ0������֡�� 
	//calFrame.Begin();
	
	/*for (int i = 0; i < 640; i++)
	{
		setlinecolor(i);
		line(i, 0, i, 479);
	}
	cleardevice();
	setbkmode(TRANSPARENT);*/

	const int maxFireNums = 50;		// ����̻�����
	std::list<animation::firework> arr;

	srand(static_cast<unsigned>(time(nullptr)));
	for (int i = 0; i < 30; ++i)		// ��ʼ��3���̻�
	{
		animation::firework tmp;
		arr.push_back(tmp);
	}

	while (!_kbhit())
	{
		animation::ClearScreen(pScreen, animation::scrW, animation::scrH);
		//cleardevice();
		//putimage(0, 0, &logo,PATPAINT);

		// ���е��̻�ÿ֡���и����̻����Ժͻ滭
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

		setaspectratio(1.0, 1.0);		// �������ű��� �Լ����귽�� �����ﲻ���û����Ļ�����������Ǿ��淴ת��
		setorigin(0, 0);				// ��������ԭ��
		putimage(0, 0, &logo, SRCCOPY);
		InitPositionSystem();

		//����֡�� 
		DrawFrame(calFrame.Value(), animation::scrW/4, animation::scrH/4);
		FlushBatchDraw();
		calFrame.Flush();

		if (!animation::genRand.GetInt(0, 40) && arr.size() < maxFireNums) // ����������� 0,1,2,...,40  ����Ϊ0�Ļ����������һ���̻�
		{
			animation::firework tmp;
			arr.push_back(tmp);
		}
	}
	EndBatchDraw();
	while (!_kbhit());
	return ;
}

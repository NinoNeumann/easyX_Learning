#include "utils.hpp"
#include "global.hpp"

void animation::ClearScreen(DWORD* pScreen, int screenW, int screenH)
{
	int i = 0;
	for (; i < screenW; i++)
	{
		pScreen[i] = 0;
	}
	for (; i < screenW * (screenH - 1); i++)
	{
		int left = i - 1;		// 左
		int right = i + 1;		// 右
		int up = i - screenW;	// 上
		int bottom = i + screenW;	// 下

		int r = int(((double)GetRValue(pScreen[i]) + (double)GetRValue(pScreen[left]) + (double)GetRValue(pScreen[right]) + (double)GetRValue(pScreen[up]) + (double)GetRValue(pScreen[bottom])) / 5.8);
		int g = int(((double)GetGValue(pScreen[i]) + (double)GetGValue(pScreen[left]) + (double)GetGValue(pScreen[right]) + (double)GetGValue(pScreen[up]) + (double)GetGValue(pScreen[bottom])) / 5.8);
		int b = int(((double)GetBValue(pScreen[i]) + (double)GetBValue(pScreen[left]) + (double)GetBValue(pScreen[right]) + (double)GetBValue(pScreen[up]) + (double)GetBValue(pScreen[bottom])) / 5.8);

		pScreen[i] = RGB(r, g, b);
	}
	for (; i < screenW * screenH; i++)
	{
		pScreen[i] = 0;
	}
}


// 设置坐标系统
void animation::InitPositionSystem()
{
	setaspectratio(static_cast<float>(animation::asp), static_cast<float>(-animation::asp));	// 设置缩放比例 以及坐标方向
	setorigin(0, animation::scrH);				// 设置坐标原点
}

// 显示帧数
void animation::DrawFrame(int Value, int x = 5, int y = 5)
{
	setbkmode(TRANSPARENT);			// 透明文字
	settextcolor(RGB(0, 255, 0));
	settextstyle(20, 0, TEXT("新宋体"));


	setaspectratio(1.0, 1.0);		// 设置缩放比例 以及坐标方向， 在这里不设置回来的话，文字输出是镜面反转的
	setorigin(0, 0);				// 设置坐标原点
	TCHAR buff[256];
	wsprintf(buff, _T("%d FPS"), Value);
	outtextxy(x, y, buff);

	InitPositionSystem();
}
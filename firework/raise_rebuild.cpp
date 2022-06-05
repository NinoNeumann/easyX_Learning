#include "raise.hpp"
#include <cmath>

#define j2h(x) (20*3.1415926*(x)/180.0)

animation::raise::raise(
	position _Pos, \
	double	 _Vx, \
	double	 _Vy, \
	int		 _R    \
)
{
	vx = _Vx;
	vy = _Vy;
	r = _R;
	state = raise::_state::RAISE;	// ״̬
	ck = clock();					// ʱ��
	pos = _Pos;						// λ��

	beginBomb = nullptr;
	color = RGB(genRand.GetInt(0, 255), genRand.GetInt(0, 255), genRand.GetInt(0, 255));
	theFire = nullptr;
}

void  animation::raise::Update()
{

	// ��¼��ǰʱ�䣬������ʱ��
	clock_t old_ck = ck;
	ck = clock();
	clock_t dt = ck - old_ck;

	// �����ٶ�
	double old_vy = vy;

	// ���ﳢ���޸�һ���̻������Ĺ켣 �޸ĳ�sin���������ӵ�
	double old_vx = vx;

	vx = 0.5 * sin(j2h(animation::angle % 3600)) / 100.0;
	angle %= 3600;
	angle++;

	//


	vy = vy - g * dt / 1000.0;
	if (vy < 0.0)
	{						// ���������㱬ը��
		state = raise::_state::STOP;
		if (beginBomb != nullptr)
		{		// �����û��ı�ը����
			beginBomb(theFire, pos, r);
		}
	}

	// ����λ��
	pos.y += old_vy * dt / 1000.0 - g * dt * dt / 2.0 / 1000000.0;	// ʱ�䵥λΪ ms ���Գ� 1000000.0
	pos.x += vx * dt;

}

void  animation::raise::Draw()
{
	if (IsStop())
	{
		return;
	}		// ֹͣ״̬��ֹͣ�滭

	for (int i = 0; i < 15; i += 1)
	{
		setfillcolor(RGB(GetRValue(color) * pow(0.96, i), GetGValue(color) * pow(0.96, i), GetBValue(color) * pow(0.96, i)));
		solidcircle(int(pos.x *  animation::posRate), int(pos.y *  animation::posRate - double((double)i * 4)), r);
	}
}

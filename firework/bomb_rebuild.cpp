#include "bomb.hpp"

double  animation::bomb::max_v = 8.0; // ����ٶ�

 animation::bomb::bomb(position pos, COLORREF col, double _Vx, double _Vy, double _Vz) :
	thePos(pos),
	vx(_Vx),
	vy(_Vy),
	vz(_Vz),
	theColor(col)
{
	start_ck = clock();		// ��ʼ��ʱ��
	ck = start_ck;
	state = _state::ALIVE;	// ��ʼ��״̬
	R =  animation::bomb::radius;	// ��ʼ���̻���ը�����뾶
}

void  animation::bomb::Update()
{
	if (IsDead())
	{
		return;
	}

	// ����ʱ��
	clock_t old_ck = ck;
	ck = clock();
	clock_t dt = old_ck - ck;
	if (ck - start_ck > (clock_t)bomb::alive)
	{
		state = _state::DEAD;
		return;
	}

	// �����ٶȡ�����
	double old_vy = vy;
	if (vy < 0)
	{
		vy = vy -  animation::g * dt / 1000.0 -  animation::a_windx * dt / 1000.0;			// V = V0 - gt;
		thePos.y += old_vy * dt / 1000.0 - 0.5 * g * dt * dt / 1000000.0;	//h = V0*t - 1/2*g*t^2
	}
	else
	{
		vy = vy -  animation::g * dt / 1000.0 +  animation::a_windx * dt / 1000.0;			// V = V0 - gt;
		thePos.y += old_vy * dt / 1000.0 - 0.5 * g * dt * dt / 1000000.0;	//h = V0*t - 1/2*g*t^2
	}

	double old_vx = vx;
	if (vx < 0)
	{
		vx = vx -  animation::a_windx * dt / 1000.0;
		thePos.x += old_vx * dt / 1000.0 - 0.5 * a_windx * dt * dt / 1000000.0;
	}
	else
	{
		vx = vx +  animation::a_windx * dt / 1000.0;
		thePos.x += old_vx * dt / 1000.0 - 0.5 * a_windx * dt * dt / 1000000.0;
	}

}

void  animation::bomb::Draw()
{
	if (IsDead()) return;
	setfillcolor(theColor);
	solidcircle(int(thePos.x *  animation::posRate), int(thePos.y *  animation::posRate), R);
}
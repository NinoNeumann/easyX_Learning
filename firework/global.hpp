#pragma once
#include <Windows.h>
#include "utils.hpp"
#include "sound.hpp"

namespace animation
{
	extern int angle;
	extern IMAGE logo;
	extern const double g;			// �������ٶ�			(m/s^2)
	extern double		a_windx;	// ˮƽ�������ϵ��		(m/s^2)
	extern const double v_max;		// ����̻�һ�׶γ��ٶ�	(  m/s)
	extern const double v_min;		// ��С�̻�һ�׶γ��ٶ�	(  m/s)
	extern const double h_max;		// ���߶�				(    m)
	extern const double w_max;		// �����              (    m)

	extern int scrW;				// ��Ļ���
	extern int scrH;				// ��Ļ�߶�

	extern Random genRand;			// ���ڲ����������ʵ��

	extern double       asp;		// ��������
	extern const int	posRate;	// �̻�����ӳ�䵽��Ļ����ĳ�������

	extern const int max_alive_time;// ��ը�����������ʱ�� ��ms��
	extern const int min_alive_time;// ��ը������С����ʱ�� ��ms��

	animation::sound& raiseSound();		// ȫ��ʹ��һ�� raise.wav ʵ��
	animation::sound& bombSound();			// ȫ��ʹ��һ��  bomb.wav ʵ��
	// todo  �޸���������Ƶ�ļ�  ���Ҽ���������Ƶ�ļ�

	struct position
	{
		double x;
		double y;
		position() :x(0.0f), y(0.0f) {}
		position(double _X, double _Y) :x(_X), y(_Y) {}
	};
}
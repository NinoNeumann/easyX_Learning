#include "global.hpp"

namespace animation
{
	int angle = 0;
	IMAGE logo;

	
	const double g = 9.8;	// �������ٶ�			(m/s^2)
	double a_windx = -2;  // ˮƽ����ϵ��			(m/s^2)
	const double v_max = 28.0;	// ����̻�һ�׶γ��ٶ�	(  m/s)
	const double v_min = 15.8;	// ��С�̻�һ�׶γ��ٶ�	(  m/s)
	const double h_max = 40.0;  // ���߶�				(    m)
	const double w_max = 100.0;	// �����              (    m)

	//int scrW = GetSystemMetrics(SM_CXSCREEN);	// ��Ļ���
	//int scrH = GetSystemMetrics(SM_CYSCREEN);	// ��Ļ�߶�

	int scrW = 800;		// ��Ļ���
	int scrH = 600;		// ��Ļ�߶�

	const int posRate = 100;  // �̻�����ӳ�䵽�ĳ���������Ļ����
	double	  asp = min(scrW / (w_max * posRate), scrH / (h_max * posRate)); // ��������


	Random genRand((unsigned int)time(nullptr));	// ���ڲ��������

	const int max_alive_time = 1400;
	const int min_alive_time = 1200;

	animation::sound& raiseSound()
	{
		static animation::sound sound(L"raise.wav", 0, 1000);
		return sound;
	}

	animation::sound& bombSound()
	{
		static animation::sound sound(L"bomb.wav", 0, 1000);
		return sound;
	}

}
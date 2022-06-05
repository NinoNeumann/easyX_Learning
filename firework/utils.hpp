#pragma once


#pragma once
#include <graphics.h>
#include <ctime>

namespace animation
{

	// ���������Ļ�� ����ʹ�ý����е�����Χ���ص����ƽ�����������ص��������ȫ����Сֵ��Ҳ���Ǻ�ɫ��0��
	/*
	* pScreen ��ʾ����
	* screenW ���
	* screenH �߶�
	*/
	void ClearScreen(DWORD* pScreen, int screenW, int screenH);


	/***************************���ڲ��������***********************/
	class Random
	{
	private:
		unsigned int seed;	// ���������

	public:
		Random(unsigned int s)
		{
			seed = s;
			srand(seed);
		}

		int Value()
		{
			seed = rand();
			srand(static_cast<unsigned>(time(nullptr)) - seed);
			return seed;
		}

		/***************����һ��[low,gight]��Χ������*****************/
		int GetInt(int low, int hight)
		{
			return Value() % (hight - low + 1) + low;
		}

		/***************����һ��[low,gight]��Χ�ĸ���������ȷ���ٷ�λ*****************/
		double GetDouble(double low, double hight)
		{
			double tmp = GetInt(static_cast<int>(low * 100), static_cast<int>(hight * 100));
			return tmp / 100.0;
		}
	};


}
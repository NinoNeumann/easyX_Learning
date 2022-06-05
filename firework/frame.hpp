#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>
namespace animation
{
	/************����֡�ʵĿ��ƺͼ���**********/
	class frame
	{
	public:
		unsigned Value() { return theFrame; }
	public:
		frame(int f = 0);
		void Begin();		// ��ʼʱ����
		void Flush();		// ÿ֡����
		void Sleep(unsigned int ms);	// ˯�� ms ���� 

	private:
		int theFrame;		// ��ǰ֡��
		int defaultFrame;	// 0�������п���
		int defaultDt;		// Ĭ��ÿ֡��ʱ���

		LARGE_INTEGER curTick;		// ��ʱʹ��
		LARGE_INTEGER tickPerSecond;// ÿ��ʱ�ӵδ�����
	public:
	};
}

#pragma once

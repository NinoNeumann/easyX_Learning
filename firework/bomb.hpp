#pragma once
#include <ctime>
#include <cmath>
#include <Windows.h>
#include "global.hpp"
#include "animation.hpp"
namespace animation
{
	/******************************�̻���ը��Ч����*******************************/
	class bomb:public anima
	{
	public:
		static const unsigned radius = 7; // �̻������İ뾶		 (��λ������) 
		static double		  max_v;	  // ��ը�����ٶȵ����ֵ ����λ��m/s��
		enum class _state :int			  // �̻���״̬
		{
			ALIVE = 1,	// �̻���ը�����ڴ��״̬
			DEAD = 2	// �̻���ը������������ʱ��󣬱�Ϊ����״̬
		};

	public:
		/*
		* ����Ĭ�������ʼ���̻���ը������һЩ����
		*/
		bomb(
			position pos = position(0.0, 0.0),
			COLORREF col = RGB(genRand.GetInt(0, 255), genRand.GetInt(0, 255), genRand.GetInt(0, 255)),
			double _Vx = genRand.GetDouble(-bomb::max_v, bomb::max_v),
			double _Vy = genRand.GetDouble(-15.0, 2.0),
			double _Vz = genRand.GetDouble(-bomb::max_v, bomb::max_v)
		);

		/*****��������******/
		void SetPosition(const position pos) { this->thePos = pos; }
		void SetColor(const COLORREF color) { this->theColor = color; }
		void SetVelocity(const double _Vx, const double _Vy, const double _Vz) { vx = _Vx; vy = _Vy; vz = _Vz; }
		void SetRedius(int r) { R = r; }

	public:
		bool IsDead() { return state == _state::DEAD; }
		bool IsAlive() { return state == _state::ALIVE; }

		void Dead() { state = _state::DEAD; }
		void Alive() { state = _state::ALIVE; }

		void Update();			// �̻���ը����ÿ֡���и��£��������ÿ֡����һ��
		void Draw();			// �滭���̻�������ÿ֡����һ��

	private:
		position thePos;		// �̻�������λ��

		double vx;				// �ٶ�����
		double vy;
		double vz;

		COLORREF theColor;		// �̻���ը��������ɫ

		clock_t ck;				// ���ڼ���ÿ֡����ʱ�����Ϣ�����������ٶ�λ�õ���Ϣ
		clock_t start_ck;		// �����̻���ը������ʱ�䣬���ڸ����̻���ը����״̬��ÿ���������и�����ʱ�� alive����

		int R;					// �̻��뾶����λ�����أ�

		_state state;
	public:

		unsigned alive = 1000;	// Ĭ���̻����ʱ��
	};

}
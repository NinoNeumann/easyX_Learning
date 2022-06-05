#pragma once
#include <list>
#include <vector>
#include "bomb.hpp"
#include "global.hpp"
#include "raise.hpp"

namespace animation
{
	class raise;
	/**********************�̻���*********************
	* ÿ���̻���Ϊ�����̣��������������̣���������� raise ����ɣ������������̻���ʼ������
	* ��ĩ�˿�ʼը����ը���Ĺ��������ɸ� bomb ��������ɣ�Ĭ��ʱ60�� bomb ������60�������� InitBombs
	* ������ɳ�ʼ�����ú�����Ϊ����ָ��Ĳ������� raise �����У��� raise �����Ϊ STOP ״̬����á�
	******/
	class firework:public anima
	{
	public:
		const static int defaultNums = 100;		// ÿ���̻���ը��ı�ը����������Ĭ��Ϊ 60 ��
		enum class _state :int
		{
			START = 1,		// ��ʼ״̬
			RAISE = 2,		// ����״̬
			BOMB = 3,		// ��ը״̬
			STOP = 4		// �̻�����
		};

	public:
		bool IsStop() { return state == _state::STOP; }

		void SetStart() { state = _state::START; }
		void SetRaise() { state = _state::RAISE; }
		void SetBomb() { state = _state::BOMB; }
		void SetStop() { state = _state::STOP; }
		void SetPosition( animation::position pos) { m_pos = pos; }
		void SetColor(COLORREF color) { m_color = color; }
		void SetBombsNums(int nums) { m_inums = nums; }

		std::vector< animation::bomb*>& GetBombsArray() { return this->m_lsBombs; }
		const COLORREF& GetColor() { return this->m_color; }

	public:
		/*************�����ʼ���̻���һЩ����*************/
		firework(
			 animation::position pos =  animation::position( animation::genRand.GetDouble(10.0,  animation::w_max - 10.0), 0.0),
			COLORREF     color = RGB(genRand.GetInt(0, 255), genRand.GetInt(0, 255), genRand.GetInt(0, 255))
		);
		firework(const firework& fire);		// ������ָ���Ա�������Լ�ʵ��һ�¸��ƹ��캯��
		~firework();
	public:
		void Update();		// �����̻����ԣ�ÿ֡����
		void Draw();		// �滭���̻�

	public:
		void static InitBombs(animation::firework* fire, const  animation::position pos, int redius);	// ��ը���ӵĳ�ʼ��
	private:
		animation::raise* m_raise;	// �̻���������

		std::vector< animation::bomb*>	m_lsBombs;	// �̻���ըЧ��
		int						m_inums;	// �̻���ը���Ӹ���
		int						state_flag;	// ���ڸ����̻�״̬ʱ���Ա�ը���Ӵ��� DEAD �Ľ��м����������б�ը���Ӷ����� DEAD ״̬���̻��Żᴦ�� STOP ״̬��

		 animation::position			m_pos;		// �̻���ʼλ��
		COLORREF				m_color;	// �̻���ɫ
		_state					state;		// �̻�״̬

	};
}
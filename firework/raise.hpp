#pragma once
#include "animation.hpp"
#include "global.hpp"

namespace animation {
	class firework;
	class raise : public anima {
	public:
		static const int max_r = 50;	// �̻������뾶
		static const int min_r = 30;	// �̻�����С�뾶

		enum class _state :int
		{
			RAISE = 1,	// �ڷ���״̬
			STOP = 2	// ��ֹͣ״̬
		};

	public:

		raise(
			position _Pos = position(genRand.GetDouble(5.0, animation::w_max - 5.0), 0.0), \
			double	 _Vx = 0.0, \
			double	 _Vy = genRand.GetDouble( animation::v_min,  animation::v_max), \
			int		 _R = genRand.GetInt(raise::min_r, raise::max_r)\
		);

	public:

		bool IsRaise() { return state == _state::RAISE; }
		bool IsStop() { return state == _state::STOP; }
		void Raise() { state = _state::RAISE; }
		void Stop() { state = _state::STOP; }

		void Update();	//ÿ֡���ã����ڸ����̻���λ�á��ٶȡ����������
		void Draw();	//��ʾ�̻�


		_state State() { return state; }
		void SetBomb(void (*bomb)( animation::firework* fire, const position pos, int redius)) { beginBomb = bomb; }
		void SetColor(COLORREF col) { color = col; }
		void SetPosition( animation::position p) { pos = p; }
		void SetFire( animation::firework* f) { theFire = f; }
	private:

		_state		state;	// �̻����״̬
		int			r;		// �̻���İ뾶    
		double		vx;		// x�����ٶ�
		double		vy;		// y�����ٶ�
		position	pos;	// �̻�λ��
		clock_t		ck;		// ��ǰʱ���¼
		COLORREF	color;	// ��¼��ɫ��Ϣ

		void (*beginBomb)( animation::firework* fire, const position pos, int redius); // ��ʼ����ըЧ���ĺ���ָ��
		 animation::firework* theFire;	// ��beginBomb��ʼ����ըЧ���������ʹ�ã���ʾ����ʼ�����̻�
	};

}
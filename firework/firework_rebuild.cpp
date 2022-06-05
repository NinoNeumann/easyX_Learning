#include "firework.hpp"
#include <algorithm>

 animation::firework::firework( animation::position pos, COLORREF color):
	m_pos(pos),
	m_color(color),
	m_inums(defaultNums),
	m_raise(nullptr),
	state(_state::START),
	state_flag(0)
{
	m_raise = new  animation::raise(pos);
	m_raise->SetBomb(&firework::InitBombs);	// ���������󣬵��ô˺�����ɱ�ը���ӳ�ʼ��
	m_raise->SetColor(m_color);
	m_raise->SetFire(this);					// ��ը��ʼ�����̻�
	m_lsBombs.resize(m_inums);
}

// copy construct
 animation::firework::firework(const firework& fire)
{
	this->m_raise = new raise(*fire.m_raise);		// ����raise
	this->m_raise->SetFire(this);					// ��ը��ʼ�����̻�
	this->m_raise->SetBomb(&firework::InitBombs);	// ��ը��ʼ������
	this->m_color = fire.m_color;
	this->m_lsBombs.resize(fire.m_lsBombs.size());

	for (int i = 0; i < fire.m_lsBombs.size(); ++i) // �����̻�����
	{
		if (fire.m_lsBombs[i] != nullptr)
		{
			this->m_lsBombs[i] = new  animation::bomb(*fire.m_lsBombs[i]);
		}
		else
		{
			this->m_lsBombs[i] = nullptr;
		}
	}

	this->m_inums = fire.m_inums;
	this->m_pos = fire.m_pos;
	this->state = fire.state;
	this->state_flag = fire.state_flag;
}

 animation::firework::~firework()
{
	if (m_raise)
	{
		delete m_raise;
	}

	for (int i = 0; i < m_lsBombs.size(); ++i)
	{
		if (m_lsBombs[i])
		{
			delete m_lsBombs[i];
		}
	}
}

void  animation::firework::Update()
{
	switch (state)
	{
	case _state::START:
		m_raise->Update();
		raiseSound().Play();
		state = _state::RAISE;
		break;
	case _state::RAISE:
		m_raise->Update();
		break;
	case _state::BOMB:
		for (int i = 0; i < m_lsBombs.size(); ++i)
		{
			if (m_lsBombs[i] != nullptr)
			{
				m_lsBombs[i]->Update();
			}

			if (m_lsBombs[i]->IsDead())		// �����ı�ը���������
			{
				delete m_lsBombs[i];
				m_lsBombs.erase(m_lsBombs.begin() + i);
				state_flag++;
			}
		}

		if (state_flag >= m_inums)
		{
			state = _state::STOP;			// ���б�ը���Ӷ��������̻�״̬���³� STOP ��
		}
		break;
	case _state::STOP:
		break;
	}
}

void  animation::firework::Draw()
{
	switch (state)
	{
	case _state::START:
		m_raise->Draw();
		break;
	case _state::RAISE:
		m_raise->Draw();
		break;
	case _state::BOMB:
		for (int i = 0; i < m_lsBombs.size(); ++i)
		{
			if (m_lsBombs[i] != nullptr)
			{
				m_lsBombs[i]->Draw();
			}
		}
		break;
	case _state::STOP:
		break;
	}
}

// ��ʼ���̻���ը����
void  animation::firework::InitBombs( animation::firework* fire, const  animation::position pos, int redius)
{
	for (int i = 0; i < fire->GetBombsArray().size(); ++i)
	{
		fire->GetBombsArray()[i] = new  animation::bomb(pos, fire->GetColor());
		fire->GetBombsArray()[i]->SetRedius(int(redius * 0.618));
		fire->GetBombsArray()[i]->alive =  animation::genRand.GetInt(min_alive_time, max_alive_time);
	}
	fire->SetBomb();
	bombSound().Play();
}

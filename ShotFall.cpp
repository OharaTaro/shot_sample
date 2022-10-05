#include "ShotFall.h"
#include "game.h"

namespace
{
	constexpr float kGravity = 0.5f;
}

void ShotFall::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = 8.0f;
	m_vec.y = -8.0f;
}

void ShotFall::update()
{
	if (!m_isExist)	return;
	m_pos += m_vec;
	m_vec.y += kGravity;
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
	if (m_pos.y > Game::kScreenHeight)
	{
		m_isExist = false;
	}
}

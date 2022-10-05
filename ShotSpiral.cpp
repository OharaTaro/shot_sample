#include "ShotSpiral.h"
#include "game.h"
#include "DxLib.h"

namespace
{
	constexpr float kRadiusSpeed = 3.0f;
	constexpr float kRotSpeed = 0.05f;
}

void ShotSpiral::start(Vec2 pos)
{
	ShotBase::start(pos);

	float randState = static_cast<float>(GetRand(255));
	float randRate = randState / 256.0f;

	m_startPos = pos;
	m_radius = 0.0f;
	m_angle = DX_TWO_PI_F * randRate;
}

void ShotSpiral::update()
{
	if (!m_isExist)	return;
	
	m_radius += kRadiusSpeed;
	m_angle += kRotSpeed;

	m_pos.x = m_startPos.x + cosf(m_angle) * m_radius;
	m_pos.y = m_startPos.y + sinf(m_angle) * m_radius;

	if (m_radius > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
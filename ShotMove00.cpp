#include "ShotMove00.h"
#include "game.h"
#include "DxLib.h"

namespace
{
	// 初速
	constexpr float kShotSpeed = 16.0f;
	// 速度変更時間(フレーム)
	constexpr int kVecInterval = 48;
	// 減速
	constexpr float kDecRate = 0.9f;
}

void ShotMove00::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec = createVec();
	m_moveInterval = kVecInterval;
}

void ShotMove00::update()
{
	if (!m_isExist)	return;
	m_pos += m_vec;
	m_vec *= kDecRate;

	m_moveInterval--;
	if(m_moveInterval <= 0)
	{
		m_vec = createVec();
		m_moveInterval = kVecInterval;
	}
	
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}

// 進行方向生成
Vec2 ShotMove00::createVec()
{
	float randState = static_cast<float>(GetRand(255));
	float randRate = randState / 255.0f;
	float angle = (DX_PI_F / 6.0f) * randRate;
	if (GetRand(1))	angle *= -1.0f;

	Vec2 result;
	result.x = cosf(angle) * kShotSpeed;
	result.y = sinf(angle) * kShotSpeed;
	return result;
}
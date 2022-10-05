#pragma once

#include "ShotBase.h"

class ShotSpiral : public ShotBase
{
public:
	ShotSpiral()
	{
		m_radius = 0.0f;
		m_angle = 0.0f;
	}
	virtual ~ShotSpiral()
	{
	}

	// ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();

private:
	Vec2	m_startPos;
	float	m_radius;
	float	m_angle;
};
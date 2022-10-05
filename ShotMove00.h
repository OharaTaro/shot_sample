#pragma once

#include "ShotBase.h"

class ShotMove00 : public ShotBase
{
public:
	ShotMove00()
	{
		m_moveInterval = 0;
	}
	virtual ~ShotMove00()
	{
	}

	// ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();
private:
	// 進行方向生成
	Vec2 createVec();
private:
	int m_moveInterval;
};
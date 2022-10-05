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

	// �V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();
private:
	// �i�s��������
	Vec2 createVec();
private:
	int m_moveInterval;
};
#pragma once

#include "CGameView.h"

class CVisualEntity;

class CGameViewLocal : public CGameView {
public:
	void Update();
	void StateChanged(Message *command);

private:
	std::vector<CVisualEntity*> visualEntities;
};
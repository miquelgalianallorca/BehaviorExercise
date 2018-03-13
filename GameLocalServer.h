#pragma once

#include "CGameServer.h"

class Entity;
class CLogicEntity;

class GameLocalServer : public CGameServer {
public:
	GameLocalServer() : isPaused(false) {}
	~GameLocalServer();

	// Create logic entities
	void InitGame();
	// Execut entity logic
	void Update();
	
	// Update views
	void RegisterView(CGameView *_view);
	void StateChanged(Message *command);
	// Receive changes from view
	void ManagePlayerCommand(Message *command);

private:
	std::vector<CLogicEntity*> logicEntities;
	bool isPaused;
};
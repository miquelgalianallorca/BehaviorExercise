#include "stdafx.h"
#include "consola.h"
#include "GameLocalServer.h"
#include "CLogicEntity.h"
#include "Message.h"

GameLocalServer::~GameLocalServer() {
	for (auto entity : logicEntities) delete entity;
	logicEntities.clear();
}

void GameLocalServer::InitGame() {
	CGameServer::InitGame();
	logicEntities.push_back(new CLogicEntityHorse (this, 1, 40, 0));
	logicEntities.push_back(new CLogicEntityTurtle(this, 2,  0, 0));
}

void GameLocalServer::Update() {
	CGameServer::Update();
	for (auto entity : logicEntities) {
		if (!isPaused) entity->Update();
	}
	Sleep(300);
	clear();
}

void GameLocalServer::RegisterView(CGameView * _view) {
	CGameServer::RegisterView(_view);
	// Add visual entities
	for (auto logicEntity : logicEntities) {
		NewVisualEntityMessage * msg = new NewVisualEntityMessage(logicEntity->GetID(),
			logicEntity->GetPosX(), logicEntity->GetPosY(), logicEntity->GetType());
		StateChanged(msg);
		delete msg;
	}
}

void GameLocalServer::StateChanged(Message *command) {
	CGameServer::StateChanged(command);
}

void GameLocalServer::ManagePlayerCommand(Message *command) {
	CGameServer::ManagePlayerCommand(command);
	if (auto msg = dynamic_cast<PauseCommand*>(command)) {
		isPaused = msg->value;
	}
}
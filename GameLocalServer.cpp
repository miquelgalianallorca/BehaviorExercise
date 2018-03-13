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
	logicEntities.push_back(new CLogicEntityHorse (this, 0, 40, 0));
	logicEntities.push_back(new CLogicEntityTurtle(this, 1,  0, 0));
}

void GameLocalServer::Update() {
	CGameServer::Update();
	for (auto entity : logicEntities) {
		if (!isPaused) entity->Update();
	}
	Sleep(200);
	clear();
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
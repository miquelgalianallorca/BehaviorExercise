#include "stdafx.h"
#include "CLogicEntity.h"

#include "consola.h"
#include "CGameServer.h"
#include "Message.h"

void CLogicEntity::Move() {
	ChangePosCommand *command = new ChangePosCommand(ID, posX, posY);
	server->StateChanged(command);
	delete command;
}

void CLogicEntityHorse::Update() {
	posX -= 2;
	Move();
}

void CLogicEntityTurtle::Update() {
	++posX;
	Move();
}
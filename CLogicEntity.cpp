#include "stdafx.h"
#include "CLogicEntity.h"

#include "consola.h"
#include "CGameServer.h"
#include "Message.h"

void CLogicEntity::Move() {
	gotoxy(posX, posY);
	ChangePosCommand *command = new ChangePosCommand(posX, posY);
	server->StateChanged(command);
}

void CLogicEntityHorse::Update() {
	posX -= 2;
	Move();
}

void CLogicEntityTurtle::Update() {
	++posX;
	Move();
}
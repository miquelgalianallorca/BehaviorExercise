#include "stdafx.h"
#include "CGameViewLocal.h"
#include "CGameServer.h"
#include "CVisualEntity.h"
#include "CLogicEntity.h"
#include "Message.h"

void CGameViewLocal::Update() {
	CGameView::Update();
	// Keyboard input
	if (_kbhit()) {
		int key = _getch();
		PauseCommand *pauseCommand = nullptr;
		if (key == 'p') {
			pauseCommand = new PauseCommand(true);
			server->ManagePlayerCommand(pauseCommand);
		}
		else if (key == 'u') {
			pauseCommand = new PauseCommand(false);
			server->ManagePlayerCommand(pauseCommand);
		}
		delete pauseCommand;
	}
	// Update visual entities (draw)
	for (auto entity : visualEntities)
		entity->Update();
}

void CGameViewLocal::StateChanged(Message *command) {
	CGameView::StateChanged(command);
	if (auto msg = dynamic_cast<NewVisualEntityMessage*>(command)) {
		CVisualEntity *entity = nullptr;
		if (msg->logicEntity->GetType() == CLogicEntity::Type::HORSE)
			entity = new CVisualEntityHorse(msg->logicEntity->GetID(),
				msg->logicEntity->GetPosX(), msg->logicEntity->GetPosY());
		else if(msg->logicEntity->GetType() == CLogicEntity::Type::TURTLE)
			entity = new CVisualEntityTurtle(msg->logicEntity->GetID(),
				msg->logicEntity->GetPosX(), msg->logicEntity->GetPosY());
		visualEntities.push_back(entity);
	}
	else {
		for (auto entity : visualEntities)
			entity->StateChanged(command);
	}
}
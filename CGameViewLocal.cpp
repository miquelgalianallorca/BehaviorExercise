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
		if (msg->type == EntityType::HORSE)
			visualEntities.push_back(new CVisualEntityHorse (msg->ID, msg->posX, msg->posY));
		else if (msg->type == EntityType::TURTLE)
			visualEntities.push_back(new CVisualEntityTurtle(msg->ID, msg->posX, msg->posY));
	}
	else {
		for (auto entity : visualEntities)
			entity->StateChanged(command);
	}
}
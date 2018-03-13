#include "stdafx.h"
#include "CVisualEntity.h"
#include "consola.h"
#include "Message.h"

void CVisualEntity::StateChanged(Message *command) {
	if (auto msg = dynamic_cast<ChangePosCommand*>(command)) {
		posX = msg->posX;
		posY = msg->posY;
	}
}

// Draw =======================================================
void CVisualEntity::Update() {
	gotoxy(posX, posY);
}

void CVisualEntityHorse::Update() {
	CVisualEntity::Update();
	std::cout << "H";
}

void CVisualEntityTurtle::Update() {
	CVisualEntity::Update();
	std::cout << "T";
}
// ============================================================

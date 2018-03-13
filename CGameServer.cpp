#include "stdafx.h"
#include "CGameServer.h"
#include "CGameView.h"

void CGameServer::StateChanged(Message *command) {
	for (auto view : views) {
		view->StateChanged(command);
	}
}

void CGameServer::RegisterView(CGameView * _view) {
	views.push_back(_view);
}
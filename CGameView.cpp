#include "stdafx.h"
#include "CGameView.h"
#include "CGameServer.h"

void CGameView::Init(CGameServer* _server) {
	server = _server;
	server->RegisterView(this);
}

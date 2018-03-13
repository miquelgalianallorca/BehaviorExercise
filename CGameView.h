#pragma once

class CGameServer;
struct Message;

class CGameView {
public:
	void Init(CGameServer* _server);
	virtual void Update()                       {}
	virtual void StateChanged(Message *command) {}

protected:
	CGameServer *server;
};
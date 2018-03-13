#pragma once

class CGameView;
struct Message;

class CGameServer {
public:
	virtual void InitGame() {}
	virtual void Update()   {}

	// Called by view to update logic
	virtual void ManagePlayerCommand(Message *command) {}
	
	// Called by logic entities to update views
	virtual void StateChanged(Message *command);
	
	// Default register view
	virtual void RegisterView(CGameView* _view);

private:
	std::vector<CGameView*> views;
};
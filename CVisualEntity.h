#pragma once

class Message;

class CVisualEntity {
public:
	virtual ~CVisualEntity() {}
	virtual void Update();
	virtual void StateChanged(Message *command);

protected:
	CVisualEntity(int _ID, int _posX, int _posY) : ID(_ID), posX(_posX), posY(_posY) {}

private:
	int ID;
	int posX;
	int posY;
};

class CVisualEntityHorse : public CVisualEntity {
public:
	CVisualEntityHorse(int _ID, int _posX, int _posY) : CVisualEntity(_ID, _posX, _posY) {}
	void Update();
};

class CVisualEntityTurtle : public CVisualEntity {
public:
	CVisualEntityTurtle(int _ID, int _posX, int _posY) : CVisualEntity(_ID, _posX, _posY) {}
	void Update();
};
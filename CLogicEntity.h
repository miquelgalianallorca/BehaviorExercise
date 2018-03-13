#pragma once

#include "globals.h"

class CGameServer;

class CLogicEntity {
public:
	virtual ~CLogicEntity() {}
	virtual void Update() = 0;

	virtual EntityType GetType() const = 0;
	int GetID()   const { return ID;   }
	int GetPosX() const { return posX; }
	int GetPosY() const { return posY; }
	
protected:
	CLogicEntity(CGameServer* _server, int _ID, int _posX, int _posY) :
		server(_server), ID(_ID), posX(_posX), posY(_posY) {}
	
	void Move(); // Called in update
	
	int ID;
	int posX;
	int posY;
	EntityType type;
	CGameServer *server;
};

class CLogicEntityHorse : public CLogicEntity {
public:
	CLogicEntityHorse(CGameServer* _server, int _ID, int _posX, int _posY) :
		CLogicEntity(_server, _ID, _posX, _posY) {}
	void Update();
	EntityType GetType() const { return EntityType::HORSE; }
};

class CLogicEntityTurtle : public CLogicEntity {
public:
	CLogicEntityTurtle(CGameServer* _server, int _ID, int _posX, int _posY) :
		CLogicEntity(_server, _ID, _posX, _posY) {}
	void Update();
	EntityType GetType() const { return EntityType::TURTLE; }
};
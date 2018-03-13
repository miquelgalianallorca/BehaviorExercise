#pragma once

class CGameServer;

class CLogicEntity {
public:
	enum class Type { HORSE, TURTLE };
	virtual ~CLogicEntity() {}
	virtual void Update() = 0;	

	virtual Type GetType() const = 0;
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
	Type type;
	CGameServer *server;
};

class CLogicEntityHorse : public CLogicEntity {
public:
	CLogicEntityHorse(CGameServer* _server, int _ID, int _posX, int _posY) :
		CLogicEntity(_server, _ID, _posX, _posY) {}
	void Update();
	Type GetType() const { return Type::HORSE; }
};

class CLogicEntityTurtle : public CLogicEntity {
public:
	CLogicEntityTurtle(CGameServer* _server, int _ID, int _posX, int _posY) :
		CLogicEntity(_server, _ID, _posX, _posY) {}
	void Update();
	Type GetType() const { return Type::TURTLE; }
};
#pragma once

#include "globals.h"

class CLogicEntity;

struct Message {
protected:
	Message() {}
public:
	virtual ~Message() {}
};

struct PauseCommand : public Message {
	PauseCommand(bool _value) : value(_value) {}
	bool value;
};

struct ChangePosCommand :public Message {
	ChangePosCommand(int x, int y, int _ID) : ID(_ID), posX(x), posY(y) {}
	int ID;
	int posX;
	int posY;
};

struct NewVisualEntityMessage : public Message {
	NewVisualEntityMessage(int _ID, int _posX, int _posY, EntityType _type) :
		ID(_ID), posX(_posX), posY(_posY), type(_type) {}
	int ID;
	int posX;
	int posY;
	EntityType type;
};
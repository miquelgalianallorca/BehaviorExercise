#pragma once

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
	ChangePosCommand(int x, int y) : posX(x), posY(y) {}
	int posX;
	int posY;
};

struct NewVisualEntityMessage : public Message {
	int ID;
	int posX;
	int posY;
	EntityType type;
};
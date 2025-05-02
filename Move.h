#pragma once
#include <string>
#include "Type.h"

class Move {
	std::string name;
	int power;
	Type type;
	float accuracy;
	int pp;

public:
	Move() {
		name = "";
		power = -1;
		type = Type::NONE;
		accuracy = -1;
		pp = -1;
	}

	Move(std::string _name, int _power, Type _type, float _accuracy, int _pp) {
		name = _name;
		power = _power;
		type = _type;
		accuracy = _accuracy;
		pp = _pp;
	}

	std::string GetName() {
		return name;
	}

	int GetPower() {
		return power;
	}

	Type GetType() {
		return type;
	}

	float GetAccuracy() {
		return accuracy;
	}

	int GetPp() {
		return pp;
	}
};
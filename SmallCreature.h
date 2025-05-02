#pragma once
#include <string>
#include <vector>
#include "Type.h"
#include "Move.h"

class SmallCreature {
	std::string name;
	int level;
	int attack;
	int defense;
	int special;
	Type type1;
	Type type2;
	std::vector<Move> moves;

public:
	SmallCreature() {
		name = "";
		level = -1;
		attack = -1;
		defense = -1;
		special = -1;
		type1 = Type::NONE;
		type2 = Type::NONE;
		moves = std::vector<Move>(4);
	}

	SmallCreature(std::string _name, int _level, int _attack, int _defense, int _special,
		Type _type1, Type _type2, std::vector<Move> _moves) {
		name = _name;
		level = _level;
		attack = _attack;
		defense = _defense;
		special = _special;
		type1 = _type1;
		type2 = _type2;
		moves = _moves;
	}

	std::string GetName() {
		return name;
	}

	int GetLevel() {
		return level;
	}

	int GetAttack() {
		return attack;
	}

	int GetDefense() {
		return defense;
	}

	int GetSpecial() {
		return special;
	}

	Type GetType1() {
		return type1;
	}

	Type GetType2() {
		return type2;
	}

	bool LearnMove(Move move) {
		bool result = false;
		
		for (int i = 0; i < moves.size(); i++) {
			Move currentMove = moves[i];

			if (currentMove.GetType() == Type::NONE) {
				moves[i] = currentMove;
				
				result = true;

				break;
			}
		}

		return result;
	}

	/*
		[1] Scratch
		[2] Growl
	*/

	void ForgetMove(int position) {
		for (int i = 0; i < moves.size(); i++) {
			// Move currentMove = moves[i];

			if (i == position - 1) {
				moves[i] = Move();
			}
		}
	}
};
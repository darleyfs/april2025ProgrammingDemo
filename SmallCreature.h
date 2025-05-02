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

	int GetCurrentHP() {
		// TODO return HP field
		return 0;
	}

	// Accept a move to be learned
	bool LearnMove(Move move) {
		
		// Initialize a default value
		bool result = false;
		
		// Search through the entire move list
		for (int i = 0; i < moves.size(); i++) {

			// Copy a reference of the current move
			// in the position we're looking at
			Move currentMove = moves[i];

			// Check the type value of the Move object
			// and if the type is NONE, then it's a default
			// object, and thus, an empty space.
			if (currentMove.GetType() == Type::NONE) {
	
				// Replace that empty space with the 
				// move parameter that has been passed
				moves[i] = move;
				
				// true
				result = true;

				// Stop looking
				break;
			}
		}

		// TODO: Add an announcement that the move was learned

		// Return the result
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
			
				// TODO: Add an announcment that the move was forgotten
			}
		}
	}
};
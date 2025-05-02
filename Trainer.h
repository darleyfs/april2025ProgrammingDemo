#pragma once
#include <string>
#include <vector>
#include "SmallCreature.h"

class Trainer {
	std::string name;
	std::vector<SmallCreature> team;

public:	
	Trainer() {
		name = "";
		team = std::vector<SmallCreature>(5);
	}

	Trainer(std::string _name, std::vector<SmallCreature> _team) {
		name = _name;
		team = _team;
	}

	std::string GetName() {
		return name;
	}

	std::vector<SmallCreature> GetTeam() {
		return team;
	}

	SmallCreature GetSmallCreature(int position) {
		return team[position];
	}

	SmallCreature GetSmallCreature(std::string name) {
		SmallCreature result = SmallCreature();

		for (int i = 0; i < team.size(); i++) {
			SmallCreature currentCreature = team[i];

			if (currentCreature.GetName() == name) {
				result = currentCreature;
			}
		}

		return result;
	}

	bool AddSmallCreatureToTeam(SmallCreature creature) {
		bool result = false;

		for (int i = 0; i < team.size(); i++) {
			SmallCreature currentCreature = team[i];

			if (currentCreature.GetType1() == Type::NONE) {
				team[i] = creature;

				result = true;

				break;
			}
		}

		return result;
	}

	/*
		[1] Charguy   (0)
		[2] Bulbfrog  (1)
		[3] Splasher  (2)
	*/

	void RemoveSmallCreatureFromTeam(int position) {
		for (int i = 0; i < team.size(); i++) {
			if (i == position - 1) {
				team[i] = SmallCreature();
			}
		}
	}
};
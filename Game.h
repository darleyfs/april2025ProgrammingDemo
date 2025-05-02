#pragma once
#include "Trainer.h"
#include "Events.h"

class Game {
	Trainer player;
	Trainer rival;


public:
	Game() {
		player = Trainer();
		rival = Trainer();
	}

	void Start() {
		Events::Introduction(player, rival);
		Events::WakeUp(player.GetName());
		Events::TouchGrass(player.GetName());
		// TODO: Prof Oak's lab
		Events::SmallCreatureSelection(player, rival);
		
		// TODO: Choose a pokemon
	}
};
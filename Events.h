#pragma once
#include "UI.h"

class Events {
public:
	static std::string Introduction() {
        std::string profOak = "OAK";
        std::string playerName = "";
        std::string rivalName = "";


        UI::ShowMessage(profOak, "Welcome to the World of Pokemon!");
        UI::ShowMessage(profOak, "Pokemon just normal wild animals, \n  but we trap them and make them fight!");


        playerName = UI::PromptUser("OAK: What's your name?", "Name");

        UI::ShowMessage(profOak, "Hey, " + playerName + "!");
        UI::ShowMessage(profOak, "My grandson is a real little...hassle.\n  So I don't think of him much...");
        UI::ShowMessage(profOak, "He's like your bully, right?\n  What was his name again?");

        rivalName = UI::PromptUser("What's professor Oak's grandon's name?", "Rival");

        UI::ShowMessage(profOak, "Yea, f&*$ " + rivalName + ". All my homies hate, " + rivalName + ".");


        // Player wakes up in their room
        UI::ShowMessage(playerName + " wakes up in their room...");

        return playerName;
	}

    static void WakeUp(std::string playerName) {
        std::vector<std::string> menuOptions = {
            "Go back to sleep",           // 0
            "Play some video games",      // 1
            "Check your computer",        // 2
            "Go outside and maybe touch some grass" // 3
        };

        bool invalid = true;

        do {
            // TODO: Player makes some choices about what to do next
            int choice = UI::DisplayMenu(menuOptions, "Choice");

            // invalid = (choice > 0 && choice <= menuOptions.size());

            switch (choice) {
            case 1:

                UI::ShowMessage(playerName + " decided to go back to sleep.\n  Today just ain't the day.");
                invalid = false;
                break;
            case 2:
                UI::ShowMessage(playerName + " just decided to play games all day.");

                invalid = false;
                break;
            case 3:
                UI::ShowMessage(playerName + " checks their PC but nothing has happened.");

                invalid = false;
                break;
            case 4:
                UI::ShowMessage(playerName + " decides to go outside and maybe touch some grass.\n  What an icon.");

                invalid = false;
                break;
            default:
                std::cout << "Not a valid choice. Please try again..." << std::endl;
                std::cin.get();
                break;
            }
        } while (invalid);
    }
};
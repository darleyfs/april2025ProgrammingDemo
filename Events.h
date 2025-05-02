#pragma once
#include "UI.h"

class Events {
public:
    static void Introduction(Trainer& player, Trainer& rival) {
        std::string profOak = "OAK";

        UI::ShowMessage(profOak, "Welcome to the World of Pokemon!");
        UI::ShowMessage(profOak, "Pokemon just normal wild animals, \n  but we trap them and make them fight!");

        std::string playerName = UI::PromptUser("OAK: What's your name?", "Name");
        player.SetName(playerName);

        UI::ShowMessage(profOak, "Hey, " + playerName + "!");
        UI::ShowMessage(profOak, "My grandson is a real little...hassle.\n  So I don't think of him much...");
        UI::ShowMessage(profOak, "He's like your bully, right?\n  What was his name again?");

        std::string rivalName = UI::PromptUser("What's professor Oak's grandon's name?", "Rival");
        rival.SetName(rivalName);

        UI::ShowMessage(profOak, "Yea, f&*$ " + rivalName + ". All my homies hate, " + rivalName + ".");

        // Player wakes up in their room
        UI::ShowMessage(playerName + " wakes up in their room...");
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
                break;
            case 2:
                UI::ShowMessage(playerName + " just decided to play games all day.");
                break;
            case 3:
                UI::ShowMessage(playerName + " checks their PC but nothing has happened.");
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

    static void TouchGrass(std::string playerName) {
        int choice = 0;
        std::vector<std::string> menuOptions = {
            "Touch grass",
            "Do not touch grass"
        };

        UI::ShowMessage(playerName + " walks out into the sunlight,\n  and wanders around for a bit...");

        do {
            UI::ShowMessage(playerName + " stops briefly in front of a patch of grass\n  and begins to get a dangerous idea...");

            choice = UI::DisplayMenu(menuOptions, "Touch grass?");
        
            if (choice == 1) {
                UI::ShowMessage(playerName + " decides to risk it all, and touch grass...\n  How brave. Truly an icon. What an absolute unit.");
            }
            else {
                UI::ShowMessage(playerName + " will not be touching grass this time.\n  Big not worth.");
            }
        
        } while (choice != 1);

        UI::ShowMessage("OAK", "WHAT THE F$*& ARE YOU DOING?!");
        UI::ShowMessage("OAK", "Are you NUTS? There's BUGS IN THAT GRASS!!");
        UI::ShowMessage("OAK", "Meet me in my lab IMMEDIATELY.\n  We need to talk.");

    }
};
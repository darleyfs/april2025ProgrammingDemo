#pragma once
#include <iostream>
#include <string>
#include <vector>

class UI {
    static void ClearScreen() {
        system("cls");
    }

public:

    // static modifier | return type | parameter list
    static void ShowMessage(std::string message) {
        ClearScreen();

        std::string divider = "===========================================\n";

        std::cout << divider << std::endl;

        std::cout << "  " << message << "\n" << std::endl;

        std::cout << divider << std::endl;

        std::cout << "\n Press enter to continue..." << std::endl;
        std::cin.get();
    }

    // Overloaded version 
    static void ShowMessage(std::string subject, std::string message) {
        ClearScreen();

        std::string divider = "===========================================\n";

        std::cout << divider << std::endl;

        std::cout << "  " << subject << ": " << message << "\n" << std::endl;

        std::cout << divider << std::endl;

        std::cout << "\n Press enter to continue..." << std::endl;
        std::cin.get();
    }


    static std::string PromptUser(std::string primeText, std::string promptText) {
        ClearScreen();

        std::string result = "";

        std::cout << "  " << primeText << "\n" << std::endl;

        std::cout << "  " << promptText << ": ";

        getline(std::cin, result);

        return result;
    }

    static int DisplayMenu(std::vector<std::string> menuOptions, std::string promptText) {
        int result = 0;
        std::string response = "";

        do {
            ClearScreen();

            //  ( start       end         how often
            //  ( initialize; evaluation; increment)
            for (int i = 0; i < menuOptions.size(); i++) {
                std::string option = menuOptions[i];

                std::cout << "  [" << (i + 1) << "] " + option << std::endl;
            }

            std::cout << "\n  " << promptText << ": ";

            getline(std::cin, response);
        
            if (response == "") {
                std::cout << "  " << promptText << " can not be empty! Please try again...";

                std::cout << "\n Press enter to continue..." << std::endl;
                std::cin.get();
            }
        } while (response == "");

        result = std::stoi(response);


        // for(std::string option : menuOptions){
        // std::cout << option << std::end;
        // }  

        return result;
    }
};
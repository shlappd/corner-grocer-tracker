#ifndef MENU_H
#define MENU_H

#include <string>

enum class MenuOption {
    SearchItemFrequency = 1,
    ShowAllFrequencies = 2,
    DisplayHistogram = 3,
    ExitProgram = 4
};

// Prints the program menu to the console.
void displayMenu();

// Reads and validates the user's numeric menu selection.
MenuOption getValidatedMenuChoice();

// Prompts the user for an item name and rejects blank input.
std::string promptForItemName();

#endif
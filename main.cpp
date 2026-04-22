#include <iostream>
#include <string>

#include "FileConstants.h"
#include "GroceryTracker.h"
#include "Menu.h"

int main() {
    GroceryTracker tracker;

    // Load the grocery purchase data before showing the menu.
    if (!tracker.loadFromFile(ProjectConstants::INPUT_FILE_NAME)) {
        std::cerr << "Error: Could not open input file: "
            << ProjectConstants::INPUT_FILE_NAME << '\n';
        return 1;
    }

    // Exit early if the file opened but contained no usable grocery data.
    if (tracker.isEmpty()) {
        std::cerr << "Error: No grocery data was loaded from the input file.\n";
        return 1;
    }

    // Create the required backup file at program startup.
    if (!tracker.writeBackupFile(ProjectConstants::BACKUP_FILE_NAME)) {
        std::cerr << "Error: Could not create backup file: "
            << ProjectConstants::BACKUP_FILE_NAME << '\n';
        return 1;
    }

    MenuOption userChoice = MenuOption::ExitProgram;

    do {
        displayMenu();
        userChoice = getValidatedMenuChoice();

        switch (userChoice) {
        case MenuOption::SearchItemFrequency: {
            const std::string itemToSearch = promptForItemName();
            const int frequency = tracker.getItemFrequency(itemToSearch);

            std::cout << '\n'
                << "Frequency for \"" << itemToSearch << "\": "
                << frequency << "\n";
            break;
        }

        case MenuOption::ShowAllFrequencies:
            std::cout << "\nAll Grocery Item Frequencies\n";
            std::cout << "----------------------------\n";
            tracker.printAllFrequencies();
            break;

        case MenuOption::DisplayHistogram:
            std::cout << "\nGrocery Item Histogram\n";
            std::cout << "----------------------\n";
            tracker.printHistogram();
            break;

        case MenuOption::ExitProgram:
            std::cout << "\nExiting program.\n";
            break;
        }

    } while (userChoice != MenuOption::ExitProgram);

    return 0;
}
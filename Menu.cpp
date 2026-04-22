#include "Menu.h"

#include <iostream>
#include <limits>

namespace {
    // Local helper used only within this file.
    std::string trim(const std::string& text) {
        const std::string whitespace = " \t\r\n";
        const std::size_t firstCharacter = text.find_first_not_of(whitespace);

        if (firstCharacter == std::string::npos) {
            return "";
        }

        const std::size_t lastCharacter = text.find_last_not_of(whitespace);
        return text.substr(firstCharacter, lastCharacter - firstCharacter + 1);
    }
}

void displayMenu() {
    std::cout << "\n===================================\n";
    std::cout << "         Corner Grocer Menu        \n";
    std::cout << "===================================\n";
    std::cout << "1. Search item frequency\n";
    std::cout << "2. Show all frequencies\n";
    std::cout << "3. Display histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

MenuOption getValidatedMenuChoice() {
    int choice = 0;

    while (!(std::cin >> choice) || choice < 1 || choice > 4) {
        std::cout << "Invalid input. Please enter a number from 1 to 4: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Remove the leftover newline before any later getline() calls.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return static_cast<MenuOption>(choice);
}

std::string promptForItemName() {
    std::string itemName;

    while (true) {
        std::cout << "Enter the grocery item to search for: ";
        std::getline(std::cin, itemName);

        itemName = trim(itemName);

        if (!itemName.empty()) {
            return itemName;
        }

        std::cout << "Item name cannot be blank. Please try again.\n";
    }
}
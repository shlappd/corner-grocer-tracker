#include "GroceryTracker.h"

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "FileConstants.h"

bool GroceryTracker::loadFromFile(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        return false;
    }

    itemFrequencies.clear();

    std::string currentLine;
    while (std::getline(inputFile, currentLine)) {
        const std::string normalizedItem = normalizeItemName(currentLine);

        // Ignore blank or whitespace-only lines.
        if (!normalizedItem.empty()) {
            ++itemFrequencies[normalizedItem];
        }
    }

    return true;
}

bool GroceryTracker::writeBackupFile(const std::string& backupFileName) const {
    std::ofstream outputFile(backupFileName);

    if (!outputFile.is_open()) {
        return false;
    }

    for (const auto& entry : itemFrequencies) {
        outputFile << entry.first << ' ' << entry.second << '\n';
    }

    return true;
}

int GroceryTracker::getItemFrequency(const std::string& itemName) const {
    const std::string normalizedItem = normalizeItemName(itemName);
    const auto itemIterator = itemFrequencies.find(normalizedItem);

    if (itemIterator != itemFrequencies.end()) {
        return itemIterator->second;
    }

    return 0;
}

void GroceryTracker::printAllFrequencies() const {
    for (const auto& entry : itemFrequencies) {
        std::cout << std::left
            << std::setw(ProjectConstants::ITEM_LABEL_WIDTH)
            << entry.first
            << entry.second
            << '\n';
    }
}

void GroceryTracker::printHistogram() const {
    for (const auto& entry : itemFrequencies) {
        std::cout << std::left
            << std::setw(ProjectConstants::ITEM_LABEL_WIDTH)
            << entry.first;

        for (int count = 0; count < entry.second; ++count) {
            std::cout << '*';
        }

        std::cout << '\n';
    }
}

bool GroceryTracker::isEmpty() const {
    return itemFrequencies.empty();
}

std::string GroceryTracker::normalizeItemName(const std::string& itemName) {
    std::string normalized = trim(itemName);

    if (normalized.empty()) {
        return normalized;
    }

    // Convert the entire string to lowercase first.
    for (char& character : normalized) {
        character = static_cast<char>(
            std::tolower(static_cast<unsigned char>(character))
            );
    }

    // Convert the first letter of each word to uppercase for clean display.
    bool capitalizeNextLetter = true;
    for (char& character : normalized) {
        if (std::isspace(static_cast<unsigned char>(character))) {
            capitalizeNextLetter = true;
        }
        else if (capitalizeNextLetter && std::isalpha(static_cast<unsigned char>(character))) {
            character = static_cast<char>(
                std::toupper(static_cast<unsigned char>(character))
                );
            capitalizeNextLetter = false;
        }
        else {
            capitalizeNextLetter = false;
        }
    }

    return normalized;
}

std::string GroceryTracker::trim(const std::string& text) {
    const std::string whitespace = " \t\r\n";
    const std::size_t firstCharacter = text.find_first_not_of(whitespace);

    if (firstCharacter == std::string::npos) {
        return "";
    }

    const std::size_t lastCharacter = text.find_last_not_of(whitespace);
    return text.substr(firstCharacter, lastCharacter - firstCharacter + 1);
}
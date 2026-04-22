#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker {
public:
    bool loadFromFile(const std::string& inputFileName);
    bool writeBackupFile(const std::string& backupFileName) const;

    int getItemFrequency(const std::string& itemName) const;
    void printAllFrequencies() const;
    void printHistogram() const;

    bool isEmpty() const;

private:
    std::map<std::string, int> itemFrequencies;

    static std::string normalizeItemName(const std::string& itemName);
};

#endif
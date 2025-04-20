#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ItemClass.hpp"

class Inventory {
private:
    std::vector<Item*> items; // Store pointers to items
public:
    ~Inventory(); // Destructor to clean up memory
    void addItem(Item* item); // Add an item to the inventory
    void removeItem(const std::string& itemName); // Remove an item from the inventory
    void displayInventory() const; // Display the contents of the inventory
};

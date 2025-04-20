#include "Inventory.hpp"

// Destructor to free memory allocated for items
Inventory::~Inventory() {
    // Iterate through items vector and delete each item
    for (auto& item : items) {
        delete item; // Free memory for each item
    }
}

// Method to add an item to the inventory
void Inventory::addItem(Item* item) {
    items.push_back(item); // Add the item pointer to the items vector
}

// Method to display the contents of the inventory
void Inventory::displayInventory() const {
    if (items.empty()) {
        std::cout << "Inventory is empty." << std::endl;
    }
    else {
        std::cout << "Inventory:" << std::endl;
        // Iterate through items and display their name and description
        for (const auto& item : items) {
            std::cout << "- " << item->getName() << ": " << item->getDescription() << std::endl;
        }
    }
}

// Method to remove an item from the inventory by name
void Inventory::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            // Delete item pointer and remove it from vector
            delete* it; // Free memory for the item
            items.erase(it); // Remove the item pointer from the items vector
            return;
        }
    }
}

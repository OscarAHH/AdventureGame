#include "../Header/room.h" // Include the header file for "Room.h"
#include "../Header/item.h" // Include the header file for "Item.h"

// Constructor for room class, initializes member variable description with value passed as desc
Room::Room(std::string desc) : description(desc) {}

// Function PrintConnections assigned to Room
void Room::PrintConnections() {
    std::cout << "\nRoom: " << description << " & ";
    for (auto& exit : exits) {
        // Parses through the available exits and outputs the direction and description of connected room
        std::cout << "Exit: " << exit.first << ", Connected Room: " << exit.second->GetDescription() << "\n" << std::endl;
    }
}

// Function AddItem assigned to Room with parameter Item and uses item to add an item to a room
void Room::AddItem(Item& item) {
    items.emplace_back(item); // Adds the item back to the room
}

// Function to return the description of a room
std::string Room::GetDescription() {
    return description; // Returns description
}

// Function to return items
std::vector<Item> Room::GetItems() {
    return items; // Returns items
}

// Function to get the exits from the room
std::map<std::string, Room*>& Room::GetExits() {
    return exits; // Returns the available exits
}

// Function to get an exit from a room with the direction
Room* Room::GetExit(std::string direction) {
    auto it = exits.find(direction); // Search for the exit in the exits map based on the given direction
    std::cout << "\n" << direction; // Outputs the direction being searched for
    if (it != exits.end()) { // Checks if the exit was found
        return it->second; // Returns a pointer to the connected room
    }
    else {
        std::cout << "\nExit not found for direction " << direction << std::endl; // Outputs the exit wasn't found
        return nullptr; // Returns a null pointer
    }
}

// A function to connect the exits from the current room to the new room
void Room::connectExit(std::string direction, Room* room) {
    exits[direction] = room; // Connects the exit with the direction to the room
}

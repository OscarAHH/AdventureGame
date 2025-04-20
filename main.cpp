#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include <random> // Provides facilities for generating random numbers
#include <chrono> // Provides utilities for measuring time
#include <thread> // Provides utilities for managing threads and sleeping


//Include the files for the game


#include "../Header/item.h" //Includes the header file for "Item.h"
#include "../Header/area.h" //Includes the header file for "Area.h"
#include "../Header/character.h" //Includes the header file for "Character.h"
#include "../Header/room.h" //Includes the header file for "Room.h"



int main() {
    // Create an instance of the Area class
    Area gameWorld;
    // Load the game map from a text file
    gameWorld.LoadMapFromFile("./Resource/game_map.txt");
    // Create a Player
    Player player("Alice", 100);
    // Set the player's starting room (you can modify this room name)
    Room* currentRoom = gameWorld.GetRoom("startRoom");

    /*
    Use line 30 to add the other rooms into the game
    */

    player.SetLocation(currentRoom);

    /*
    Correct syntax for items:
    Item [item]("[item name]", "[item description]")
    */

    /*
    Correct syntax for adding items to room:
    [room name]->AddItem([item])
    */

    // Game loop
    while (true) {
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
        std::cout << "Items in the room:" << std::endl;
        for (Item& item : player.GetLocation()->GetItems()) {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
        }
        std::cout << "Exits available: ";
        for (auto& exit : player.GetLocation()->GetExits()) {
            std::cout << exit.first << " ";
        }
        std::cout << "| ";
        std::cout << "Options: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Move to another room | ";
        std::cout << "4. Quit" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            // Player looks around (no action required)
            std::cout << "You look around the room." << std::endl;
        }
        else if (choice == 2) {
            // Player interacts with an item in the room
            std::cout << "Enter the name of the item you want to interact with:";
            std::string itemName;
            std::cin >> itemName;
            for (Item& item : player.GetLocation()->GetItems()) {
                if (item.GetName() == itemName) {
                    item.Interact();
                    break;
                }
            }
        }
        else if (choice == 3) {
            // Player moves to another room
            std::cout << "Enter the direction (e.g., north, south): ";
            std::string direction;
            std::cin >> direction;
            Room* nextRoom = player.GetLocation()->GetExit(direction);
            if (nextRoom != nullptr) {
                player.SetLocation(nextRoom);
                std::cout << "You move to the next room." << std::endl;
                currentRoom = nextRoom;
            }
            else {
                std::cout << "You can't go that way." << std::endl;
            }
        }
        else if (choice == 4) {
            // Quit the game
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}

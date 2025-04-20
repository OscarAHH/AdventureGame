#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include "../Header/item.h" //Includes the header file for "Item.h"
#include "../Header/room.h" //Includes the header file for "Room.h"
#include "../Header/character.h" //Includes the header file for "Character.h"


//Character class


//New features are hitpoints and experience
Character::Character(std::string& name, int health) : name(name) {}
/*
Constructor for Character class, intitializes member variables name, health, hitpoints and experience with values passed as name, health, hitpoints and experience
*/
void Character::PrintStats() { //A function to output the player stats
    std::cout << "\nYou have a health of " << health << std::endl;
    //Outputs the players stats
}
void Character::TakeDamage(int damage) { //New feeature: A function to idecrease health on player
    health = health - damage; //Minuses the players health
    if (health > 0) { //Checks if player health is greater than 0
        std::cout << "\nYou have taken " << damage << " damage. Your health is: " << health << std::endl;
        //Outputs a message saying the damage to the player done and current health
    }
    else {
        health = 0; //Sets health to 0
        std::cout << "\nYou died! Better luck next time." << std::endl; //Outputs a message to the player saying that they have died
        std::exit(0); //Exits the game
    }
}
void Character::AddToInventory(Item& newItem) { //New feature: Max amount of item to add in player inventory through function
    if (inventory.size() < 2) { //Checks if the size of the inventory is less than 2
        inventory.emplace_back(newItem); //Adds the new item
        std::cout << "\nAmount of items in inventory: " << inventory.size() << "\n" << std::endl;
        //Outputs the amount of items in inventory
    }
    else {
        std::cout << "\nAmount of items in inventory: " << inventory.size() << "\n" << std::endl;
        //Outputs the amount of items in inventory
        std::cout << "\nYou have reached the maximum amount of items (which is 2) in your inventory and cannot add anymore items.\n" << std::endl;
        //Outputs a message saying max. items are 2
    }
}
std::string& Character::GetName() { //A function to get the name of the player
    return name; //Returns the name of the player
}
std::vector<Item>& Character::GetInventory() { //A function to get the players inventory
    return inventory; //Returns the players inventory
}

//New features: Hitpoints and experience
Player::Player(std::string name, int health) : Character(name, health) {}
/*
Constructor for Player class, which is derived from the Character class. The base class with the attributes name, health, hitpoints and experience are initialized
*/
Room* Player::GetLocation() { //A function to get the location of the player
    return location; //Returns the location
}
void Player::SetLocation(Room* newLocation) { //A function to set the new location
    location = newLocation; //Sets newLocation to the current location
}

#pragma once 
//Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <vector> //Allows for working with dynamic arrays (vectors)
#include "../Header/item.h" //Includes the header file for "Item.h"
#include "../Header/room.h" //Includes the header file for "Room.h"


//Character class and Player class

/*
//New features are hitpoints and experience
*/

class Character {
private:
	std::string name; //String used to name the character
	int health; //Integer to give the healthpoints (new)
	std::vector<Item> inventory; //A vector which contains the character inventory of items
public:
	Character(std::string& name, int health); //Constructor for character class
	void PrintStats(); //A function to output the chracter stats (health, shield hitpoints, level, and XP) 
	void TakeDamage(int damage); //A function to decrease character health
	void AddToInventory(Item& newItem); //A function to add items to the characters inventory
	std::string& GetName(); //A function to get the character name
	std::vector<Item>& GetInventory(); //A function to get the characters inventory.
};
class Player : public Character {
private:
	Room* location; //Pointer used to point to a room of where the player is located
public:
	Player(std::string name, int health); //Constructor for Player class
	Room* GetLocation(); //A function used to get the players location
	void SetLocation(Room* newLocation); //A function used to set the new location for the player
};

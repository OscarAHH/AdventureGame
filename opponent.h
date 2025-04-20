#pragma once
#ifndef OPPONENT_H
#define OPPONENT_H

#include <iostream>
#include <vector>
#include <string>

// Declaration of the Opponent class
class Opponent {
private:
    std::string name;
    int health;

public:
    // Constructor for initializing an opponent
    Opponent(const std::string& name, int health);

    // Method to get the name of the opponent
    std::string getName() const;

    // Method to get the health of the opponent
    int getHealth() const;

    // Method to set the health of the opponent
    void setHealth(int newHealth);

    // Method to apply damage to the opponent
    void takeDamage(int damage);
};

// Declaration of the OpponentList class
class OpponentList {
private:
    std::vector<Opponent> opponents;

public:
    // Constructor for initializing an opponent list
    OpponentList(const std::string& name, int health);

    // Method to add an opponent to the list
    void addOpponent(const Opponent& opponent);

    // Method to remove an opponent from the list by name
    void removeOpponent(const std::string& opponentName);
};

#endif // OPPONENT_H


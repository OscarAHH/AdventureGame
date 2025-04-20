#include "Opponent.h"

// Opponent class implementation
Opponent::Opponent(std::string name, int health) : name(name), health(health) {}

std::string Opponent::getName() {
    return name;
}

int Opponent::getHealth() {
    return health;
}

void Opponent::setHealth(int newHealth) {
    health = newHealth;
}

void Opponent::takeDamage(int damage) {
    health -= damage;
    // Ensure health doesn't go below 0
    if (health < 0) {
        health = 0;
    }
}

// OpponentList class implementation
class OpponentList {
private:
    std::vector<Opponent> opponents;

public:
    // Constructor not shown for brevity

    // Method to add an opponent to the list
    void addOpponent(const Opponent& opponent) {
        opponents.push_back(opponent);
    }

    // Method to remove an opponent from the list by name
    void removeOpponent(const std::string& opponentName) {
        for (auto it = opponents.begin(); it != opponents.end(); ++it) {
            if (it->getName() == opponentName) {
                opponents.erase(it);
                return;
            }
        }
    }
};

// Explanation:
// This code demonstrates two classes: Opponent and OpponentList.
// The Opponent class represents individual opponents in the game and provides methods to interact with them.
// The OpponentList class extends the behavior of Opponent through composition by managing a collection of Opponent objects.
// OpponentList encapsulates a vector of Opponent objects and provides methods to add and remove opponents from the list.
// By using composition, OpponentList achieves modularity and separation of concerns, adhering to the principles of object-oriented design.

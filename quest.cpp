#include <string>
#include <vector>

class Quest {
public:
    enum Status {
        NotStarted,
        InProgress,
        Completed
    };

    // Constructor definition
    Quest(const std::string& desc, Status status);

    // Marks the quest as started
    void startQuest();

    // Updates the quest status, progressing it if it's not completed
    void updateQuest();

    // Marks the quest as completed
    void completeQuest();

    // Retrieves the status of the quest as a string
    std::string getStatus() const;

    // Method to retrieve the description of the quest
    std::string getDescription() const { return questDesc; }

private:
    std::string questDesc; // Description of the quest
    Status currentStatus; // Current status of the quest
};

// Constructor definition
Quest::Quest(const std::string& desc, Status status) : questDesc(desc), currentStatus(status) {}

// Marks the quest as started
void Quest::startQuest() {
    currentStatus = InProgress; // Update status to indicate the quest is in progress
}

// Updates the quest status, progressing it if it's not completed
void Quest::updateQuest() {
    // Convert enum to int to perform arithmetic operations
    int intValue = static_cast<int>(currentStatus);
    // Increment status only if it's less than Completed
    if (intValue < Completed)
        currentStatus = static_cast<Status>(intValue + 1); // Progress the quest status
}

// Marks the quest as completed
void Quest::completeQuest() {
    currentStatus = Completed; // Update status to indicate the quest is completed
}

// Retrieves the status of the quest as a string
std::string Quest::getStatus() const {
    // Switch-case to handle different status cases
    switch (currentStatus) {
    case NotStarted:
        return "Not Started";
    case InProgress:
        return "In Progress";
    case Completed:
        return "Completed";
    }
    // Default case for unknown status
    return "Unknown";
}

// Define the Player class that contains a collection of Quest objects
class Player {
public:
    void addQuest(const Quest& quest) {
        quests.push_back(quest); // Composition: Player class contains a collection of Quest objects
    }

    // Other methods for managing player's quests can be added here

private:
    std::vector<Quest> quests; // Composition: Player class is composed of a collection of Quest objects
};

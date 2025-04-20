
#include <iostream>
#pragma once

class Quest {
public:
    enum Status { NotStarted, InProgress, Completed };

    // Constructor with default values
    Quest(const std::string& desc = "", Status status = NotStarted);

    // Destructor (virtual as it's good practice for base classes)
    virtual ~Quest() {}

    // Public member functions
    void startQuest();
    void updateQuest();
    void completeQuest();
    std::string getStatus() const;

private:
    std::string questDesc;
    Status currentStatus;
};

#endif // QUEST_H


#pragma once
#include <string>

enum class Priority { High, Normal, Low };
enum class Status { Todo, InProgress, Done };

class Task {
public:
    Task(const std::string& title, Priority priority, const std::string& creationDate);

    const std::string& getTitle() const;
    Priority getPriority() const;
    Status getStatus() const;
    const std::string& getCreationDate() const;

    void setTitle(const std::string& title);
    void setPriority(Priority priority);
    void setStatus(Status status);

    void cycleStatus();

    std::string serialize() const;
    static Task deserialize(const std::string& line);

private:
    std::string title_;
    Priority priority_;
    Status status_;
    std::string creationDate_;
};

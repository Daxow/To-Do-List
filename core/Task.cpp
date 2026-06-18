#include "Task.hpp"
#include <stdexcept>

Task::Task(const std::string& title, Priority priority, const std::string& creationDate)
    : title_(title), priority_(priority), status_(Status::Todo), creationDate_(creationDate) {}

const std::string& Task::getTitle() const { return title_; }
Priority Task::getPriority() const { return priority_; }
Status Task::getStatus() const { return status_; }
const std::string& Task::getCreationDate() const { return creationDate_; }

void Task::setTitle(const std::string& title) { title_ = title; }
void Task::setPriority(Priority priority) { priority_ = priority; }
void Task::setStatus(Status status) { status_ = status; }

void Task::cycleStatus() {
    switch (status_) {
        case Status::Todo:       status_ = Status::InProgress; break;
        case Status::InProgress: status_ = Status::Done;       break;
        case Status::Done:       status_ = Status::Todo;       break;
    }
}

std::string Task::serialize() const {
    return title_ + "|" +
           std::to_string(static_cast<int>(priority_)) + "|" +
           std::to_string(static_cast<int>(status_)) + "|" +
           creationDate_;
}

Task Task::deserialize(const std::string& line) {
    size_t p1 = line.find('|');
    size_t p2 = line.find('|', p1 + 1);
    size_t p3 = line.find('|', p2 + 1);

    if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos)
        throw std::runtime_error("Invalid task format: " + line);

    std::string title = line.substr(0, p1);
    Priority priority = static_cast<Priority>(std::stoi(line.substr(p1 + 1, p2 - p1 - 1)));
    Status status = static_cast<Status>(std::stoi(line.substr(p2 + 1, p3 - p2 - 1)));
    std::string date = line.substr(p3 + 1);

    Task t(title, priority, date);
    t.setStatus(status);
    return t;
}

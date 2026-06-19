#include "TaskManager.hpp"
#include "../utils/FileStorage.hpp"

void TaskManager::addTask(const std::string& title, Priority priority, const std::string& date) {
    tasks_.emplace_back(title, priority, date);
}

void TaskManager::removeTask(int index) {
    if (index >= 0 && index < static_cast<int>(tasks_.size()))
        tasks_.erase(tasks_.begin() + index);
}

void TaskManager::cycleStatus(int index) {
    if (index >= 0 && index < static_cast<int>(tasks_.size()))
        tasks_[index].cycleStatus();
}

const std::vector<Task>& TaskManager::getTasks() const {
    return tasks_;
}

std::vector<int> TaskManager::getFilteredIndices(FilterPriority fp, FilterStatus fs) const {
    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(tasks_.size()); ++i) {
        const Task& t = tasks_[i];

        bool matchPriority =
            fp == FilterPriority::All ||
            (fp == FilterPriority::High   && t.getPriority() == Priority::High)   ||
            (fp == FilterPriority::Normal && t.getPriority() == Priority::Normal) ||
            (fp == FilterPriority::Low    && t.getPriority() == Priority::Low);

        bool matchStatus =
            fs == FilterStatus::All ||
            (fs == FilterStatus::Todo       && t.getStatus() == Status::Todo)       ||
            (fs == FilterStatus::InProgress && t.getStatus() == Status::InProgress) ||
            (fs == FilterStatus::Done       && t.getStatus() == Status::Done);

        if (matchPriority && matchStatus)
            result.push_back(i);
    }
    return result;
}

void TaskManager::loadFromFile(const std::string& path) {
    tasks_ = FileStorage::load(path);
}

void TaskManager::saveToFile(const std::string& path) const {
    FileStorage::save(path, tasks_);
}

int TaskManager::size() const {
    return static_cast<int>(tasks_.size());
}

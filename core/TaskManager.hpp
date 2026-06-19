#pragma once
#include "Task.hpp"
#include <vector>
#include <string>

enum class FilterPriority { All, High, Normal, Low };
enum class FilterStatus   { All, Todo, InProgress, Done };

class TaskManager {
public:
    void addTask(const std::string& title, Priority priority, const std::string& date);
    void removeTask(int index);
    void cycleStatus(int index);

    const std::vector<Task>& getTasks() const;
    std::vector<int> getFilteredIndices(FilterPriority fp, FilterStatus fs) const;

    void loadFromFile(const std::string& path);
    void saveToFile(const std::string& path) const;

    int size() const;

private:
    std::vector<Task> tasks_;
};

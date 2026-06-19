#pragma once
#include "../core/Task.hpp"
#include <vector>
#include <string>

class FileStorage {
public:
    static std::vector<Task> load(const std::string& path);
    static void save(const std::string& path, const std::vector<Task>& tasks);
};

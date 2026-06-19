#include "FileStorage.hpp"
#include <fstream>
#include <stdexcept>

#ifdef _WIN32
#include <direct.h>
#define MAKE_DIR(p) _mkdir(p)
#else
#include <sys/stat.h>
#define MAKE_DIR(p) mkdir(p, 0755)
#endif

std::vector<Task> FileStorage::load(const std::string& path) {
    std::vector<Task> tasks;
    std::ifstream file(path);
    if (!file.is_open())
        return tasks;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        try {
            tasks.push_back(Task::deserialize(line));
        } catch (const std::exception&) {
        }
    }
    return tasks;
}

void FileStorage::save(const std::string& path, const std::vector<Task>& tasks) {
    size_t sep = path.find_last_of("/\\");
    if (sep != std::string::npos)
        MAKE_DIR(path.substr(0, sep).c_str());

    std::ofstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file for writing: " + path);

    for (const auto& task : tasks)
        file << task.serialize() << "\n";
}

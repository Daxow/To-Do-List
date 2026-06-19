#pragma once
#include "../core/TaskManager.hpp"
#include <string>
#include <vector>

class TerminalUI {
public:
    void render(const TaskManager& tm, int selectedIndex,
                FilterPriority fp, FilterStatus fs,
                const std::vector<int>& filteredIndices);

    void showHelp();
    std::string promptInput(const std::string& prompt);
    int promptPriority();
    bool promptConfirm(const std::string& msg);

private:
    std::string priorityColor(Priority p) const;
    std::string priorityLabel(Priority p) const;
    std::string statusLabel(Status s) const;
    std::string statusIcon(Status s) const;
    std::string filterPriorityLabel(FilterPriority fp) const;
    std::string filterStatusLabel(FilterStatus fs) const;
};

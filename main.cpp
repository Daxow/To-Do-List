#include <iostream>
#include "core/TaskManager.hpp"
#include "ui/TerminalUI.hpp"
#include "ui/InputHandler.hpp"
#include "utils/DateUtils.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

const std::string DATA_PATH = "data/tasks.txt";

int main() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    SetConsoleOutputCP(65001);
#endif

    TaskManager tm;
    tm.loadFromFile(DATA_PATH);

    TerminalUI   ui;
    InputHandler ih;

    FilterPriority fp = FilterPriority::All;
    FilterStatus   fs = FilterStatus::All;
    int selectedIndex = 0;
    bool running = true;

    while (running) {
        auto filteredIndices = tm.getFilteredIndices(fp, fs);
        int maxIdx = static_cast<int>(filteredIndices.size()) - 1;

        if (maxIdx < 0)
            selectedIndex = 0;
        else if (selectedIndex > maxIdx)
            selectedIndex = maxIdx;

        ui.render(tm, selectedIndex, fp, fs, filteredIndices);

        Action action = ih.getAction();

        switch (action) {
            case Action::Up:
                if (selectedIndex > 0) --selectedIndex;
                break;

            case Action::Down:
                if (!filteredIndices.empty() && selectedIndex < maxIdx)
                    ++selectedIndex;
                break;

            case Action::Left:
                fs = static_cast<FilterStatus>((static_cast<int>(fs) + 1) % 4);
                selectedIndex = 0;
                break;

            case Action::Right:
                fp = static_cast<FilterPriority>((static_cast<int>(fp) + 1) % 4);
                selectedIndex = 0;
                break;

            case Action::Create: {
                std::string title = ui.promptInput("Titre de la tache : ");
                if (!title.empty()) {
                    int prio = ui.promptPriority();
                    tm.addTask(title, static_cast<Priority>(prio), DateUtils::getCurrentDate());
                    tm.saveToFile(DATA_PATH);
                }
                break;
            }

            case Action::Delete:
                if (!filteredIndices.empty()) {
                    if (ui.promptConfirm("Supprimer cette tache ? (o/n) : ")) {
                        tm.removeTask(filteredIndices[selectedIndex]);
                        tm.saveToFile(DATA_PATH);
                        if (selectedIndex > 0) --selectedIndex;
                    }
                }
                break;

            case Action::Edit:
                if (!filteredIndices.empty()) {
                    tm.cycleStatus(filteredIndices[selectedIndex]);
                    tm.saveToFile(DATA_PATH);
                }
                break;

            case Action::Help:
                ui.showHelp();
                break;

            case Action::Quit:
                running = false;
                break;

            default:
                break;
        }
    }

    std::cout << "\033[2J\033[H" << std::flush;
    return 0;
}

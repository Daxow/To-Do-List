#include "TerminalUI.hpp"
#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

namespace {
    const std::string RESET   = "\033[0m";
    const std::string BOLD    = "\033[1m";
    const std::string DIM     = "\033[2m";
    const std::string RED     = "\033[31m";
    const std::string YELLOW  = "\033[33m";
    const std::string GREEN   = "\033[32m";
    const std::string CYAN    = "\033[36m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
}

static int waitKey() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

void TerminalUI::render(const TaskManager& tm, int selectedIndex,
                        FilterPriority fp, FilterStatus fs,
                        const std::vector<int>& filteredIndices) {
    std::cout << "\033[2J\033[H";

    std::cout << BOLD << CYAN
              << "==================== TO-DO LIST ====================\n"
              << RESET << "\n";

    std::cout << DIM
              << "[" << BOLD << "^v" << RESET << DIM << "] Nav  "
              << "[" << BOLD << "<>" << RESET << DIM << "] Filtre  "
              << "[" << BOLD << "c" << RESET << DIM << "] Creer  "
              << "[" << BOLD << "d" << RESET << DIM << "] Suppr  "
              << "[" << BOLD << "e" << RESET << DIM << "] Statut  "
              << "[" << BOLD << "h" << RESET << DIM << "] Aide  "
              << "[" << BOLD << "q" << RESET << DIM << "] Quitter\n"
              << RESET << "\n";

    if (filteredIndices.empty()) {
        std::cout << DIM << "  (Aucune tache trouvee)\n" << RESET;
    } else {
        for (int i = 0; i < static_cast<int>(filteredIndices.size()); ++i) {
            const Task& task = tm.getTasks()[filteredIndices[i]];
            bool selected = (i == selectedIndex);

            if (selected)
                std::cout << BOLD << GREEN << "> " << RESET;
            else
                std::cout << "  ";

            std::string pColor = priorityColor(task.getPriority());
            std::string pLabel = "[" + priorityLabel(task.getPriority()) + "]";
            std::cout << pColor << std::left << std::setw(9) << pLabel << RESET;

            std::cout << " " << statusIcon(task.getStatus()) << " ";

            if (selected) std::cout << BOLD;
            std::cout << std::left << std::setw(36) << task.getTitle();
            if (selected) std::cout << RESET;

            std::cout << "  " << DIM
                      << "(" << statusLabel(task.getStatus()) << ")"
                      << "  " << task.getCreationDate()
                      << RESET << "\n";
        }
    }

    std::cout << "\n";

    std::cout << BLUE
              << "Filtre : Priorite = " << filterPriorityLabel(fp)
              << " | Statut = " << filterStatusLabel(fs)
              << RESET << "\n";

    std::cout << std::flush;
}

void TerminalUI::showHelp() {
    std::cout << "\033[2J\033[H";
    std::cout << BOLD << CYAN
              << "====================== AIDE ======================\n"
              << RESET << "\n";

    auto line = [](const std::string& key, const std::string& desc) {
        std::cout << "  " << BOLD << std::left << std::setw(22) << key << RESET
                  << desc << "\n";
    };

    line("Fleches haut / bas",   "Naviguer dans la liste");
    line("Fleche gauche",        "Changer le filtre Statut");
    line("Fleche droite",        "Changer le filtre Priorite");
    line("c",                    "Creer une nouvelle tache");
    line("d",                    "Supprimer la tache selectionnee");
    line("e",                    "Modifier le statut (cycle : A faire > En cours > Terminé)");
    line("h",                    "Afficher cette aide");
    line("q",                    "Quitter le programme");

    std::cout << "\n" << DIM << "Appuyez sur une touche pour revenir...\n" << RESET << std::flush;
    waitKey();
}

std::string TerminalUI::promptInput(const std::string& prompt) {
    std::cout << "\n" << CYAN << prompt << RESET << std::flush;
    std::string input;
    std::cin.clear();
    std::getline(std::cin, input);
    return input;
}

int TerminalUI::promptPriority() {
    std::cout << CYAN << "Priorite :\n"
              << "  " << RED    << "[1]" << RESET << " Haute\n"
              << "  " << YELLOW << "[2]" << RESET << " Normale\n"
              << "  " << GREEN  << "[3]" << RESET << " Basse\n"
              << CYAN << "Choix (1-3) : " << RESET << std::flush;

    int ch = waitKey();
    std::cout << "\n";
    if (ch == '1') return 0;
    if (ch == '3') return 2;
    return 1; // default: Normal
}

bool TerminalUI::promptConfirm(const std::string& msg) {
    std::cout << YELLOW << msg << RESET << std::flush;
    int ch = waitKey();
    std::cout << "\n";
    return (ch == 'o' || ch == 'O' || ch == 'y' || ch == 'Y');
}

std::string TerminalUI::priorityColor(Priority p) const {
    switch (p) {
        case Priority::High:   return RED;
        case Priority::Normal: return YELLOW;
        case Priority::Low:    return GREEN;
    }
    return RESET;
}

std::string TerminalUI::priorityLabel(Priority p) const {
    switch (p) {
        case Priority::High:   return "Haute";
        case Priority::Normal: return "Normale";
        case Priority::Low:    return "Basse";
    }
    return "";
}

std::string TerminalUI::statusLabel(Status s) const {
    switch (s) {
        case Status::Todo:       return "A faire";
        case Status::InProgress: return "En cours";
        case Status::Done:       return "Terminé";
    }
    return "";
}

std::string TerminalUI::statusIcon(Status s) const {
    switch (s) {
        case Status::Todo:       return "[ ]";
        case Status::InProgress: return "[~]";
        case Status::Done:       return "[x]";
    }
    return "[ ]";
}

std::string TerminalUI::filterPriorityLabel(FilterPriority fp) const {
    switch (fp) {
        case FilterPriority::All:    return "Toutes";
        case FilterPriority::High:   return "Haute";
        case FilterPriority::Normal: return "Normale";
        case FilterPriority::Low:    return "Basse";
    }
    return "";
}

std::string TerminalUI::filterStatusLabel(FilterStatus fs) const {
    switch (fs) {
        case FilterStatus::All:        return "Tous";
        case FilterStatus::Todo:       return "A faire";
        case FilterStatus::InProgress: return "En cours";
        case FilterStatus::Done:       return "Terminé";
    }
    return "";
}

#include "InputHandler.hpp"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#endif

Action InputHandler::getAction() {
#ifdef _WIN32
    int ch = _getch();
    if (ch == 224 || ch == 0) {
        int code = _getch();
        switch (code) {
            case 72: return Action::Up;
            case 80: return Action::Down;
            case 75: return Action::Left;
            case 77: return Action::Right;
        }
        return Action::None;
    }
    switch (ch) {
        case 'c': case 'C': return Action::Create;
        case 'd': case 'D': return Action::Delete;
        case 'e': case 'E': return Action::Edit;
        case 'h': case 'H': return Action::Help;
        case 'q': case 'Q': return Action::Quit;
    }
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int ch = getchar();

    if (ch == 27) {
        int next = getchar();
        if (next == '[') {
            int code = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            switch (code) {
                case 'A': return Action::Up;
                case 'B': return Action::Down;
                case 'D': return Action::Left;
                case 'C': return Action::Right;
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return Action::None;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    switch (ch) {
        case 'c': case 'C': return Action::Create;
        case 'd': case 'D': return Action::Delete;
        case 'e': case 'E': return Action::Edit;
        case 'h': case 'H': return Action::Help;
        case 'q': case 'Q': return Action::Quit;
    }
#endif
    return Action::None;
}

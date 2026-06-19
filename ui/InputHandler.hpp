#pragma once

enum class Action {
    None,
    Up, Down, Left, Right,
    Create, Delete, Edit, Help, Quit
};

class InputHandler {
public:
    Action getAction();
};

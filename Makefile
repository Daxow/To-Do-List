NAME = td-cli

CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = main.cpp \
      core/Task.cpp \
      core/TaskManager.cpp \
      ui/TerminalUI.cpp \
      ui/InputHandler.cpp \
      utils/FileStorage.cpp \
      utils/DateUtils.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME).exe

re: fclean all

.PHONY: all clean fclean re

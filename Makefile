NAME		= tree
SRC			= main.cpp BaseHolder.cpp IntHolder.cpp CharArrayHolder.cpp DoubleHolder.cpp 
OBJ			= $(SRC:.cpp=.o)
HEAD		= main.hpp BaseHolder.hpp IntHolder.hpp CharArrayHolder.hpp DoubleHolder.hpp
CC			= clang++ --std=c++14


%.o:	%.cpp
	$(CC) -g -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) random_tree example_tree

fclean: clean
	rm -rf $(NAME)

re: fclean all
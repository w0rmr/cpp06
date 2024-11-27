Target = serializer

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp Serializer.cpp Data.cpp

objects = $(FILES:.cpp=.o)

$(Target): $(objects)
	$(CC) $(FLAGS) -o $(Target) $(objects)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(objects)

fclean: clean
	rm -f $(Target)

re: fclean $(Target)
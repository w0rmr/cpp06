Target = Converter

CC = g++ 

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

FILES = main.cpp ScalarConverter.cpp 

objects = $(FILES:.cpp=.o)

$(Target): $(objects)
	$(CC) $(FLAGS) -o $(Target) $(objects)

make :
	$(CC) $(FLAGS) -o $(Target)  $(FILES)

clean :
	rm -f $(objects)

re : clean make

fclean : clean
	rm -f $(Target)

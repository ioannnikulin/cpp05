CPP = c++
COMPILE_FLAGS = -Wall -Werror -Wextra -pedantic -g -c -std=c++98
LINK_FLAGS =
NAME = Intern

SRCS = \
	main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) $(COMPILE_FLAGS) $^ -o $@

$(NAME): $(OBJS)
	$(CPP) $(LINK_FLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS) *_shrubbery

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean test
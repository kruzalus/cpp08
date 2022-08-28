NAME = 1.out

SRCS = main.cpp Span.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRCS:.cpp=.o)

DEPS := $(patsubst %.cpp,%.d,${SRCS})

-include ${DEPS}

all:$(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $^ -o $@
	rm -f $(DEPS)

%.o: %.cpp Makefile
	c++ $(FLAGS) -MMD -MP -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

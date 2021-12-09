NAME =
CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS_PATH = objs
SRCS = \
	main.cpp Karen.cpp
OBJS_NAME = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

$(OBJS_PATH)/%.o : %.cpp
	mkdir -p $(OBJS_PATH)
	$(CC) $(CPPFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS_PATH)

fclean :
	rm -rf $(NAME) $(OBJS_PATH)
re : fclean all

.PHONY : all clean fclean re

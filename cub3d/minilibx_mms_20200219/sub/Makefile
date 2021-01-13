CC = gcc
FLAGS = -L./ -lmlx -framework OpenGL -framework AppKit -D BUFFER_SIZE=30
SRCS = *.c ../../get_next_line/*.c ../../libft/*.c
LEAK_FLAG = -g -fsanitize=address

all : 
	$(CC) $(FLAGS) $(SRCS)
	./a.out
leak : 
	$(CC) $(LEAK_FLAG) $(FLAGS) $(SRCS)
	./a.out

clean :
	make clean -C ../
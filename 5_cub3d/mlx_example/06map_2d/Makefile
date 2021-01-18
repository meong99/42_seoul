all:
	gcc -D BUFFER_SIZE=30 -L../mlx -lmlx -framework OpenGL -framework AppKit main.c ../../get_next_line/*.c ../../libft/*.c
	./a.out
leak : 
	gcc -g -fsanitize=address -D BUFFER_SIZE=30 -L../mlx -lmlx -framework OpenGL -framework AppKit main.c ../../get_next_line/*.c ../../libft/*.c
	./a.out
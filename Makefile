NAME = fdf

LIBSRC = libft/libft.a
LIBPATH = libft/

OBJ = main.o\
	  file_check.o\
	  draw_file.o\
	  map_create.o\
	  rotation_file.o\
	  init_file.o\
	  helping_file.o
	  
FLAG = -Wall -Werror -Wextra
LIB_EXT = -framework appkit -framework opengl -lmlx

all: $(NAME)

$(NAME): $(LIBSRC) $(OBJ)
		gcc $(FLAG) $(LIB_EXT) $(OBJ) $(LIBSRC) -o $(NAME)

%.o : %.c
		gcc $(FLAG) -c $< -o $@
$(LIBSRC):
		make -C $(LIBPATH)

clean:
		make clean -C $(LIBPATH)
			/bin/rm -f $(OBJ)
fclean: clean
		make fclean -C $(LIBPATH)
			/bin/rm -f $(NAME)
re: fclean all
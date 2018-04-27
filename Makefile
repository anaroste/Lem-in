NAME = lem-in

LIBFT = libft

CC = gcc

FLAGS = -g -fsanitize=address -Wall -Wextra -Werror

SRC_NAME =  main_lemin.c			\
			ft_lemin_read.c			\
			ft_lemin_read_second.c	\
			ft_free_struct.c		\
			ft_verif_error.c		\
			ft_verif_error_second.c	\
			ft_verif_way.c		\
			ft_test_read.c			\
			ft_move_ant.c			\
			ft_algorithme.c			\

SRC = $(addprefix lemin_functions/, $(SRC_NAME))

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)

$(LIBFT) :
	@make -C $(LIBFT)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT)/libft.a -o $(NAME)
	@echo "$(NAME) have been compiled"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(LIBFT)
	@/bin/rm -f $(OBJ)
	@echo "$(NAME) objects have been deleted"

fclean : clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@echo "$(NAME) have been deleted"

re : fclean all

programs : all clean

.PHONY : all clean fclean re libft

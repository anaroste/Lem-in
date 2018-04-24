# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:34:52 by tbleuse           #+#    #+#              #
#    Updated: 2018/03/07 11:03:05 by tbleuse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

FLAGS = -Wall -Wextra -Werror

CONV_NAME	=	ft_atoi.c				\
				ft_itoa.c				\
				ft_itoa_base.c			\
				ft_lltoa.c              \
				ft_ulltoa_base.c        \
				ft_wc_convert.c			\
				ft_wcs_convert.c		\
				ft_conv_utf8.c			\

CHAR_NAME	=	ft_isalnum.c			\
				ft_isalpha.c			\
				ft_isascii.c			\
				ft_isdigit.c			\
				ft_isprint.c			\
				ft_tolower.c			\
				ft_toupper.c			\

MEMORY_NAME =	ft_memalloc.c			\
				ft_memccpy.c			\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memcpy.c				\
				ft_memdel.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_bzero.c				\
				ft_realloc.c			\
				ft_swap.c				\
				ft_gnl.c				\
				ft_addncharbefore.c     \

STR_NAME	=	ft_strcat.c				\
				ft_strchr.c				\
				ft_strclr.c				\
				ft_strcmp.c				\
				ft_strcpy.c				\
				ft_strdel.c				\
				ft_strdup.c				\
				ft_strequ.c				\
				ft_striter.c			\
				ft_striteri.c			\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlen.c				\
				ft_strlen_c.c			\
				ft_strmap.c				\
				ft_strmapi.c			\
				ft_strncat.c			\
				ft_strncmp.c			\
				ft_strncpy.c			\
				ft_strnequ.c			\
				ft_strnew.c				\
				ft_strnstr.c			\
				ft_strrchr.c			\
				ft_strsplit.c			\
				ft_strstr.c				\
				ft_strsub.c				\
				ft_strtrim.c			\
				ft_wcslen.c				\
				ft_strlenwcs.c			\

LIST_NAME	=	ft_lstadd.c				\
				ft_lstdel.c				\
				ft_lstdelone.c			\
				ft_lstiter.c			\
				ft_lstmap.c				\
				ft_lstnew.c				\
				ft_lstpushback.c		\
				ft_lstrev.c				\
				ft_lstsize.c			\

PRINT_NAME	=	ft_putchar.c			\
				ft_putchar_fd.c			\
				ft_putendl.c			\
				ft_putendl_fd.c			\
				ft_putnbr.c				\
				ft_putnbr_fd.c			\
				ft_putnbr_n.c			\
				ft_putstr.c				\
				ft_putstr_fd.c			\
				ft_printnchar.c         \

MATH_NAME	=	ft_bracket.c			\
				ft_sqrt.c				\
				ft_power.c				\
				ft_random.c				\
				ft_sort_int_tab.c		\
				ft_abs.c		\

PRINTF_NAME	=	ft_printf.c				\
				ft_m_count.c            \
				ft_last_char.c          \
				ft_take_infos.c         \
				ft_printf_s.c           \
				ft_printf_di.c          \
				ft_printf_o.c           \
				ft_printf_u.c           \
				ft_printf_p.c           \
				ft_printf_ms.c          \
				ft_printf_md.c          \
				ft_printf_x.c           \
				ft_printf_mx.c          \
				ft_printf_c.c           \
				ft_printf_mc.c          \
				ft_printf_n.c           \
				ft_printf_b.c           \
				ft_printf_momu.c        \
				ft_printf_bouxmx.c      \
				ft_printf_modulo.c      \

CONV_O = $(addprefix conversion/, $(CONV_NAME:.c=.o))
CHAR_O = $(addprefix char/, $(CHAR_NAME:.c=.o))
MEMORY_O = $(addprefix memory/, $(MEMORY_NAME:.c=.o))
STR_O = $(addprefix str/, $(STR_NAME:.c=.o))
LIST_O = $(addprefix list/, $(LIST_NAME:.c=.o))
PRINT_O = $(addprefix print/, $(PRINT_NAME:.c=.o))
MATH_O = $(addprefix math/, $(MATH_NAME:.c=.o))
PRINTF_O = $(addprefix printf/, $(PRINTF_NAME:.c=.o))

POINT_O =	$(CONV_O) $(CHAR_O) $(MEMORY_O) $(STR_O)	\
			$(LIST_O) $(PRINT_O) $(MATH_O) $(PRINTF_O)	\

all : $(NAME)

$(NAME) : $(POINT_O) $(NAME).a

%.a: $(POINT_O)
	@ar rc $(NAME).a $(POINT_O)
	@ranlib $(NAME).a
	@echo "$(NAME) have been compiled"

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean :
	@/bin/rm -f $(POINT_O)
	@echo "$(NAME) objects have been deleted"

fclean : clean
	@/bin/rm -f $(NAME).a
	@echo "$(NAME) have been deleted"

lib : all clean

re : fclean all

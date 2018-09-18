# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 10:56:57 by tasikimu          #+#    #+#              #
#    Updated: 2018/08/10 14:35:51 by tasikimu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
LIB			=	./libft/libft.a
_SRC		=	main.c\
				get_parse_info.c\
				display.c\
				init.c\
				moves.c\
				launch.c\

INC			=	./includes/fdf.h \


SRC			=	$(addprefix srcs/,$(_SRC))
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./libft/ -I./includes/

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@echo "Busy working Miss tasikimu"
	@echo "working..."
	@make -C ./libft/
	@gcc $(CFLAGS)  -lm -L libft/ -lmlx -framework OpenGL -framework AppKit  $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@echo $(NAME) " - compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@make clean -C libft
	@/bin/rm -rf $(OBJ)
	@echo $(NAME) " - Clean all .o files"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo $(NAME) " - Clean executable"

re: fclean all

.PHONY: all, clean, fclean, re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 19:37:53 by tferrieu          #+#    #+#              #
#    Updated: 2019/04/15 22:10:16 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		push_swap

NAME2		=		checker

LIB			=		./libft/libft.a

SRCS		=		./srcs/stack_moveset.c \
					./srcs/stack_tools.c \
					./srcs/stack_sorter.c

SRC1		=		./srcs/push_swap.c

SRC2		=		./srcs/checker.c

OBJS		=		$(patsubst ./srcs/%.c, %.o, $(SRCS))

OBJ1		=		push_swap.o

OBJ2		=		checker.o

FLAGS		=		-Wall -Werror -Wextra


all:		$(NAME)

$(NAME):	$(SRCS) $(SRC1) $(SRC2)
	make -C libft
	gcc $(FLAGS) -c $(SRCS) $(SRC1) $(SRC2)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(OBJ1) $(LIB)
	gcc $(FLAGS) -o $(NAME2) $(OBJS) $(OBJ2) $(LIB)

clean:
	make -C libft clean
	rm -rf $(OBJS)
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)

fclean:		clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf $(NAME2)

re: 		fclean all

.PHONY : all $(NAME1) $(NAME2) clean fclean re

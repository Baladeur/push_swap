# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 19:37:53 by tferrieu          #+#    #+#              #
#    Updated: 2019/04/15 19:49:48 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		=		push_swap

NAME2		=		checker

LIB			=		./libft/libft.a

SRCS		=		./srcs/stack_moveset.c \
					./srcs/stack_tools.c \
					./srcs/stack_sorter.c

OBJS		=		$(patsubst ./srcs/%.c, %o, $(SRCS))

FLAGS		=		-Wall -Werror -Wextra


all:		$(NAME1) $(NAME2)

$(NAME1):	$(SRCS)
	make -C libft
	gcc $(FLAGS) -c $(SRCS)

$(NAME2):	$(SRCS)
	make -C libft
	gcc $(FLAGS) -c $(SRCS) ./srcs/checker.c
	gcc $(FLAGS) -o $(NAME2) $(OBJS) checker.o $(LIB)

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean:
	make -C libft fclean
	rm -rf $(OBJS) $(NAME1) $(NAME2)

re: 		fclean all

.PHONY all $(NAME1) $(NAME2) clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 19:37:53 by tferrieu          #+#    #+#              #
#    Updated: 2019/04/28 19:31:55 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		=		push_swap

NAME2		=		checker

LIB			=		./libft/libft.a

SRCS		=		./srcs/stack_moveset.c \
					./srcs/stack_tools_1.c \
					./srcs/stack_tools_2.c \
					./srcs/stack_tools_3.c \
					./srcs/stack_sorter.c

SRC1		=		./srcs/push_swap.c \
					./srcs/result_cleaner.c \
					./srcs/safer_cleaner.c \
					./srcs/selection_sort.c \
					./srcs/gnome_sort.c \
					./srcs/bubble_sort.c \
					./srcs/quicksort.c \
					./srcs/partition_tools.c \
					./srcs/insertion_sort.c

SRC2		=		./srcs/checker.c

OBJS		=		$(patsubst ./srcs/%.c, %.o, $(SRCS))

OBJ1		=		$(patsubst ./srcs/%.c, %.o, $(SRC1))

OBJ2		=		$(patsubst ./srcs/%.c, %.o, $(SRC2))

FLAGS		=		-Wall -Werror -Wextra


all:		$(NAME1) $(NAME2)

$(NAME1):	$(SRCS) $(SRC1)
	make -C libft
	gcc $(FLAGS) -c $(SRCS) $(SRC1)
	gcc $(FLAGS) -o $(NAME1) $(OBJS) $(OBJ1) $(LIB)

$(NAME2):	$(SRCS) $(SRC2)
	make -C libft
	gcc $(FLAGS) -c $(SRCS) $(SRC2)
	gcc $(FLAGS) -o $(NAME2) $(OBJS) $(OBJ2) $(LIB)

clean:
	make -C libft clean
	rm -rf $(OBJS)
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)

fclean:		clean
	make -C libft fclean
	rm -rf $(NAME1)
	rm -rf $(NAME2)

re: 		fclean all

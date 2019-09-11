# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 17:33:14 by tferrieu          #+#    #+#              #
#    Updated: 2019/07/13 17:33:15 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

SRC		=	push_swap.c \
			result_cleaner.c \
			safer_cleaner.c \
			selection_sort.c \
			gnome_sort.c \
			bubble_sort.c \
			quicksort.c \
			partition_tools.c \
			insertion_sort.c

OBJ		=	$(SRC:.c=.o)

OBJS	=	../srcs/stack_moveset.c \
			../srcs/stack_tools_1.c \
			../srcs/stack_tools_2.c \
			../srcs/stack_tools_3.c \
			../srcs/stack_sorter.c

NAME	=	../push_swap

CFLAGS	=	-Wall -Werror -Wextra

all :		$(NAME)

$(NAME) :	$(OBJ) $(OBJS) ../includes/push_swap.h
			$(MAKE) -C ../libft
			$(MAKE) -C ../srcs
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) ../libft/libft.a ../srcs/push_swap.a

clean :
			$(MAKE) -C ../libft clean
			$(MAKE) -C ../srcs clean
			@rm -Rf $(OBJ)

fclean :	clean
			$(MAKE) -C ../libft fclean
			$(MAKE) -C ../srcs fclean
			@rm -Rf $(NAME)

re :		fclean all

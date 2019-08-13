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

NAME	=	../push_swap

CFLAGS	=	-Wall -Werror -Wextra

all :		$(NAME)

$(NAME) :	$(OBJ) ../includes/push_swap.h
			make -C ../libft
			make -C ../srcs
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) ../libft/libft.a ../srcs/push_swap.a

clean :
			make -C ../libft clean
			make -C ../srcs clean
			@rm -Rf $(OBJ)

fclean :	clean
			make -C ../libft fclean
			make -C ../srcs fclean
			@rm -Rf $(NAME)

re :		fclean all

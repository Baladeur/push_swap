# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 17:33:01 by tferrieu          #+#    #+#              #
#    Updated: 2019/07/13 17:33:02 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

AR		=	ar rc

SRC		=	stack_moveset.c \
			stack_tools_1.c \
			stack_tools_2.c \
			stack_tools_3.c \
			stack_sorter.c

OBJ		=	$(SRC:.c=.o)

NAME	=	push_swap.a

CFLAGS	=	-Wall -Werror -Wextra

all :		$(NAME)

$(NAME) :	$(OBJ) ../includes/push_swap.h
			$(AR) $(NAME) $(OBJ)

clean :
			/bin/rm -Rf $(OBJ)

fclean :	clean
			/bin/rm -Rf $(NAME)

re :		fclean all

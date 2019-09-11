# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 17:33:07 by tferrieu          #+#    #+#              #
#    Updated: 2019/07/13 17:33:08 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

SRC		=	checker.c

OBJ		=	$(SRC:.c=.o)

OBJS	=	../srcs/stack_moveset.c \
			../srcs/stack_tools_1.c \
			../srcs/stack_tools_2.c \
			../srcs/stack_tools_3.c \
			../srcs/stack_sorter.c

NAME	=	../checker

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

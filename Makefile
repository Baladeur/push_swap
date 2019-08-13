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

all:
	make -C srcs\ checker
	make -C srcs\ push_swap

$(NAME1):
	make -C srcs\ push_swap

$(NAME2):
	make -C srcs\ checker

clean:
	@make -C srcs\ checker clean
	@make -C srcs\ push_swap clean

fclean:		clean
	@make -C srcs\ checker fclean
	@make -C srcs\ push_swap fclean

re: 		fclean all

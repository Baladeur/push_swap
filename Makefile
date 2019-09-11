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

SRC		=	srcs/stack_moveset.c \
			srcs/stack_tools_1.c \
			srcs/stack_tools_2.c \
			srcs/stack_tools_3.c \
			srcs/stack_sorter.c

SRC2	=	srcs\ checker/checker.c

SRC1	=	srcs\ push_swap/push_swap.c \
			srcs\ push_swap/result_cleaner.c \
			srcs\ push_swap/safer_cleaner.c \
			srcs\ push_swap/selection_sort.c \
			srcs\ push_swap/gnome_sort.c \
			srcs\ push_swap/bubble_sort.c \
			srcs\ push_swap/quicksort.c \
			srcs\ push_swap/partition_tools.c \
			srcs\ push_swap/insertion_sort.c

all: $(NAME1) $(NAME2)

$(NAME1): $(SRC) $(SRC1)
	$(MAKE) -C srcs\ push_swap

$(NAME2): $(SRC) $(SRC2)
	$(MAKE) -C srcs\ checker

clean:
	@$(MAKE) -C srcs\ checker clean
	@$(MAKE) -C srcs\ push_swap clean

fclean:		clean
	@$(MAKE) -C srcs\ checker fclean
	@$(MAKE) -C srcs\ push_swap fclean

re: 		fclean all

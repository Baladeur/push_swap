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

LIBFT	=	libft/libft.a

NAME1	=	checker

NAME2	=	push_swap

SHARED	=	srcs/push_swap.a

PROG1	=	check

PROG2	=	push

SRCLIB	=	libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_itoa.c \
			libft/ft_lstadd.c \
			libft/ft_lstdel.c \
			libft/ft_lstdelone.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \
			libft/ft_lstnew.c \
			libft/ft_memalloc.c \
			libft/ft_memccpy.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memdel.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_pow.c \
			libft/ft_putchar.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr.c \
			libft/ft_putstr_fd.c \
			libft/ft_strcat.c \
			libft/ft_strchr.c \
			libft/ft_strclr.c \
			libft/ft_strcmp.c \
			libft/ft_strcpy.c \
			libft/ft_strdel.c \
			libft/ft_strdup.c \
			libft/ft_strequ.c \
			libft/ft_striter.c \
			libft/ft_striteri.c \
			libft/ft_strjoin.c \
			libft/ft_strlcat.c \
			libft/ft_strlen.c \
			libft/ft_strmap.c \
			libft/ft_strmapi.c \
			libft/ft_strncat.c \
			libft/ft_strncmp.c \
			libft/ft_strncpy.c \
			libft/ft_strnequ.c \
			libft/ft_strnew.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_strsplit.c \
			libft/ft_strstr.c \
			libft/ft_strsub.c \
			libft/ft_strtrim.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/ft_splitcharset.c \
			libft/ft_root.c \
			libft/ft_table_to_list.c \
			libft/ft_putlst.c \
			libft/ft_strjoin_free.c \
			libft/get_next_line.c \
			libft/ft_itobase.c \
			libft/ft_strmake.c \
			libft/ft_strset.c \
			libft/ft_strnset.c \
			libft/ft_strndup.c \
			libft/biggest_int.c \
			libft/ft_getpow.c \
			libft/ft_getbase.c \
			libft/ft_abs.c \
			libft/ft_printf.c \
			libft/parsing.c \
			libft/convert_cs.c \
			libft/convert_float.c \
			libft/convert_int.c \
			libft/convert_oux.c \
			libft/convert_p.c \
			libft/scanning.c

SRC		=	srcs/stack_moveset.c \
			srcs/stack_tools_1.c \
			srcs/stack_tools_2.c \
			srcs/stack_tools_3.c \
			srcs/stack_sorter.c

SRC1	=	srcs-checker/checker.c

SRC2	=	srcs-push_swap/push_swap.c \
			srcs-push_swap/result_cleaner.c \
			srcs-push_swap/safer_cleaner.c \
			srcs-push_swap/selection_sort.c \
			srcs-push_swap/gnome_sort.c \
			srcs-push_swap/bubble_sort.c \
			srcs-push_swap/quicksort.c \
			srcs-push_swap/partition_tools.c \
			srcs-push_swap/insertion_sort.c

OBJLIB	=	$(SRCLIB:.c=.o)

OBJ		=	$(SRC:.c=.o)

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:		$(LIBFT) $(SHARED) $(NAME1) $(NAME2)

$(LIBFT):	$(OBJLIB)
	@echo "Updating libft.a"
	@ar rc $(LIBFT) $(OBJLIB)

$(SHARED):	$(OBJLIB) $(OBJ)
	@echo "Updating push_swap.a"
	@ar rc $(SHARED) $(OBJ)

$(NAME1):	$(LIBFT) $(SHARED) $(OBJLIB) $(OBJ) $(OBJ1)
	@echo "Updating checker"
	@$(CC) $(CFLAGS) $(LIBFT) $(SHARED) $(OBJ1) -o $(NAME1)

$(NAME2):	$(LIBFT) $(SHARED) $(OBJLIB) $(OBJ) $(OBJ2)
	@echo "Updating push_swap"
	@$(CC) $(CFLAGS) $(LIBFT) $(SHARED) $(OBJ2) -o $(NAME2)

clean:
	@/bin/rm -Rf $(OBJLIB)
	@/bin/rm -Rf $(OBJ)
	@/bin/rm -Rf $(OBJ1)
	@/bin/rm -Rf $(OBJ2)

fclean:		clean
	@/bin/rm -Rf $(LIBFT)
	@/bin/rm -Rf $(SHARED)
	@/bin/rm -Rf $(NAME1)
	@/bin/rm -Rf $(NAME2)

re: 		fclean all

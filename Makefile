# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apopinea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:05:55 by apopinea          #+#    #+#              #
#    Updated: 2016/11/17 10:09:57 by jyakdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, $(LIBFT_A), $(NAME_PROG)

.SUFFIXES:

NAME = fillit
LIBFT_A = ./libft/libft.a
DIR_LIBFT = ./libft/
DIR_H_LIBFT = ./libft
DIR_M = ./srcs/
DIR_H = ./includes
SRCM = main.c ft_verif_tetrinos_f.c ft_resolvator.c ft_strtolst.c ft_efface_t.c \
		ft_print_grid.c ft_place_t.c ft_lst.c ft_validate.c ft_tetricut.c \
		ft_creat_info.c ft_strchange.c ft_del_final.c
SROM = $(SRCM:.c=.o)
FULL_PATH = $(addprefix $(DIR_M),$(SRCM))
OPT = -I
FLAG = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(SROM) $(LIBFT_A)
	$(CC) $(FLAG) -o $@ $^

$(SROM): $(FULL_PATH)
	$(CC) $(FLAG) -c $^ $(OPT)$(DIR_H_LIBFT) $(OPT)$(DIR_H)

$(LIBFT_A):
	cd $(DIR_LIBFT) && $(MAKE)

clean:
	rm -f $(SROM)
	cd $(DIR_LIBFT) && $(MAKE) $@

fclean: clean
	rm -f $(NAME)
	cd $(DIR_LIBFT) && $(MAKE) $@

re: fclean all

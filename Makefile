# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/05 16:41:49 by hkang             #+#    #+#              #
#    Updated: 2018/02/05 16:41:55 by hkang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re
NAME = lem-in
NOC=\033[36m
OKC=\033[36m
WAC=\033[36m
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
LIB_PATH = ./print/
LIB_NAME = libftprintf.a
SRC_NAME = get_next_line.c\
lem_add_data.c\
lem_add_step.c\
lem_add_trace.c\
lem_check.c\
lem_display.c\
lem_find_trace.c\
lem_free.c\
lem_init.c\
lem_read.c\
main.c\

all:
	make re -C $(LIB_PATH)
	$(CC) $(CC_FLAGS) $(SRC_NAME) $(LIB_PATH)$(LIB_NAME) -o $(NAME)

clean:
	make clean -C $(LIB_PATH)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2019/01/28 19:06:11 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFTIDIR) -g

IDIR = includes
SDIR = srcs
ODIR = obj
LIBFTDIR = libft
LIBFTIDIR = $(LIBFTDIR)/includes
LIBFT = libft.a

# Output file name
NAME = lem_in

DEPS = $(IDIR)/lem_in.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Source files
_SRC =	main.c \
		room.c \
		lem_in.c \
		parsing.c \
		solve.c \
		print_solution.c \
		utils.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTDIR)/$(LIBFT)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFTDIR)/$(LIBFT)

# $(LIBFTDIR)/$(LIBFT):
# 	make -C $(LIBFTDIR)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re:	fclean all

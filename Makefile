# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2019/01/29 15:20:40 by juazouz          ###   ########.fr        #
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
TEST_PRINT_SOL = lem_in_solution_print_test

DEPS = $(IDIR)/lem_in.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Source files
_SRC =	room.c \
		lem_in.c \
		parsing.c \
		solve.c \
		solution/solution_print.c \
		solution/solution.c \
		utils.c

.PHONY: all clean fclean re

all: $(NAME) $(TEST_PRINT_SOL)

$(TEST_PRINT_SOL): $(OBJ) $(LIBFTDIR)/$(LIBFT) $(SDIR)/test/test_print.c
	$(CC) $(CFLAGS) $^ -o $@

$(NAME): $(OBJ) $(LIBFTDIR)/$(LIBFT) $(SDIR)/main.c
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFTDIR)/$(LIBFT):
	make -C $(LIBFTDIR)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST_PRINT_SOL)
	make -C $(LIBFTDIR) fclean

re:	fclean all

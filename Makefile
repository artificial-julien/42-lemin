# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2019/02/05 16:13:24 by agoulas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFTIDIR) -g -fsanitize=address

IDIR = includes
SDIR = srcs
ODIR = obj
LIBFTDIR = libft
LIBFTIDIR = $(LIBFTDIR)/includes
LIBFT = libft.a

# Output file name
NAME = lem_in
TEST_PRINT_SOL = lem_in_solution_print_test
TEST_ROUTE = lem_route_test
TEST_GROUP = lem_test_group

DEPS = $(IDIR)/lem_in.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC)) \
	  $(LIBFTDIR)/$(LIBFT)

SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Source files
_SRC = lem_in.c \
	   parse.c \
	   parsing.c \
	   route_creator/create_nodes_weights.c \
	   solver/solve.c \
	   solver/build_solution.c \
	   solver/select_best_group.c \
	   solution/solution_print.c \
	   solution/solution.c \
	   utils.c \
	   glist/ft_glstadd.c \
	   glist/ft_glstadd_last.c \
	   glist/ft_glstdel.c \
	   glist/ft_glstdelone.c \
	   glist/ft_glstiter.c \
	   glist/ft_glstmap.c \
	   glist/ft_glstnew.c \
	   groups.c \
	   group.c \
	   route.c \
	   routes.c \
	   room.c \
	   bitmap.c \
	   route_creator/create_nodes_weights.c

.PHONY: all clean fclean re

all: $(TEST_PRINT_SOL)  $(TEST_ROUTE)  $(TEST_GROUP) $(NAME)

$(TEST_PRINT_SOL): $(OBJ) $(SDIR)/test/test_print.c
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_ROUTE): $(OBJ) $(SDIR)/test/test_routes.c
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_GROUP): $(OBJ) $(SDIR)/test/test_group.c
	$(CC) $(CFLAGS) $^ -o $@

$(NAME): $(OBJ) $(SDIR)/main.c
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

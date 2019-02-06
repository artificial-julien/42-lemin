# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2019/02/06 19:48:35 by juazouz          ###   ########.fr        #
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
TEST_PRINT_SOL = lem_in_test_solution_print
TEST_ROUTE = lem_in_test_route_creation
TEST_GROUP = lem_in_test_group_creation

DEPS = $(IDIR)/lem_in.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC)) \
	  $(LIBFTDIR)/$(LIBFT)

SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Source files
_SRC =	room/room.c \
		lem_in.c \
		parser/parse.c \
		parser/parse_core.c \
		route_creator/create_routes.c \
		solver/solve.c \
		solver/build_solution.c \
		solver/select_best_group.c \
		solver/rounds_for_group.c \
		solver/sort_routes.c \
		solution/solution_print.c \
		solution/solution.c \
		utils/utils.c \
		utils/utils_route.c \
		glist/ft_glstadd.c \
		glist/ft_glstadd_last.c \
		glist/ft_glstdel.c \
		glist/ft_glstdelone.c \
		glist/ft_glstiter.c \
		glist/ft_glstmap.c \
		glist/ft_glstnew.c \
		glist/ft_glstcpy.c \
		glist/ft_glsthascontent.c \
		glist/ft_glstsort.c \
		glist/ft_glstlen.c \
		group_creator/create_groups.c \
		group/group.c \
		route/route.c \
		route/route_create_conflicts_map.c \
		bitmap/bitmap.c \
		test/dummy_maps.c

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

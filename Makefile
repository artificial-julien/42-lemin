# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2019/03/05 19:17:03 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

# Laisser en mode debug avant la version finale
CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFTIDIR) -g -D DEBUG #-fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFTIDIR) -O3 -g

IDIR = includes
SDIR = srcs
ODIR = obj
LIBFTDIR = libft
LIBFTIDIR = $(LIBFTDIR)/includes
LIBFT = libft.a

NAME = lem_in

DEPS = $(IDIR)/lem_in.h Makefile

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC)) \
	  $(LIBFTDIR)/$(LIBFT)

SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

# Source files
_SRC =	room/room.c \
		room/room_create_links.c \
		lem_in.c \
		bft/bft_run.c \
		bft/route_tree.c \
		parser/parse.c \
		parser/parse_core.c \
		solver/solve.c \
		solver/solve_utils.c \
		solver/rebuild_routes.c \
		solution/solution_print.c \
		solution/solution.c \
		solution_builder/build_solution.c \
		utils/utils_array.c \
		utils/utils.c \
		utils/utils_array.c \
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
		glist/ft_glstinsert.c \
		glist/ft_glstrev.c \
		group/ants_distribution.c \
		group/group.c \
		group/group_build.c \
		route/route.c \
		route/route_print.c \
		parser/parser_opt.c \
		parser/parse_optimizer.c \
		parser/parse_opt_print.c \
		parser/parse_opt_print_help.c \
		parser/parse_utils.c \
		display.c \
		main.c


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
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

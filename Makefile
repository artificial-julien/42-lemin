# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2019/03/19 13:43:40 by agoulas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

all: $(NAME)

NAME		= lem-in

SOURCES		+= main.c \
			lem_in.c \
			display.c
SOURCES		+= $(addprefix bft/, \
			run_bft.c \
			run_bft_core.c \
			run_bft_utils.c tree.c \
			tree_utils.c)
SOURCES		+= $(addprefix parser/, \
			parse.c \
			parse_core.c \
			parse_opt_print.c \
			parse_opt_print_help.c \
			parse_optimizer.c \
			parse_utils.c \
			parser_opt.c )
SOURCES		+= $(addprefix glist/, \
			ft_glstadd.c\
			ft_glstcpy.c \
			ft_glstdel.c \
			ft_glstdelone.c \
			ft_glsthascontent.c \
			ft_glstlen.c \
			ft_glstnew.c \
			ft_glstrev.c \
			ft_glstsort.c )
SOURCES		+= $(addprefix group/, \
			ants_distribution.c \
			group.c \
			group_build.c)
SOURCES		+= $(addprefix room/, \
			room.c \
			room_create_links.c )
SOURCES		+= $(addprefix route/, \
			route.c \
			route_print.c)
SOURCES		+= $(addprefix solution/, \
			solution.c \
			solution_print.c \
			solution_round.c )
SOURCES		+= $(addprefix solution_builder/, \
			build_solution.c )
SOURCES		+= $(addprefix solver/, \
			rebuild_routes.c \
			solve.c \
			solve_utils.c)
SOURCES		+= $(addprefix utils/, \
			utils.c \
			utils_array.c)
SRCS_DR		= srcs
SRCS		= $(addprefix $(SRCS_DR)/, $(SOURCES))

CC			= clang
CFLAGS		= -Wall -Werror -Wextra -I libft/includes  -I $(INC_DR)

OBJS_DR		= objs
OBJS		= $(SRCS:$(SRCS_DR)/%.c=$(OBJS_DR)/%.o)

INC_DR = includes

LIBFT_INC_DR	= libft\includes
LIBFT_DR	= libft
LIBFT		= $(LIBFT_DR)/libft.a
LIBFT_FLAG	= -L$(LIBFT_DR) -lft

RESET		= \e[0m
ITALIC		= \e[3m
RED			= \e[31m
GREEN		= \e[32m
YELLOW		= \e[33m
BLUE		= \e[34m
MAGENTA		= \e[35m

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS_DR) $(OBJS) $(CM_OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) $(CM_OBJS) $(LIBFT_FLAG) -o $@
	@ printf "$(GREEN)%-42s$(RESET)\n" "Build $@ binary"

$(LIBFT) :
	@ printf "$(MAGENTA)%-42s$(RESET)\r" "Compiling $@"
	@ make -sC $(LIBFT_DR)
	@ printf "$(MAGENTA)%-42s$(RESET)\n" "Build $@ library"

$(OBJS_DR) :
	@ mkdir -p $(OBJS_DR) $(OBJS_DR)/bft $(OBJS_DR)/glist $(OBJS_DR)/group $(OBJS_DR)/parser $(OBJS_DR)/room $(OBJS_DR)/route $(OBJS_DR)/solution $(OBJS_DR)/solution_builder $(OBJS_DR)/solver $(OBJS_DR)/utils

$(OBJS_DR)/%.o : $(SRCS_DR)/%.c
	@ $(CC) $(CFLAGS) -o $@ -c $<
	@ printf "$(ITALIC)$(BLUE)%-42.42s$(RESET)\r" "Compiled $@"

clean :
	@ make -sC $(LIBFT_DR) clean
	@ rm -rf $(OBJS_DR)
	@ printf "$(YELLOW)%-42s$(RESET)\n" "Removed $(NAME) $(OBJS_DR)"

fclean : clean
	@ make -sC $(LIBFT_DR) fclean
	@ rm -f $(NAME)
	@ printf "$(YELLOW)%-42s$(RESET)\n" "Removed $(NAME) binary"

re : fclean all

norme :
	@ norminette `find . -type f \( -name *.c -o -name *.h \)` \
	| if ! grep Error -B 1 --color; then printf "$(GREEN)NORME OK$(RESET)\n"; fi

.PHONY: all clean fclean re norme

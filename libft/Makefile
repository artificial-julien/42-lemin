# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/12/28 18:49:22 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -g

NAME = libft.a

DEPS =	$(IDIR)/libft.h \
		$(IDIR)/ft_printf.h \
		$(IDIR)/ft_printf_types.h

SDIR = srcs
IDIR = includes
ODIR = obj

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(SRC))
SRC =	$(_SRC) \
		$(addprefix output/ft_printf/,$(_SRC_FTFPRINTF))

_SRC =	./char/ft_isalnum.c \
		./char/ft_isalpha.c \
		./char/ft_isascii.c \
		./char/ft_isdigit.c \
		./char/ft_islower.c \
		./char/ft_isprint.c \
		./char/ft_isspace.c \
		./char/ft_isupper.c \
		./char/ft_tolower.c \
		./char/ft_toupper.c \
		./linq/ft_all.c \
		./linq/ft_any.c \
		./linq/ft_atoi.c \
		./linq/ft_foreach.c \
		./linq/ft_max.c \
		./linq/ft_min.c \
		./list/ft_lstadd.c \
		./list/ft_lstdel.c \
		./list/ft_lstdelone.c \
		./list/ft_lstiter.c \
		./list/ft_lstmap.c \
		./list/ft_lstnew.c \
		./memory/ft_bzero.c \
		./memory/ft_memalloc.c \
		./memory/ft_memccpy.c \
		./memory/ft_memchr.c \
		./memory/ft_memcmp.c \
		./memory/ft_memcpy.c \
		./memory/ft_memdel.c \
		./memory/ft_memmove.c \
		./memory/ft_memset.c \
		./output/ft_putchar.c \
		./output/ft_putchar_fd.c \
		./output/ft_putendl.c \
		./output/ft_putendl_fd.c \
		./output/ft_putnbr.c \
		./output/ft_putnbr_fd.c \
		./output/ft_putstr.c \
		./output/ft_putstr_fd.c \
		./string/ft_itoa.c \
		./string/ft_strcat.c \
		./string/ft_strchr.c \
		./string/ft_strclr.c \
		./string/ft_strcmp.c \
		./string/ft_strcpy.c \
		./string/ft_strdel.c \
		./string/ft_strdup.c \
		./string/ft_strequ.c \
		./string/ft_striter.c \
		./string/ft_striteri.c \
		./string/ft_strjoin.c \
		./string/ft_strlcat.c \
		./string/ft_strlen.c \
		./string/ft_strmap.c \
		./string/ft_strmapi.c \
		./string/ft_strncat.c \
		./string/ft_strncmp.c \
		./string/ft_strncpy.c \
		./string/ft_strnequ.c \
		./string/ft_strnew.c \
		./string/ft_strnstr.c \
		./string/ft_strrchr.c \
		./string/ft_strsplit.c \
		./string/ft_strstr.c \
		./string/ft_strsub.c \
		./string/ft_strtrim.c \
		./input/get_next_line.c \
		./math/ft_powf.c \
		./math/ft_abs.c

_SRC_FTFPRINTF = \
				./core/ft_fprintf.c \
				./core/print_argument.c \
				./parse/parse.c \
				./parse/parse_flags.c \
				./parse/parse_length.c \
				./parse/parse_number.c \
				./parse/parse_precision.c \
				./parse/parse_specifier.c \
				./parse/parse_width.c \
				./types/print_char.c \
				./types/print_float.c \
				./types/print_hex.c \
				./types/print_hexup.c \
				./types/print_int.c \
				./types/print_octal.c \
				./types/print_str.c \
				./types/print_uint.c \
				./types/print_percent.c \
				./types/print_ptr.c \
				./utils/ft_putnbr_base.c \
				./utils/ft_putnstr.c \
				./utils/print_number_generic.c \
				./utils/print_padding.c \
				./utils/print_prepound_notnull.c \
				./utils/value_is_zero.c \
				./output/out_init.c \
				./output/out_putchar_len.c \
				./output/out_putchar.c \
				./output/out_fill.c \
				./args/read_argument.c

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

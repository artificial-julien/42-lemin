/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:07:02 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 12:04:32 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include <unistd.h>

typedef struct s_formatinfo		t_formatinfo;
typedef enum e_specifier		t_specifier;
typedef enum e_length			t_length;
typedef struct s_output			t_output;

typedef	unsigned char			t_u8;
typedef	unsigned short			t_u16;
typedef	unsigned int			t_u32;
typedef	unsigned long long		t_u64;

typedef	char					t_8;
typedef	short					t_16;
typedef	int						t_32;
typedef	long long				t_64;

typedef char					t_s8;
typedef short					t_s16;
typedef int						t_s32;
typedef	long					t_s64;
typedef float					t_f32;
typedef double					t_f64;

# define SPEC_COUNT 11

enum							e_specifier
{
	spec_none,
	spec_int,
	spec_uint,
	spec_octal,
	spec_hex,
	spec_hexup,
	spec_float,
	spec_str,
	spec_char,
	spec_percent,
	spec_ptr,
};

enum							e_length
{
	none,
	len_char,
	len_short,
	len_long,
	len_llong,
	len_ptr,
};

struct							s_formatinfo
{
	int			precision;
	int			width;
	t_length	length;
	t_specifier	specifier;
	char		flags;
};

struct							s_output
{
	int		fd;
	size_t	size;
	char	*buf;
};

#endif

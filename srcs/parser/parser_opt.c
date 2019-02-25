/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/22 13:51:08 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** init opt of print.
*/

void	init_opt(t_lem_in *lem_in)
{
	lem_in->opt.debug = false;
	lem_in->opt.print_groups = false;
	lem_in->opt.print_help = false;
	lem_in->opt.print_time = false;
}

/*
** parsing of the args of lem_in
*/

void	parse_arg_sym(t_lem_in *lem_in, char *s)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (s[i] == 'd')
			lem_in->opt.debug = true;
		else if (s[i] == 'h')
			lem_in->opt.print_help = true;
		else if (s[i] == 'r')
			lem_in->opt.print_room = true;
		else if (s[i] == 'g')
			lem_in->opt.print_groups = true;
		else if (s[i] == 't')
			lem_in->opt.print_time = true;
		else
			print_unknow(s);
		i++;
	}
}

/*
** parsing of the args of lem_in
*/

void	parse_arg(char *s, t_lem_in *lem_in)
{
	if (s[0] != '-')
		print_unknow(s);
	else
	{
		if (ft_strequ("--debug", s))
			lem_in->opt.debug = true;
		else if (ft_strequ("--help", s))
			lem_in->opt.print_help = true;
		else if (ft_strequ("--roomsinfo", s))
			lem_in->opt.print_room = true;
		else if (ft_strequ("--groups", s))
			lem_in->opt.print_groups = true;
		else if (ft_strequ("--time", s))
			lem_in->opt.print_time = true;
		else
			parse_arg_sym(lem_in, s);
	}
}

/*
**	Parse every string find a the call of lem_in
*/

void	parse_opt(t_lem_in *lem_in, int ac, char **av)
{
	int i;

	i = 1;
	init_opt(lem_in);
	if (ac > 1)
	{
		while (av[i] != NULL && i < ac)
		{
			parse_arg(av[i], lem_in);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/15 13:14:50 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_opt(t_lem_in *lem_in)
{
	lem_in->opt.debug = false;
	lem_in->opt.print_room = false;
	lem_in->opt.print_groups = false;
	lem_in->opt.print_help = false;
}

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
		else if (s[i] == 'R')
			lem_in->opt.print_route = true;
		else
			print_unknow(s);
		i++;
	}
}

/*
**	Parses a single argument.
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
		else if (ft_strequ("--rooms", s))
			lem_in->opt.print_room = true;
		else if (ft_strequ("--groups", s))
			lem_in->opt.print_groups = true;
		else if (ft_strequ("--route", s))
			lem_in->opt.print_route = true;
		else
			parse_arg_sym(lem_in, s);
	}
}

/*
**	Parses the command line options.
*/

void	parse_opt(t_lem_in *lem_in, int ac, char **av)
{
	int i;

	i = 1;
	ft_memset(&lem_in->opt, 0, sizeof(lem_in->opt));
	while (av[i] != NULL && i < ac)
	{
		parse_arg(av[i], lem_in);
		i++;
	}
}

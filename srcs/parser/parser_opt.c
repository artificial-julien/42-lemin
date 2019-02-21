/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/15 16:51:45 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** init opt of print.
*/

void	init_opt(t_lem_in *lem_in)
{
	lem_in->opt.print_groups = false;
	lem_in->opt.print_routes = false;
	lem_in->opt.print_help = false;
}

/*
** parsing of the args of lem_in
*/

void	parse_arg(char *s, t_lem_in *lem_in)
{
	if (s)
	{
		if (s[0] == '-')
		{
			if (ft_strequ("-debug", s) || ft_strequ("-d", s))
				lem_in->opt.debug = true;
			else if (ft_strequ("-help", s) || ft_strequ("-h", s))
				lem_in->opt.print_help = true;
			else if (ft_strequ("-rooms", s) || ft_strequ("-rs", s))
				lem_in->opt.print_room = true;
			else if (ft_strequ("-routes", s) || ft_strequ("-rts", s))
				lem_in->opt.print_routes = true;
			else if (ft_strequ("-groups", s) || ft_strequ("-grs", s))
				lem_in->opt.print_groups = true;
			else
			{
				print_unknow(s);
			}
		}
		else
		{
			print_unknow(s);
		}
	}
}

/*
**	print message error of flags.
*/

void	print_unknow(char *s)
{
	ft_fprintf(2, " ____________________________________");
	ft_fprintf(2, "____________________________________\n");
	ft_fprintf(2, "|                                    ");
	ft_fprintf(2, "                                    |\n\n");
	ft_fprintf(2, "	Error arg : '%s' is not a commandgit  of lem_in.\n\n", s);
	printf_help();
	ft_fprintf(2, "\n");
	ft_fprintf(2, "|___________________________________");
	ft_fprintf(2, "____________________________________|\n\n");
	lem_in_die();
}

/*
** Print manual of the option of lem_in
*/

void	printf_help(void)
{
	ft_fprintf(2, "	 ______________________________________________\n");
	ft_fprintf(2, "	| HELP                                        |\n");
	ft_fprintf(2, "	|  Usage: lem_in [-h,rs,rts,grs}              |\n");
	ft_fprintf(2, "	|    -help,-h:  Show help.                    |\n");
	ft_fprintf(2, "	|    -rms,-rooms: print rooms of the graph.   |\n");
	ft_fprintf(2, "	|    -rts,-routes: print the routes.          |\n");
	ft_fprintf(2, "	|    -grs,-groups: print all group of routes. |\n");
	ft_fprintf(2, "	|    -d,-debug: print all for debug.          |\n");
	ft_fprintf(2, "	|   only on stderr (2)                        |\n");
	ft_fprintf(2, "	|_____________________________________________|\n");
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
		while (av[i] != NULL && i <= ac + 1)
		{
			parse_arg(av[i], lem_in);
			i++;
		}
	}
}

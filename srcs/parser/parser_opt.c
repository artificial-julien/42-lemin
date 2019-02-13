/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:41:27 by agoulas           #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void	init_opt(t_lem_in *lem_in)
{
	lem_in->opt.print_groups = false;
	lem_in->opt.print_routes = false;
	lem_in->opt.print_help = false;
}


void	parse_arg(char *s, t_lem_in *lem_in)
{
	if (s)
	{
		if (s[0] == '-')
		{
			if (ft_strequ("-help", s) || ft_strequ("-h", s))
				lem_in->opt.print_help = false;
			else if (ft_strequ("-r", s))
				lem_in->opt.print_routes = false;
			else if (ft_strequ("-g", s))
				lem_in->opt.print_groups = false;
			else
			{
				ft_printf("/************************************/\n");
				ft_printf("n %s is not a unknow commande .\n");
				ft_printf("for mor help: launch lem_in -help\n");
				ft_printf("/************************************/\n");
				lem_in_die();
			}
		}
		else
		{
			/* test if fichier or other thing */
		}

	}

}

void	printf_help(void)
{
	ft_printf("/********** HELP **********/\n");
	ft_printf("	Usage: lem_in [-hrg] \n");
	ft_printf("		-help,-h:  Show help.\n");
	ft_printf("		-r: print all the routes used and saved in the resolution.\n");
	ft_printf("		-g: print all group of route find in the algorythme\n");
	ft_printf("/*************************/\n");
	lem_in_die();
}

void	parse_opt(t_lem_in *lem_in, int ac, char **av)
{
	int i;

	i = 1;
	init_opt(lem_in);
	if (ac > 1)
	{
			while (av[i] != NULL)
			{
				parse_arg(av[i], lem_in);
				i++;
			}
	}
}

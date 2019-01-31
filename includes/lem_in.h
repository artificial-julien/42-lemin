/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/31 17:06:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**	Includes.
*/

# include "libft.h"

/*
**	Defines.
*/

/*
**	Types.
*/

typedef struct s_glist		t_glist;
typedef	struct s_point		t_point;
typedef	struct s_lem_in		t_lem_in;
typedef	struct s_room		t_room;
typedef	enum e_roomtype		t_roomtype;
typedef	struct s_move		t_move;
typedef struct s_round		t_round;
typedef struct s_solution	t_solution;
typedef struct s_route		t_route;
typedef struct s_group		t_group;

/*
**	Project generic list.
*/

struct	s_glist
{
	union
	{
		void		*content;
		t_room		*room;
		t_route		*route;
		t_group		*group;
		t_round		*round;
		t_move		*move;
		t_glist		*glist;
	};
	size_t			content_size;
	struct s_glist	*next;
};

struct	s_point
{
	int	x;
	int	y;
};

enum	e_roomtype
{
	standard,
	start,
	end,
};

struct	s_lem_in
{
	int		total_ants;
	t_room	*start;
	t_room	*end;
	t_list	*rooms;
};

struct	s_room
{
	char		*name;
	t_roomtype	type;
	t_point		pos;
	int			ants;
	t_list		*links;
};

/*
**	Final result.
**	Contains a list of rounds.
*/

struct	s_solution
{
	t_dlist	*rounds;
};

/*
**	Round.
**	Contains a list of moves.
*/

struct	s_round
{
	t_dlist	*moves;
};

/*
**	Ant move going from origin to target.
*/

struct	s_move
{
	t_room	*origin;
	t_room	*target;
};

struct	s_route
{
	int		len;
	t_list	*rooms;
};

struct	s_group
{
	int		count;
	int		high_len;
	int		low_len;
	t_list	*routes;
};

/*
**	Core.
*/

void	lem_in_init(t_lem_in *lem_in);
void	lem_in_add_room(t_lem_in *lem_in, t_room *room);
void	lem_in_free(t_lem_in *lem_in);
void	lem_in_die();

/*
**	Project generic list functions.
*/

t_glist	*ft_glstnew(void const *content, size_t content_size);
void	ft_glstdelone(t_glist **alst, void (*del)(void*, size_t));
void	ft_glstdel(t_glist **alst, void (*del)(void*, size_t));
void	ft_glstadd(t_glist **alst, t_glist *new);
void	ft_glstiter(t_glist *lst, void (*f)(t_glist *elem));
t_glist	*ft_glstmap(t_glist *lst, t_glist *(*f)(t_glist *elem));
void	ft_glstadd_last(t_glist **alst, t_glist *n);

/*
**	Parse.
*/

void	parse(t_lem_in *lem_in);
void	parse_ants_count(t_lem_in *lem_in, char **line);
t_bool	parse_rooms(t_lem_in *lem_in, char **line);
int		parse_room_line(t_lem_in *lem_in, char *line, t_roomtype type);
int		read_room_line(t_lem_in *lem_in, char **line, t_roomtype type);
void	parse_links(t_lem_in *lem_in, char **line);

/*
**	Room.
*/

t_room	*room_new(char *name, t_roomtype type, int x, int y);
t_room	*room_find_by_name(t_lem_in *lem_in, char *name);
void	room_add_link(t_lem_in *lem_in, char *origin, char *target);
void	room_set_ants(t_room *room, int ants);
void	room_free(void *content, size_t size);

/*
**	Route.
*/

int		route_cmp_conflit(t_route *route_a, t_route *route_b);
void	route_free(void *content, size_t size);

/*
**	Group.
*/

void	group_creat(t_group **g);
void	group_add_route(t_group **g, t_route *r);
void	group_del_route(t_group **g, t_route **r);
void	group_free(void *content, size_t size);
void	del_route_group_conflict(t_list **groups, t_list **routes, t_route **p);
void	groups_add_group(t_list **groups, t_group **group);

/*
**	Solve.
*/

void	solve(t_lem_in *lem_in, t_solution *solution);
void	scan_routes(t_lem_in *lem_in, t_list **routes);
void	build_groups(t_list **groups, t_list **routes);
t_group	*select_best_group(t_list *groups);
void	build_solution(t_solution *solution);

/*
**	Solution.
*/

void	solution_init(t_solution *solution);
void	solution_print(t_solution *solution);
void	solution_add_round(t_solution *solution);
void	solution_discard_round(t_solution *solution);
void	solution_add_move(t_solution *solution, t_move *move);

/*
**	Utils.
*/

void	ft_free_tab(char ***tab);
int		ft_strindex(const char *hay, char c);
int		ft_strrindex(const char *hay, char c);
int		gnl_no_comm(const int fd, char **line);

#endif

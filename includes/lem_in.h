/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 18:59:59 by juazouz          ###   ########.fr       */
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
typedef struct s_bitmap		t_bitmap;

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
	t_glist	*rooms;
};

/*
**	struct	s_room
**	description:	Ant room or node.
**
**	name:	Room name. Display purposes.
**	type:	Start / end / standard (intermediate node)
**	ants:	Ants count in the current room. Up to 1 for standard type.
**	links:	Connected rooms list.
**	weigth:	Distance to end node. Useful when building routes list. -1 is undefined.
*/

struct	s_room
{
	char		*name;
	t_roomtype	type;
	t_point		pos;
	int			ants;
	t_glist		*links;
	int			weigth;
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
	int			id_route;
	int			len;
	t_glist		*rooms;
	t_bitmap	*conflicts;
};

// struct	s_potentialroute
// {
// 	int		len;
// 	t_room	*room;
// 	t_potentialroute	*next;
// };

struct	s_group
{
	int		count;
	int		high_len;
	int		low_len;
	t_glist	*routes;
};

struct	s_bitmap
{
	size_t	bits_size;
	int		*map;
	t_list	*routes;
	int		id;
};

/*
**	Core.
*/

void		lem_in_init(t_lem_in *lem_in);
void		lem_in_add_room(t_lem_in *lem_in, t_room *room);
void		lem_in_free(t_lem_in *lem_in);
void		lem_in_die();

/*
**	Project generic list functions.
*/

t_glist		*ft_glstnew(void const *content, size_t content_size);
void		ft_glstdelone(t_glist **alst, void (*del)(void*, size_t));
void		ft_glstdel(t_glist **alst, void (*del)(void*, size_t));
void		ft_glstadd(t_glist **alst, t_glist *new);
void		ft_glstiter(t_glist *lst, void (*f)(t_glist *elem));
t_glist		*ft_glstmap(t_glist *lst, t_glist *(*f)(t_glist *elem));
void		ft_glstadd_last(t_glist **alst, t_glist *n);

/*
**	Parse.
*/

void		parse(t_lem_in *lem_in);
void		parse_ants_count(t_lem_in *lem_in, char **line);
t_bool		parse_rooms(t_lem_in *lem_in, char **line);
int			parse_room_line(t_lem_in *lem_in, char *line, t_roomtype type);
int			read_room_line(t_lem_in *lem_in, char **line, t_roomtype type);
void		parse_links(t_lem_in *lem_in, char **line);

/*
**	Room.
*/

t_room		*room_new(char *name, t_roomtype type, int x, int y);
t_room		*room_find_by_name(t_lem_in *lem_in, char *name);
void		room_add_link(t_lem_in *lem_in, char *origin, char *target);
void		room_set_ants(t_room *room, int ants);
void		room_free(void *content, size_t size);

/*
** Route.
*/

t_bool		route_equals(t_route *a, t_route *b);
t_bool		route_cmp_conflit(t_route *route_a, t_route *route_b);
void		route_free(void *content, size_t size);
t_bool		route_has_conflict(t_route *a, t_route *b);


/*
** Routes
*/

t_bool		routes_routechr(t_glist *routes, t_route *route);
int			routes_equals(t_glist *routes_a, t_glist *routes_b);

/*
**	Routes building.
*/

void		create_nodes_weights(t_lem_in *lem_in);

/*
** Group.
*/

t_group*	group_new();
void		group_add_route(t_group **group, t_route *route);
void		group_del_route(t_group *g, t_route *route);
void		group_free(void *content, size_t size);
t_bool		group_has_conflict(t_group **group, t_route *route);
void		group_route_conflict(t_glist **groups, t_route *a, t_glist *routes);
t_bool		group_equals(t_group *group_a, t_group *group_b);

/*
** Groups .
*/

void		groups_add_group(t_glist **groups, t_group *group);
void		build_groups(t_glist **groups, t_glist *routes);
t_bool		groups_doublon_group(t_glist *groups, t_group *group);

/*
**	Solver.
*/

void		solve(t_lem_in *lem_in, t_solution *solution);
void		scan_routes(t_lem_in *lem_in, t_glist **routes);
t_group		*select_best_group(t_glist *groups);
void		build_solution(t_solution *solution, t_group *group);

/*
**	Solution.
*/

void		solution_init(t_solution *solution);
void		solution_print(t_solution *solution);
void		solution_add_round(t_solution *solution);
void		solution_discard_round(t_solution *solution);
void		solution_add_move(t_solution *solution, t_move *move);

/*
**	Bitmap.
*/

t_bitmap	*bitmap_new(size_t bits_size);
t_bool		bitmap_get(t_bitmap *bitmap, size_t index);
void		bitmap_set(t_bitmap *bitmap, size_t index);
void		bitmap_free(t_bitmap *bitmap);

/*
**	Utils.
*/

void		ft_free_tab(char ***tab);
int			ft_strindex(const char *hay, char c);
int			ft_strrindex(const char *hay, char c);
int			gnl_no_comm(const int fd, char **line);

#endif

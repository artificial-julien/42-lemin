/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/21 16:42:45 by juazouz          ###   ########.fr       */
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

#define MAX_NB_SIZE 10

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
typedef struct s_opt		t_opt;
typedef struct s_bft		t_bft;

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
		t_bft		*bft;
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

struct	s_opt
{
	t_bool	debug;
	t_bool	print_room;
	t_bool	print_routes;
	t_bool	print_groups;
	t_bool	print_help;
};

struct	s_lem_in
{
	int		total_ants;
	t_room	*start;
	t_room	*end;
	int		room_len;
	t_glist	*rooms;
	t_list	*data;
	t_opt	opt;
};

/*
**	struct	s_room
**	description:	Ant room or node.
**
**	name:	Room name. Display purposes.
**	id:		Room id.
**	type:	Start / end / standard (intermediate node)
**	ants:	Ants count in the current room. Up to 1 for standard type.
**	links:	Connected rooms list.
*/

struct	s_room
{
	char		*name;
	int			id;
	t_roomtype	type;
	t_point		pos;
	int			ants;
	t_glist		*links;
	t_room		*prev;
	t_room		*next;
	int			links_count;
};

/*
**	Final result.
**	Contains a list of rounds.
*/

struct	s_solution
{
	int round;
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
**	Breadth-first traverse informations.
**
**	virtual_route:	Every traversed nodes. Virtual route used for flows creation.
**	augment_count:	How many times the path augmented the total flow.
**	forbidden:		Forbidden nodes map.
*/

struct	s_bft
{
	t_route		*virtual_route;
	int			augment_count;
	t_bitmap	*forbidden;
};

/*
**	Ant move going from origin to target.
*/

struct	s_move
{
	t_room	*src;
	t_room	*dst;
};

struct	s_route
{
	int			id_route;
	int			len;
	t_glist		*rooms;
};

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
	char	*map;
};

/*
**	Core.
*/

void		lem_in_init(t_lem_in *lem_in);
void		lem_in_add_room(t_lem_in *lem_in, t_room *room);
void		lem_in_free(t_lem_in *lem_in);
void		lem_in_die();
void		lem_in_remove_room(t_lem_in *lem_in ,t_room *room);

/*
**	Project generic list functions.
*/

t_glist		*ft_glstnew(void const *content, size_t content_size);
void		ft_glstdelone(t_glist **alst, void (*del)(void*, size_t));
void		ft_glstdel(t_glist **alst, void (*del)(void*, size_t));
void		ft_glstadd(t_glist **alst, t_glist *new);
void		ft_glstiter(t_glist *lst, void (*f)(t_glist *elem));
void		ft_glstinsert(t_glist **dest, t_glist *new, int (*cmp)(void*, void*));
t_glist		*ft_glstmap(t_glist *lst, t_glist *(*f)(t_glist *elem));
void		ft_glstadd_last(t_glist **alst, t_glist *n);
t_glist		*ft_glstcpy(t_glist *src);
t_bool		ft_glsthascontent(t_glist *lst, void *content);
void		ft_glstsort(t_glist *list, int (*cmp)(void*, void*));
int			ft_glstlen(t_glist *list);
void		ft_glstrev(t_glist **list);

/*
**	Parse.
*/

void		parse(t_lem_in *lem_in);
void		parse_ants_count(t_lem_in *lem_in, char **line);
void		parse_rooms(t_lem_in *lem_in, char **line);
void		parse_room(t_lem_in *lem_in, char *line, t_roomtype type);
int			read_room_line(t_lem_in *lem_in, char **line, t_roomtype type);
t_bool		parse_is_link(char *line);
void		parse_links(t_lem_in *lem_in, char **line);
void		parse_link(t_lem_in *lem_in, char *line);
int			parse_number_safe(char *s);

/*
**	Room.
*/

t_room		*room_new(char *name, t_roomtype type, int x, int y);
t_room		*room_find_by_name(t_lem_in *lem_in, char *name);
t_bool		room_find_name(t_lem_in *lem_in, char *name);
void		room_set_ants(t_room *room, int ants);
void		room_free(void *content, size_t size);

/*
** Room_links.
*/

void		room_add_link(t_lem_in *lem_in, char *origin, char *target);
void		room_remove_link(t_room *room, t_room *link);

/*
**	Breadth-first traverse.
*/

t_bft		*bft_run(t_lem_in *lem_in, t_bft *initial);
t_bft		*bft_new(int rooms_count);
void		bft_free(void *content, size_t size);
t_bft		*bft_copy(t_bft *bft);
void		bft_add_node(t_bft *bft, t_room *room);
void		bft_run_to_start(t_bft *bft);

/*
**	Route.
*/

t_route		*route_new();
t_route		*route_build(t_room *start, t_room *second);
void		route_free(void *content, size_t size);
t_route		*route_copy(t_route *src);
void		route_print(t_route *route);
void		route_add_node(t_route *route, t_room *room);

/*
** Route.
*/

t_route		*route_new();
t_bool		route_equals(t_route *a, t_route *b);
void		route_free(void *content, size_t size);
t_route		*route_copy(t_route *src);
int			route_cmp(void *a, void *b);

/*
**	Routes create conflict map
*/

void		route_create_conflicts_map(t_route *route, t_glist *routes, int count);
t_bool		route_has_conflict(t_route *a, t_route *b);

/*
** Routes
*/

t_bool		routes_routechr(t_glist *routes, t_route *route);

/*
** Group.
*/

t_group		*group_new();
t_group		*group_build(t_room *start);
void		group_add_route(t_group *group, t_route *route);
void		group_free(void *content, size_t size);
t_bool		group_equals(t_group *group_a, t_group *group_b);
t_bool		group_has_route(t_group *group, t_route *route);
void		group_print(t_group *group);
int			group_total_rounds(t_group *group, int total_ants);

/*
**	Solver.
*/

void		solve(t_lem_in *lem_in, t_solution *solution);
void		rebuild_routes(t_route *route);
t_group		*select_best_group(t_glist *groups, int total_ants);
void		build_solution(t_lem_in *lem_in, t_group *group, t_solution *solution);
void		sort_routes(t_group *group);
int			ants_distribution(t_group *group, int total_ants, int **res);

/*
**	Solution printer.
*/

void		print_solution(t_group *group, t_lem_in *lem_in);
t_bool		ant_try_move(t_room *src, t_room *dest, t_solution *solution);
t_bool		ant_can_move(t_room *room);

/*
**	Solution.
*/

void		solution_init(t_solution *solution);
void		solution_print(t_solution *solution);
void		solution_add_round(t_solution *solution);
void		solution_discard_round(t_solution *solution);
void		solution_add_move(t_solution *solution, t_room *src, t_room *dst);

/*
**	Bitmap.
*/

t_bitmap	*bitmap_new(size_t bits_size);
t_bool		bitmap_get(t_bitmap *bitmap, size_t index);
void		bitmap_set(t_bitmap *bitmap, size_t index);
void		bitmap_unset(t_bitmap *bitmap, size_t index);
void		bitmap_free(t_bitmap *bitmap);
t_bitmap	*bitmap_copy(t_bitmap *bitmap);
void		bitmap_print(t_bitmap *bitmap);
void		bitmap_reset(t_bitmap *bitmap);

/*
**	Utils.
*/

int			min_lem_in(t_lem_in *lem);
void		ft_free_tab(char ***tab);
int			ft_strindex(const char *hay, char c);
int			gnl_no_comm(const int fd, char **line);
void		print_nodes(t_glist *nodes);
t_bool		is_number(char *s);
/*
** Parsing opt of lem_in.
*/

void		init_opt(t_lem_in *lem_in);
void		printf_help(void);
void		print_unknow();
void		parse_opt(t_lem_in *lem_in, int ac, char **av);
void		parse_arg(char *s, t_lem_in *lem_in);


/*
**	Parser optimiser
*/

void		delete_dead_end(t_lem_in *lem_in, t_room *dead_end);
void		parse_optimizer(t_lem_in *lem_in);

/*
**	Print for for debug.
*/

void		group_print_extra(t_group *group);
void		route_print_extra(t_route *route);
void		room_print_extra(t_room *room);
void		lem_in_print_all_rooms(t_lem_in *lem_in);

/*
**	Lines saving and display.
*/

void		save_line(t_lem_in *lem_in, char *line);
void		print_lines(t_lem_in *lem_in);
void		free_saved_line(t_lem_in *lem_in);

#endif

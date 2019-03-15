/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/15 18:18:30 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**	Includes.
*/

# include "libft.h"

/*
**	Defines / Configuration.
*/

# define MAX_NB_SIZE 10

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
typedef struct s_opt		t_opt;
typedef struct s_tree		t_tree;

/*
**	Project generic list.
*/

union		u_generic
{
	void	*content;
	t_room	*room;
	t_route	*route;
	t_group	*group;
	t_round	*round;
	t_move	*move;
	t_glist	*glist;
	t_tree	*tree;
};

struct		s_glist
{
	union u_generic	gen;
	size_t			content_size;
	struct s_glist	*next;
};

struct		s_point
{
	int		x;
	int		y;
};

enum		e_roomtype
{
	standard,
	start,
	end,
};

struct		s_opt
{
	t_bool	debug;
	t_bool	print_room;
	t_bool	print_route;
	t_bool	print_groups;
	t_bool	print_nblines;
	t_bool	print_help;
};

struct		s_lem_in
{
	int		total_ants;
	int		max_routes;
	t_room	*start;
	t_room	*end;
	int		room_count;
	t_glist	*rooms;
	t_room	**array_room;
	t_list	*display;
	t_opt	opt;
};

/*
**	struct	s_room
**	description:	Ant room or node.
**
**	name:		Room name. Display purposes.
**	id:			Room id.
**	type:		Start / end / standard (intermediate node)
**	ants:		Ants count in the current room. Up to 1 for standard type.
**	ant_id:		Present ant id from 1 to ants_count.
**				0 when no ants are present.
**	links:		Connected rooms list.
**	visited:	True if the room has been visited by the breathd-first traverse.
*/

struct		s_room
{
	char		*name;
	int			id;
	t_roomtype	type;
	t_point		pos;
	int			ants;
	int			ant_id;
	t_glist		*links;
	int			links_count;
	t_room		*prev;
	t_room		*next;
	t_bool		visited;
};

/*
**	Final result.
**	Contains a list of rounds.
*/

struct		s_solution
{
	int		round;
	int		route;
	t_dlist	*rounds;
};

/*
**	Round.
**	Contains a list of moves.
*/

struct		s_round
{
	t_dlist	*moves;
};

/*
**	Virtual route tree. Used for forking in breadth first traverse.
**	room:			current node room.
**	parent:			parent node.
**	child_count:	child count. 0 means a dead end.
**	intersection:	node where the traverse starts cutting an existant route.
*/

struct		s_tree
{
	t_room	*room;
	t_tree	*parent;
	int		child_count;
	int		augmentation;
	t_room	*intersection;
};

/*
**	Ant move going from origin to target.
*/

struct		s_move
{
	int		id_route;
	int		ant_id;
	t_room	*dst;
};

struct		s_route
{
	int		id_route;
	int		len;
	t_glist	*rooms;
};

/*
**	Combination of non conflicting routes.
**	total_rounds:		required rounds to send ants using this group.
**						The lower the better.
**	count:				routes count.
**	ants_distribution:	optimal ants distribution array accross the routes.
**	routes:				group routes array.
*/

struct		s_group
{
	int		route_count;
	int		total_rounds;
	int		*ants_distribution;
	t_route	**routes;
};

/*
**	Core.
*/

void		lem_in_init(t_lem_in *lem_in);
void		lem_in_add_room(t_lem_in *lem_in, t_room *room);
void		lem_in_free(t_lem_in *lem_in);
void		lem_in_die();
void		lem_in_remove_room(t_lem_in *lem_in, t_room *room);

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
void		parse_link(t_lem_in *lem_in, char **line);
int			parse_number_safe(char *s);

/*
**	Room.
*/

t_room		*room_new(char *name, t_roomtype type, int x, int y);
t_room		*room_find_by_name(t_lem_in *lem_in, char *name);
void		room_free(void *content, size_t size);
int			room_cmp(void *a, void *b);

/*
** Room_links.
*/

void		room_add_link(t_lem_in *lem_in, char *origin, char *target);
void		room_remove_link(t_room *room, t_room *link);

/*
**	Breadth-first traverse.
*/

t_route		*run_bft(t_lem_in *lem_in);

/*
**	Breadth-first traverse core.
*/

t_route		*extend_nodes_list(t_lem_in *lem_in, t_glist *nodes,
	t_glist **next_nodes);
t_route		*extend_node(t_lem_in *lem_in,
	t_tree *node, t_glist **next_nodes);
t_route		*try_finalize_traverse(t_tree *node);
t_tree		*traverse_end(t_lem_in *lem_in, t_tree *node);
t_tree		*traverse(t_lem_in *lem_in, t_tree *node, t_room *dst);

/*
**	Breadth-first traverse utils.
*/

t_bool		can_traverse(t_tree *tree, t_room *dst);
t_bool		in_intersection(t_room *src, t_room *dst);
t_bool		out_intersection(t_room *src, t_room *dst);
t_tree		*go_to_start(t_lem_in *lem_in, t_tree *tree);

/*
**	Breadth-first traverse tree.
*/

t_tree		*tree_new(t_lem_in *lem_in);
void		tree_del(t_lem_in *lem_in, t_tree *tree);
void		tree_del_list(t_lem_in *lem_in, t_glist **trees);
t_tree		*tree_create_child(t_lem_in *lem_in, t_tree *parent, t_room *room);
void		tree_print(t_tree *tree);
t_route		*tree_to_route(t_tree *tree);

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
**	Group.
*/

t_group		*group_build(t_lem_in *lem_in);
void		group_add_route(t_group *group, t_route *route);
void		group_free(void *content, size_t size);
void		group_print(t_group *group);
int			group_rounds_for_route(t_group *group, int index);
void		distribute_ants(t_group *group, int total_ants);

/*
**	Solve.
*/

void		solve(t_lem_in *lem_in, t_solution *solution);
void		rebuild_routes(t_lem_in *lem_in, t_route *route);
void		build_solution(t_lem_in *lem_in, t_group *group,
	t_solution *solution);

/*
**	Solve utils.
*/

int			max_routes(t_lem_in *lem_in);

/*
**	Solution printer.
*/

void		print_solution(t_group *group, t_lem_in *lem_in);
t_bool		ant_try_move(t_room *src, t_room *dest,
	t_solution *solution, int *ants_routes);
t_bool		ant_can_move(t_room *room);

/*
**	Solution.
*/

void		solution_init(t_solution *solution);
void		solution_print(t_lem_in lem_in, t_solution *solution);
void		solution_add_round(t_solution *solution);
void		solution_add_move(t_solution *solution, t_room *dst);
void		solution_free(t_solution *solution);
void		round_free(void *content, size_t size);

/*
**	Utils.
*/

void		ft_free_tab(char ***tab);
int			ft_strindex(const char *hay, char c);
int			gnl_no_comm(const int fd, char **line);
void		print_nodes(t_glist *nodes);
t_bool		is_number(char *s);

/*
**	Array utils.
*/

void		*glist_to_array(t_glist *list);
void		array_sort(void **array, size_t size, int (cmp)(void*, void*));

/*
**	Parsing opt of lem_in.
*/

void		init_opt(t_lem_in *lem_in);
void		printf_help(void);
void		print_unknow();
void		parse_opt(t_lem_in *lem_in, int ac, char **av);
void		parse_arg(char *s, t_lem_in *lem_in);

/*
**	Parse optimiser.
*/

void		delete_dead_end(t_lem_in *lem_in, t_room *dead_end);
void		parse_optimizer(t_lem_in *lem_in);

/*
**	Print for for debug.
*/

void		room_print_extra(t_room *room);
void		lem_in_print_all_rooms(t_lem_in *lem_in);

/*
**	Lines saving and display.
*/

void		save_display(t_lem_in *lem_in, char *line);
void		print_display(t_lem_in *lem_in);
void		free_saved_display(t_lem_in *lem_in);

/*
**	Array utils.
*/

void		*glist_to_array(t_glist *list);
void		array_sort(void **array, size_t size, int (cmp)(void*, void*));

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   store_all_paths.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 13:34:12 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:47:56 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			end_of_path(t_lem *lem, int *path)
{
	if (!lem->path)
	{
		lem->begin_path = create_path(0, path, lem);
		lem->path = lem->begin_path;
	}
	else
	{
		lem->path->next = create_path(0, path, lem);
		lem->path = lem->path->next;
	}
	lem->nb_path++;
}

void			next_node(t_lem *lem, t_list_path *cur, int i)
{
	int	limit;

	limit = lem->nb_room + (lem->nb_room / 6);
	if (limit < lem->nblinks && lem->nb_room >= 20)
	{
		if (lem->clvl < lem->level[i])
		{
			lem->level[i] = lem->clvl;
			add_to_path(cur->path, i);
			lem->b_queue = push_queue(lem->b_queue, cur->path, lem);
			remove_last_path(cur->path);
		}
	}
	else
	{
		add_to_path(cur->path, i);
		lem->b_queue = push_queue(lem->b_queue, cur->path, lem);
		remove_last_path(cur->path);
	}
}

void			bfs(t_lem *lem)
{
	int			i;
	t_list_path	*cur;

	while ((cur = lem->b_queue) && lem->b_queue)
	{
		if (cur->path[0] == -1)
			cur = found_bm(lem, cur);
		if (!lem->b_queue)
			break ;
		i = 1;
		if (lem->room_matrix[cur->path[cur->size - 1]][lem->nb_room - 1] == '1')
			end_of_path(lem, cur->path);
		while (i < lem->nb_room - 1)
		{
			if (lem->room_matrix[cur->path[cur->size - 1]][i] == '1')
			{
				if (!(already_visited(cur->path, i)))
					next_node(lem, cur, i);
			}
			i++;
		}
		lem->b_queue = destroy_firstq(lem->b_queue);
	}
}

void			starting_queue(char *line, t_lem *lem, int *path)
{
	int			i;

	if (!(lem->bookmark = (int*)malloc(sizeof(int))))
		exit_after_rooms(lem);
	lem->bookmark[0] = -1;
	i = 0;
	lem->clvl = 0;
	while (i < lem->nb_room)
	{
		if (line[i] == '1')
		{
			path[0] = i;
			lem->b_queue = push_queue(lem->b_queue, path, lem);
		}
		i++;
	}
	lem->b_queue = push_queue(lem->b_queue, lem->bookmark, lem);
	bfs(lem);
}

void			store_all_paths(t_lem *lem, int *path)
{
	int		i;

	i = 0;
	lem->nb_path = 0;
	path = (int*)malloc(sizeof(int) * (lem->nb_room + 1));
	lem->level = (int*)malloc(sizeof(int) * lem->nb_room + 1);
	if (!path || !lem->level)
		exit_after_rooms(lem);
	while (i < lem->nb_room + 1)
	{
		path[i] = 0;
		lem->level[i] = lem->nb_room;
		i++;
	}
	starting_queue(lem->room_matrix[0], lem, path);
	free(path);
	free(lem->level);
	if (!lem->begin_path)
		error_matrix(lem, 0);
	free(lem->bookmark);
	init_range_list(lem);
}

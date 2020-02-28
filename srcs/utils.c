/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 10:42:07 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:20:01 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				nbturn(t_lem *lem, t_translate *info, int nb_ant, int turn)
{
	int	i;
	int	remove_ant;

	remove_ant = 1;
	i = 1;
	while (nb_ant > 0)
	{
		while (lem->soluce.pathsoluce[i])
		{
			if ((lem->soluce.pathsoluce[i]->size + 1) == turn)
			{
				i++;
				remove_ant++;
			}
			else if ((lem->soluce.pathsoluce[i]->size + 1) > turn)
				break ;
		}
		turn++;
		nb_ant -= remove_ant;
	}
	info->nbpath = i;
	return (turn);
}

t_list_path		*create_path(int size, int *path, t_lem *lem)
{
	t_list_path *new;

	new = NULL;
	if (!(new = (t_list_path*)malloc(sizeof(t_list_path))))
		exit_after_rooms(lem);
	if (!(new->path = tabdup(path, &size, lem)))
	{
		free(new);
		exit_after_rooms(lem);
	}
	new->size = size;
	new->next = NULL;
	return (new);
}

t_list_path		*destroy_firstq(t_list_path *begin_queue)
{
	t_list_path	*fresh;

	if (begin_queue->next)
	{
		fresh = begin_queue->next;
		free(begin_queue->path);
		free(begin_queue);
	}
	else
	{
		free(begin_queue->path);
		free(begin_queue);
		fresh = NULL;
	}
	return (fresh);
}

t_list_path		*push_queue(t_list_path *begin_queue, int *path, t_lem *lem)
{
	t_list_path	*new;

	new = begin_queue;
	if (!begin_queue)
	{
		begin_queue = create_path(0, path, lem);
		return (begin_queue);
	}
	else
	{
		while (new->next)
			new = new->next;
		new->next = create_path(0, path, lem);
		return (begin_queue);
	}
}

int				already_visited(int *path, int room)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (path[i] == room)
			return (1);
		i++;
	}
	return (0);
}

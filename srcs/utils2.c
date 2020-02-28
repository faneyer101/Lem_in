/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 22:27:46 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:25:59 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			check_emptyline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			ft_strdel(&line);
			ft_putendl_fd("Empty line somewhere\nERROR\n", 2);
			exit(0);
		}
		i++;
	}
}

t_list_path		*found_bm(t_lem *lem, t_list_path *cur)
{
	lem->b_queue = destroy_firstq(lem->b_queue);
	if (lem->b_queue != NULL && (lem->b_queue->path[0] != -1))
		lem->b_queue = push_queue(lem->b_queue, lem->bookmark, lem);
	lem->clvl++;
	cur = lem->b_queue;
	return (cur);
}

static int		nb_links(t_lem *lem)
{
	int	nblink1;
	int	enfant;

	nblink1 = 0;
	enfant = 0;
	while (enfant < lem->nb_room && enfant >= 0)
	{
		if (lem->room_matrix[0][enfant] == '1')
			nblink1++;
		enfant++;
	}
	return (nblink1);
}

int				init_range_list(t_lem *lem)
{
	lem->nb_path_max = nb_links(lem);
	lem->path = lem->begin_path;
	lem->save = lem->path;
	if ((init_solution(lem) == -1))
		exit(0);
	return (0);
}

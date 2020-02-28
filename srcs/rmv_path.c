/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rmv_path.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 18:23:28 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 11:42:47 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_nb_link(t_lem *lem, char *line)
{
	int	nblink;
	int	i;

	i = 0;
	nblink = 0;
	while (i < lem->nb_room)
	{
		if (line[i] == '1')
			nblink++;
		i++;
	}
	return (nblink);
}

void	turn_to_deadend(t_lem *lem, char *line)
{
	int	i;

	i = 0;
	while (i < lem->nb_room)
	{
		if (line[i] == '1')
			line[i] = '2';
		i++;
	}
}

char	check_if_deadend(t_lem *lem, char *line)
{
	char	deadend;

	deadend = 0;
	if (get_nb_link(lem, line) == 1)
	{
		deadend = 1;
	}
	return (deadend);
}

void	correct_matrix(t_lem *lem)
{
	int	i;
	int	j;

	i = 0;
	while (i < lem->nb_room)
	{
		j = 0;
		while (j < lem->nb_room)
		{
			if (lem->room_matrix[i][j] == '2')
				lem->room_matrix[j][i] = '2';
			j++;
		}
		i++;
	}
}

void	remove_paths(t_lem *lem)
{
	int	i;

	i = 1;
	while (i < lem->nb_room - 1)
	{
		if (check_if_deadend(lem, lem->room_matrix[i]))
		{
			turn_to_deadend(lem, lem->room_matrix[i]);
			correct_matrix(lem);
			i = 1;
			continue ;
		}
		i++;
	}
}

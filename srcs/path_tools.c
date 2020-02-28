/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 14:24:28 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:20:48 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

size_t	get_tab_size(int *tab)
{
	size_t	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	add_to_path(int *path, int c)
{
	int		i;

	i = 0;
	while (path[i])
		i++;
	path[i] = c;
}

int		*tabdup(int *tab, int *size, t_lem *lem)
{
	int		*rep;
	int		i;

	rep = (int*)malloc(sizeof(int) * (lem->nb_room + 1));
	i = 0;
	while (tab[i])
	{
		rep[i] = tab[i];
		i++;
	}
	*size = i;
	while (i < lem->nb_room)
	{
		rep[i] = 0;
		i++;
	}
	rep[i] = 0;
	return (rep);
}

void	remove_last_path(int *path)
{
	int	i;

	i = 0;
	while (path[i] != 0)
		i++;
	path[i - 1] = 0;
}

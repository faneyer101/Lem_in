/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 19:25:08 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:47:16 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_parsed(t_lem *lem)
{
	int	i;

	i = 0;
	ft_strdel(&lem->start);
	ft_strdel(&lem->end);
	while (i < lem->nb_room)
	{
		ft_strdel(&lem->rooms[i].name);
		ft_strdel(&lem->room_matrix[i]);
		i++;
	}
	ft_strdel(&lem->room_matrix[i]);
	free(lem->rooms);
	free(lem->room_matrix);
}

void	free_list_path(t_lem *lem)
{
	t_list_path *next_list;

	next_list = lem->save->next;
	while (lem->save != NULL)
	{
		free(lem->save->path);
		lem->save->next = NULL;
		free(lem->save);
		lem->save = next_list;
		if (next_list != NULL)
			next_list = next_list->next;
		else
			next_list = NULL;
	}
}

int		free_tab_soluce(int isize, t_list_path **tab, int jsize)
{
	int	i;

	i = -1;
	jsize = 98415;
	while (++i <= isize)
		ft_memdel((void**)&tab[i]);
	ft_memdel((void**)&tab);
	return (-1);
}

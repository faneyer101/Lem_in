/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   combinaison_path.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 18:47:01 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 04:23:13 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	cmp_path(t_list_path *list, t_list_path *tab_soluce, int size)
{
	int	i;
	int	j;
	int	colone;

	colone = 0;
	while (colone <= size)
	{
		i = 0;
		while ((tab_soluce[colone].size - 1) > i)
		{
			j = 0;
			while (list->size > j)
			{
				if (list->path[j] == tab_soluce[colone].path[i])
					return (-1);
				j++;
			}
			i++;
		}
		colone++;
	}
	return (0);
}

int			start_tab_soluce(t_lem *lem, t_resolv solver,
		t_list_path **tab_soluce)
{
	int	i;
	int	j;

	if (solver.etage == lem->nb_path)
		return (1);
	i = solver.etage;
	j = 1;
	while (solver.list != NULL && j < lem->nb_path)
	{
		if (cmp_path(solver.list, tab_soluce[i], j) == 0)
		{
			tab_soluce[i][j] = *solver.list;
			tab_soluce[i][j].size += 1;
			j++;
		}
		solver.list = solver.list->next;
	}
	solver.colone = 1;
	solver.etage++;
	solver.list = lem->save;
	return (start_tab_soluce(lem, solver, tab_soluce));
}

void		init_tab_soluce(t_lem *lem, t_list_path **tab_soluce)
{
	int			i;
	t_list_path	*list;

	list = lem->save;
	i = -1;
	while (list != NULL && ++i < lem->nb_path)
	{
		tab_soluce[i][0] = *list;
		tab_soluce[i][0].size += 1;
		list = list->next;
	}
}

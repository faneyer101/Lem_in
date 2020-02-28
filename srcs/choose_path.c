/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choose_path.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 18:35:04 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:10:36 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		malloc_tab_soluce(t_lem *lem, t_list_path ***tab_soluce, int i, int j)
{
	if (!(tab_soluce[0] = (t_list_path**)malloc(sizeof(t_list_path*) *
					(lem->nb_path + 1))))
		return (-1);
	while (i < lem->nb_path)
	{
		if (!(tab_soluce[0][i] = (t_list_path*)malloc(sizeof(t_list_path) *
						(lem->nb_path + 1))))
			return (free_tab_soluce(i, tab_soluce[0], j));
		j = 0;
		while (j < lem->nb_path)
		{
			tab_soluce[0][i][j].size = -1;
			j++;
		}
		tab_soluce[0][i][j].path = NULL;
		i++;
	}
	tab_soluce[0][i] = NULL;
	return (0);
}

int		create_soluce(t_lem *lem)
{
	int	i;

	if (!(lem->soluce.pathsoluce = (t_list_path**)malloc(sizeof(t_list_path*) *
					(lem->nb_path + 1))))
	{
		return (-1);
	}
	i = -1;
	while (++i < lem->nb_path)
		lem->soluce.pathsoluce[i] = NULL;
	return (0);
}

int		stock_soluce(t_lem *lem, t_resolv solver, t_list_path **tab_soluce)
{
	int	i;

	if (create_soluce(lem) == -1)
		return (-1);
	i = 0;
	while (i < solver.size)
	{
		lem->soluce.pathsoluce[i] = &tab_soluce[solver.soluce][i];
		i++;
	}
	lem->soluce.pathsoluce[i] = NULL;
	return (0);
}

void	range_soluce(t_lem *lem, t_resolv solver)
{
	int			i;
	t_list_path *tmp;

	i = 1;
	while (i < solver.size)
	{
		if (lem->soluce.pathsoluce[i]->size <
				lem->soluce.pathsoluce[i - 1]->size)
		{
			tmp = lem->soluce.pathsoluce[i];
			lem->soluce.pathsoluce[i] = lem->soluce.pathsoluce[i - 1];
			lem->soluce.pathsoluce[i - 1] = tmp;
			i = 0;
		}
		i++;
	}
}

int		init_solution(t_lem *lem)
{
	t_resolv	solver;
	int			i;

	i = 0;
	if (malloc_tab_soluce(lem, &lem->tab_soluce, 0, 0) == -1)
	{
		free_list_path(lem);
		return (-1);
	}
	init_tab_soluce(lem, lem->tab_soluce);
	init_struct(lem, &solver, 0);
	start_tab_soluce(lem, solver, lem->tab_soluce);
	init_struct(lem, &solver, 1);
	search_best_solution(lem, lem->tab_soluce, &solver);
	if (stock_soluce(lem, solver, lem->tab_soluce) == -1)
	{
		free_list_path(lem);
		free_tab_soluce(lem->nb_path, lem->tab_soluce, lem->nb_room);
		return (-1);
	}
	range_soluce(lem, solver);
	lem->nb_turn = solver.nbturn - 1;
	create_tab_ant(lem, solver, lem->nb_ant);
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gestion_tab_ant.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 18:36:47 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 04:26:37 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	malloc_tab_ant(t_lem *lem, int i)
{
	if (!(lem->tab_ant = (int**)malloc(sizeof(int*) * (2 + 1))))
		return (-1);
	if (!(lem->tab_ant[0] = (int*)malloc(sizeof(int) * (lem->nb_room + 1))))
	{
		free(lem->tab_ant);
		return (-1);
	}
	while (++i < lem->nb_room)
		lem->tab_ant[0][i] = -1;
	if (!(lem->tab_ant[1] = (int*)malloc(sizeof(int) * (lem->nb_room + 1))))
	{
		free(lem->tab_ant[0]);
		free(lem->tab_ant);
		return (-1);
	}
	i = -1;
	while (++i < lem->nb_room)
		lem->tab_ant[1][i] = 0;
	lem->tab_ant[2] = NULL;
	return (0);
}

static void	actif_path(t_lem *lem, int index_path_actif)
{
	if (lem->tab_ant[0][index_path_actif] == -1)
		lem->tab_ant[0][index_path_actif] = 1;
}

static void	nb_ant_path(t_lem *lem, int i, int size, int nbant)
{
	while (++i < size)
		if (lem->tab_ant[0][i] != -1)
		{
			lem->tab_ant[1][i] += 1;
			nbant--;
			if (nbant == 0)
				break ;
		}
}

int			create_tab_ant(t_lem *lem, t_resolv solver, int nbant)
{
	int	i;
	int	nb_turn;
	int	remove_ant;

	nb_turn = 0;
	remove_ant = 0;
	if (malloc_tab_ant(lem, -1) != 0)
		return (-1);
	while (nbant > 0)
	{
		i = -1;
		while (lem->soluce.pathsoluce[++i])
			if (lem->soluce.pathsoluce[i]->size == nb_turn)
			{
				actif_path(lem, i);
				remove_ant++;
			}
		nb_ant_path(lem, -1, solver.size, nbant);
		nbant -= remove_ant;
		nb_turn++;
	}
	return (0);
}

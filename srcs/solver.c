/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: faneyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 18:56:16 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 04:29:01 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		init_struct(t_lem *lem, t_resolv *solver, int a)
{
	if (a == 0)
	{
		solver->list = lem->save;
		solver->etage = 0;
	}
	else if (a == 1)
	{
		solver->etage = 0;
		solver->colone = 0;
		solver->soluce = 0;
		solver->size = 0;
		solver->ok = -1;
		solver->nbturn = -1;
	}
	else if (a == 2)
		solver->colone = 0;
}

static void	approuve_solution(t_resolv *solver, int nbturn)
{
	solver->soluce = solver->etage;
	solver->size = solver->colone;
	solver->nbturn = nbturn;
	solver->ok = 1;
}

static void	cmpturn(t_lem *lem, int tab_turn[lem->nb_path + 1],
		t_resolv *solver, int nb_ant)
{
	int	i;
	int	nb_turn;
	int	remove_ant;

	remove_ant = 0;
	nb_turn = 0;
	while (nb_ant > 0)
	{
		i = -1;
		while (++i < lem->nb_path && tab_turn[i] != -1)
		{
			if (tab_turn[i] == nb_turn)
				remove_ant++;
		}
		nb_turn++;
		nb_ant -= remove_ant;
	}
	if (solver->nbturn == -1 || nb_turn < solver->nbturn)
		approuve_solution(solver, nb_turn);
}

int			search_best_solution(t_lem *lem, t_list_path **tab_soluce,
		t_resolv *solver)
{
	int	tab_turn[lem->nb_path + 1];

	if (solver->etage >= lem->nb_path && solver->ok == 1)
		return (1);
	while (solver->colone < lem->nb_path &&
			tab_soluce[solver->etage][solver->colone].size != -1)
	{
		tab_turn[solver->colone] =
			tab_soluce[solver->etage][solver->colone].size
			+ 1;
		solver->colone++;
	}
	tab_turn[solver->colone] = -1;
	cmpturn(lem, tab_turn, solver, lem->nb_ant);
	init_struct(lem, solver, 2);
	solver->etage++;
	return (search_best_solution(lem, tab_soluce, solver));
}

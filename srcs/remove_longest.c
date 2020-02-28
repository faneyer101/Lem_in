/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   remove_longest.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 04:54:11 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 09:43:22 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	recalculate_paths(t_lem *lem, t_translate *info)
{
	int	i;

	i = 0;
	while (lem->soluce.pathsoluce[i])
		i++;
	info->nbpath = i;
}

void	remove_from(int i, t_translate *info, t_lem *lem)
{
	int	j;

	j = 0;
	while (lem->soluce.pathsoluce[j])
		j++;
	j--;
	while (j >= i)
	{
		lem->soluce.pathsoluce[j] = NULL;
		info->nbpath--;
		j--;
	}
}

void	remove_longest(t_lem *lem, t_translate *info)
{
	int	i;

	i = 0;
	while (lem->soluce.pathsoluce[i])
	{
		if (lem->tab_ant[1][i] < 1 && info->nbpath > 1)
			remove_from(i, info, lem);
		lem->tab_ant[1][i] -= 1;
		i++;
	}
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   translate_answ.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 18:23:00 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:47:42 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		move_ants(t_translate *info, t_lem *lem, int out, int i)
{
	while (i < out)
	{
		if (info->allants[i].ipos == -1)
			i++;
		else
		{
			info->allants[i].ipos++;
			if (info->allants[i].path[info->allants[i].ipos] == 0)
			{
				ft_printf("L%d-%s ", info->allants[i].num + 1, lem->end);
				info->finished++;
				info->allants[i].ipos = -1;
				free(info->allants[i].path);
			}
			else
			{
				ft_printf("L%d-%s ", info->allants[i].num + 1,
					lem->rooms[info->allants[i].path[info->allants[i].ipos]]);
			}
			i++;
		}
	}
}

void		start_ants(int topush, int out, t_translate *info, t_lem *lem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < out)
		i++;
	while (j < topush)
	{
		info->allants[i].num = i;
		if (!(info->allants[i].path = tabdup(lem->soluce.pathsoluce[j]->path,
			&lem->soluce.pathsoluce[j]->size, lem)))
			exit_after_rooms(lem);
		info->allants[i].ipos = 0;
		ft_printf("L%d-%s ", info->allants[i].num + 1,
			lem->rooms[info->allants[i].path[0]]);
		j++;
		i++;
	}
}

void		take_turns(t_lem *lem, t_translate *info)
{
	int	topush;
	int	out;

	out = 0;
	info->remaining = lem->nb_ant;
	while (info->turn < info->nbturn)
	{
		remove_longest(lem, info);
		topush = info->nbpath;
		if (info->remaining < topush)
			topush = info->remaining;
		if (info->turn)
			move_ants(info, lem, out, 0);
		start_ants(topush, out, info, lem);
		out += topush;
		info->remaining -= topush;
		info->turn++;
		if (info->finished == lem->nb_ant)
			break ;
		ft_putendl("");
	}
}

static void	init_info(t_lem *lem, t_translate *info)
{
	int	i;

	i = 0;
	info->l_path = 0;
	while (lem->soluce.pathsoluce[i])
	{
		if (lem->soluce.pathsoluce[i]->size > info->l_path)
			info->l_path = lem->soluce.pathsoluce[i]->size;
		i++;
	}
	info->turn = 0;
	info->l_path++;
	info->nbpath = i;
	info->nbturn = info->l_path + lem->nb_ant / info->nbpath;
	info->nbturn = (lem->nb_ant % info->nbpath > 0)
		? info->nbturn + 1 : info->nbturn;
	info->onboard = 0;
	if (!(info->allants = (t_ts_ant*)malloc(sizeof(t_ts_ant) * lem->nb_ant)))
		exit_after_rooms(lem);
	i = 0;
	info->finished = 0;
	while (i < lem->nb_ant)
		info->allants->num = i++;
}

void		translate_answ(t_lem *lem)
{
	t_translate info;

	ft_putendl("");
	init_info(lem, &info);
	take_turns(lem, &info);
	ft_printf("\n\n{BLUE}{BOLD}{UND}Number of turns to finish: %d turns{END}\n",
				info.turn);
	free(info.allants);
	free(lem->tab_ant[0]);
	free(lem->tab_ant[1]);
	free(lem->tab_ant);
	free(lem->soluce.pathsoluce);
	free_tab_soluce(lem->nb_path, lem->tab_soluce, lem->nb_path);
	free_list_path(lem);
}

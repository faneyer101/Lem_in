/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 23:54:33 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 08:32:58 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	check_roomerrors(t_lem *lem)
{
	int	i;

	i = 0;
	check_dupe_roomname(lem);
	if (ft_strchr(lem->start, '-') || ft_strchr(lem->end, '-'))
	{
		while (lem->tabfile[i])
		{
			ft_strdel(&lem->tabfile[i]);
			i++;
		}
		ft_strdel(&lem->start);
		ft_strdel(&lem->end);
		ft_putstr_fd("Error on your start or end room\nERROR", 2);
		exit(0);
	}
}

void	exit_after_rooms(t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->tabfile[i])
	{
		ft_strdel(&lem->tabfile[i]);
		i++;
	}
	i = 0;
	ft_strdel(&lem->start);
	ft_strdel(&lem->end);
	while (i < lem->nb_room)
	{
		ft_strdel(&lem->rooms[i].name);
		i++;
	}
	exit(0);
}

void	exit_early_parsing(t_lem *lem)
{
	int	i;

	i = 0;
	if (lem->start)
		free(lem->start);
	if (lem->end)
		free(lem->end);
	while (lem->tabfile[i])
	{
		ft_strdel(&lem->tabfile[i]);
		i++;
	}
	ft_putendl_fd("ERROR", 2);
	exit(0);
}

int		check_those_rooms(t_lem *lem, int i, int j)
{
	if (lem->start[0] == 'L' || lem->end[0] == 'L')
		return (1);
	if (ft_strcmp(lem->rooms[i].name, lem->rooms[j].name) == 0)
		return (1);
	if (ft_strcmp(lem->rooms[i].name, lem->start) == 0 && i != 0)
		return (1);
	if (ft_strcmp(lem->rooms[i].name, lem->end) == 0)
		return (1);
	if (ft_strchr(lem->rooms[i].name, '-')
		|| ft_strchr(lem->rooms[j].name, '-'))
		return (1);
	if (lem->rooms[i].name[0] == 'L' || lem->rooms[j].name[0] == 'L')
		return (1);
	return (0);
}

void	check_dupe_roomname(t_lem *lem)
{
	int		i;
	int		j;
	char	boolerror;

	i = 0;
	boolerror = 0;
	while (i < lem->nb_room - 1)
	{
		j = i + 1;
		while (j < lem->nb_room)
		{
			boolerror = check_those_rooms(lem, i, j);
			j++;
			if (boolerror)
				break ;
		}
		i++;
		if (boolerror)
			break ;
	}
	if (boolerror)
	{
		ft_putendl_fd("Duplicate or forbidden name\nERROR", 2);
		exit_after_rooms(lem);
	}
}

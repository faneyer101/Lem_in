/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_coords.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 11:31:47 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 12:26:04 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"

void	exit_coords(char **tab, t_lem *lem)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
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
	free(lem->room_coords);
	exit(0);
}

void	check_letter(char **tab, t_lem *lem)
{
	int		i;
	int		j;
	char	boolerror;

	boolerror = 0;
	i = 0;
	j = 0;
	while (tab[1][i])
	{
		if (!(ft_isdigit(tab[1][i])))
			boolerror = 1;
		i++;
	}
	while(tab[2][j])
	{
		if (!(ft_isdigit(tab[2][j])))
			boolerror = 1;
		j++;
	}
	if (boolerror)
	{
		ft_putendl_fd("Can only have digits in your coords\nERROR", 2);
		exit_coords(tab, lem);
	}
}

void	check_coords(char **tab, t_lem *lem)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	if (i != 3)
	{
		ft_putendl_fd("Your rooms must have x and y coords: roomnname xcoord ycoord\nERROR", 2);
		exit_coords(tab, lem);
	}
	check_letter(tab, lem);
}
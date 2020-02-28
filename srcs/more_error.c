/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   more_error.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 07:13:42 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 23:42:20 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	error_get_roomname(t_lem *lem, char **r1, char **r2)
{
	ft_strdel(r1);
	ft_strdel(r2);
	ft_putendl_fd("Wrong room name in your list of links\nERROR\n", 2);
	exit_after_rooms(lem);
}

void	error_matrix(t_lem *lem, int bool)
{
	int	i;

	i = 0;
	if (bool)
	{
		while (lem->tabfile[i])
		{
			ft_strdel(&lem->tabfile[i]);
			i++;
		}
	}
	i = 0;
	ft_strdel(&lem->start);
	ft_strdel(&lem->end);
	while (i < lem->nb_room)
	{
		ft_strdel(&lem->rooms[i].name);
		ft_strdel(&lem->room_matrix[i]);
		i++;
	}
	free(lem->room_matrix);
	ft_putendl_fd("\nStart or end in links or no solution\nERROR\n", 2);
	exit(0);
}

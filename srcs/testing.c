/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/04 16:28:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 22:19:30 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_path(int *path, t_lem *lem, int size)
{
	int		i;

	i = 0;
	ft_printf("%s-", lem->rooms[0].name);
	while (i < size)
	{
		ft_printf("%s-", lem->rooms[path[i]].name);
		i++;
	}
	ft_printf("%s\nThe path is %d long\n",
		lem->rooms[lem->nb_room - 1].name, i + 1);
}

void	print_all_paths(t_lem *lem)
{
	int		track_nb_path;

	track_nb_path = 0;
	lem->path = lem->begin_path;
	while (track_nb_path < lem->nb_path)
	{
		if (lem->path->size <= 3)
			print_path(lem->path->path, lem, lem->path->size);
		if (lem->path->next)
			lem->path = lem->path->next;
		track_nb_path++;
	}
}

void	print_all_paths2(t_lem *lem, t_list_path *list)
{
	int		track_nb_path;

	track_nb_path = 0;
	while (track_nb_path < lem->nb_path)
	{
		if (list->size <= 5)
			print_path(list->path, lem, list->size);
		if (list->next)
			list = list->next;
		track_nb_path++;
	}
}

void	test(t_lem *lem)
{
	int	i;

	i = 0;
	ft_printf("\nNombre de fourmis: %lld\n", lem->nb_ant);
	ft_printf("Nombre de salles: %d\n", lem->nb_room);
	ft_printf("La salle de depart est: '%s'\n", lem->start);
	ft_printf("La salle de fin est   : '%s'\n", lem->end);
	ft_putendl("\n");
	if (lem->nb_room < 40)
	{
		while (lem->room_matrix[i])
		{
			ft_putendl(lem->room_matrix[i]);
			i++;
		}
	}
	ft_putendl("");
}

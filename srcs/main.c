/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/27 19:02:01 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:47:35 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_tabfile(t_lem *lemin)
{
	int	i;

	i = 0;
	while (lemin->tabfile[i] != NULL)
	{
		free(lemin->tabfile[i]);
		i++;
	}
	free(lemin->tabfile[i]);
	free(lemin->tabfile);
}

void	check_startend(t_lem *lem)
{
	int	i;

	i = 0;
	if (lem->room_matrix[0][lem->nb_room - 1] == '1')
	{
		while (i < lem->nb_ant)
		{
			ft_printf("L%d-%s ", i + 1, lem->end);
			i++;
		}
		ft_putendl("");
		ft_printf("Start connected to end\n");
		exit_after_rooms(lem);
	}
}

void	setup_visu(t_lem *lem)
{
	parse_coords(lem);
	free_tabfile(lem);
	visu_lemin(lem);
}

int		main(int argc, char **argv)
{
	t_lem			lemin;
	char			bool_visu;
	int				i;

	i = -1;
	ft_bzero((void*)&lemin, sizeof(t_lem));
	while (++i < lemin.nb_room)
		ft_bzero((void*)&lemin.rooms[i], sizeof(t_rooms));
	bool_visu = 0;
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'v')
		bool_visu = 1;
	lem_parsing(&lemin);
	remove_paths(&lemin);
	check_startend(&lemin);
	test(&lemin);
	store_all_paths(&lemin, NULL);
	translate_answ(&lemin);
	if (!bool_visu)
	{
		free_tabfile(&lemin);
		free_parsed(&lemin);
	}
	if (bool_visu)
		setup_visu(&lemin);
	return (0);
}

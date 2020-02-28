/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parsing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 17:23:20 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 01:22:34 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		skip_multiple_coms(t_lem *lem)
{
	int	i;

	i = 0;
	while (lem->tabfile[lem->curs + i] && lem->tabfile[lem->curs + i][0] == '#')
		i++;
	return (i);
}

void	check_com(t_lem *lem)
{
	int		i;
	char	*tmp;

	i = skip_multiple_coms(lem);
	if (!(ft_strcmp(lem->tabfile[lem->curs], "##start")))
	{
		tmp = ft_strdup(lem->tabfile[lem->curs + i]);
		lem->start = ft_strndup(tmp, ft_strcspn(tmp, " "));
		ft_strdel(&tmp);
		check_com_cut(lem, i, 1);
		if (!lem->start)
			exit_early_parsing(lem);
	}
	else if (!(ft_strcmp(lem->tabfile[lem->curs], "##end")))
	{
		tmp = ft_strdup(lem->tabfile[lem->curs + i]);
		lem->end = ft_strndup(tmp, ft_strcspn(tmp, " "));
		ft_strdel(&tmp);
		check_com_cut(lem, i, 0);
		if (!lem->end)
			exit_early_parsing(lem);
	}
	else
		lem->curs++;
}

void	get_nb_ants(t_lem *lem)
{
	while (lem->tabfile[lem->curs] && lem->tabfile[lem->curs][0] == '#')
	{
		if (lem->tabfile[lem->curs][0] == '#')
			check_com(lem);
		else
			lem->curs++;
	}
	if (lem->tabfile[lem->curs])
		lem->nb_ant = ft_atoi(lem->tabfile[lem->curs]);
	if (lem->nb_ant < 1 || lem->nb_ant > 2147483647)
	{
		ft_putstr_fd("Wrong number of ants, set : [1 to 2147483647]\n", 2);
		exit_early_parsing(lem);
	}
	lem->curs++;
	while (lem->tabfile[lem->curs] && lem->tabfile[lem->curs][0] == '#')
	{
		if (lem->tabfile[lem->curs][0] == '#')
			check_com(lem);
	}
	if (!lem->tabfile[lem->curs])
	{
		ft_putstr_fd("No rooms no links ??\n", 2);
		exit_early_parsing(lem);
	}
}

void	get_nb_rooms(t_lem *lem)
{
	int	tmpcurs;

	tmpcurs = lem->curs;
	while (42)
	{
		if (lem->tabfile[lem->curs][0] == '#')
			check_com(lem);
		else if (ft_strchr(lem->tabfile[lem->curs], '-'))
			break ;
		else
		{
			lem->nb_room++;
			lem->curs++;
		}
		if (!lem->tabfile[lem->curs])
			break ;
	}
	if (lem->nb_room == 0 || lem->startfound != 1 || lem->endfound != 1)
	{
		ft_putendl_fd("Stricly need one starting and ending room", 2);
		exit_early_parsing(lem);
	}
	lem->curs = tmpcurs;
}

void	lem_parsing(t_lem *lem)
{
	char	*linefile;

	linefile = file_to_line();
	check_emptyline(linefile);
	if (!(lem->tabfile = ft_strsplit(linefile, '\n')))
		exit(0);
	if (!lem->tabfile[1])
	{
		ft_strdel(&linefile);
		free_tabfile(lem);
		ft_putendl("Empty map, no links, or empty line somewhere\nERROR\n");
		exit(0);
	}
	get_nb_ants(lem);
	if (!lem->nb_ant)
		exit_early_parsing(lem);
	get_nb_rooms(lem);
	parse_rooms(lem);
	write(1, linefile, ft_strlen(linefile));
	ft_strdel(&linefile);
	ft_printf("nblink = %d nbroom = %d\n", lem->nblinks, lem->nb_room);
}

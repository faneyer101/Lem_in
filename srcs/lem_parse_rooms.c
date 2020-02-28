/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_parse_rooms.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 22:33:53 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 03:18:52 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	make_roomtab(t_lem *lem)
{
	int	i;

	if (!(lem->rooms = (t_rooms*)malloc(sizeof(t_rooms) * lem->nb_room)))
		exit_early_parsing(lem);
	i = 1;
	while (i < lem->nb_room && lem->tabfile[lem->curs])
	{
		while (lem->tabfile[lem->curs][0] == '#')
			lem->curs++;
		lem->rooms[i].name = ft_strndup(lem->tabfile[lem->curs],
			ft_strcspn(lem->tabfile[lem->curs], " "));
		if (!ft_strcmp(lem->rooms[i].name, lem->start))
			ft_strdel(&lem->rooms[i--].name);
		else if (!ft_strcmp(lem->rooms[i].name, lem->end))
			ft_strdel(&lem->rooms[i--].name);
		i++;
		lem->curs++;
	}
	lem->rooms[0].name = ft_strdup(lem->start);
	ft_strdel(&lem->rooms[lem->nb_room - 1].name);
	lem->rooms[lem->nb_room - 1].name = ft_strdup(lem->end);
}

void	get_room_names(char **r1, char **r2, char *str, t_lem *lem)
{
	int		i;
	int		j;
	char	foundboth;

	j = 0;
	foundboth = 0;
	i = ft_strcspn(str, "-");
	*r1 = ft_strndup(str, i);
	*r2 = ft_strdup(str + i + 1);
	if (!r1 || !r2)
		exit_after_rooms(lem);
	while (j < lem->nb_room)
	{
		if (!(ft_strcmp(*r1, lem->rooms[j].name))
			|| !(ft_strcmp(*r2, lem->rooms[j].name)))
			foundboth++;
		j++;
	}
	if (foundboth < 2)
		error_get_roomname(lem, r1, r2);
}

void	fill_matrix(t_lem *lem, int i, int j)
{
	char	*r1;
	char	*r2;

	while (lem->tabfile[lem->curs])
	{
		i = 0;
		j = 0;
		while (lem->tabfile[lem->curs] && lem->tabfile[lem->curs][0] == '#')
		{
			if (ft_strequ(lem->tabfile[lem->curs], "##start")
				|| ft_strequ(lem->tabfile[lem->curs], "##end"))
				error_matrix(lem, 1);
			lem->curs++;
		}
		if (!(lem->tabfile[lem->curs]))
			break ;
		get_room_names(&r1, &r2, lem->tabfile[lem->curs], lem);
		while (ft_strcmp(r1, lem->rooms[i].name))
			i++;
		while (ft_strcmp(r2, lem->rooms[j].name))
			j++;
		ft_strdel(&r1);
		ft_strdel(&r2);
		matrix_next(lem, i, j);
	}
}

void	init_matrix(t_lem *lem)
{
	int i;
	int j;

	lem->nblinks = 0;
	lem->room_matrix = (char **)malloc(sizeof(char *) * (lem->nb_room + 1));
	i = 0;
	while (i < lem->nb_room)
	{
		j = 0;
		lem->room_matrix[i] = (char *)malloc(sizeof(char) * (lem->nb_room + 1));
		while (j < lem->nb_room)
		{
			lem->room_matrix[i][j] = '0';
			j++;
		}
		lem->room_matrix[i][j] = '\0';
		i++;
	}
	lem->room_matrix[i] = NULL;
}

void	parse_rooms(t_lem *lem)
{
	make_roomtab(lem);
	lem->curs = 0;
	while (lem->tabfile[lem->curs]
		&& ((!(ft_strchr(lem->tabfile[lem->curs], '-'))
		|| lem->tabfile[lem->curs][0] == '#')))
		lem->curs++;
	if (!lem->tabfile[lem->curs])
	{
		ft_putendl_fd("No links\nERROR\n", 2);
		exit_after_rooms(lem);
	}
	if (ft_strequ(lem->tabfile[lem->curs], "##start")
			|| ft_strequ(lem->tabfile[lem->curs], "##end")
				|| !lem->tabfile[lem->curs])
		exit_after_rooms(lem);
	check_roomerrors(lem);
	init_matrix(lem);
	fill_matrix(lem, 0, 0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_answer.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 16:27:43 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:12:32 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"

int		get_next_ant(t_lem *lem, char *line)
{
	int		nbant;

	
	while (line[lem->i_parsingline] != 'L')
		lem->i_parsingline++;
	lem->i_parsingline++;
	nbant = ft_atoi(line + lem->i_parsingline);
	lem->i_parsingline += ft_intlen(nbant);
	return (nbant - 1);
}

int		get_next_room(t_lem *lem, char *line)
{
	char *room;
	int	rep;

	rep = 0;
	lem->i_parsingline++;
	room = ft_strndup(line + lem->i_parsingline, ft_strcspn(line + lem->i_parsingline, " \0"));
	lem->i_parsingline += ft_strlen(room);
	while (ft_strcmp(room, lem->rooms[rep].name))
		rep++;
	ft_strdel(&room);
	return (rep);
}

void	parse_this_turn(t_lem *lem, char *line, int iturn)
{
	int		nbant;
	int		iant;

	iant = 0;
	lem->i_parsingline = 0;
	nbant = ft_stroccur(line, '-');
	lem->turns[iturn] = (int**)malloc(sizeof(int*) * nbant + 1);
	while (iant < nbant)
	{
		lem->turns[iturn][iant] = (int*)malloc(sizeof(int) * 2);
		lem->turns[iturn][iant][0] = get_next_ant(lem, line);
		lem->turns[iturn][iant][1] = get_next_room(lem, line);
		iant++;
	}
	lem->turns[iturn][iant] = NULL;
}

void	parse_answer(t_lem *lem, t_visulem *vs)
{
	int		iturn;

	iturn = 0;
	lem->turns = (int***)malloc(sizeof(int**) * lem->nb_turn);
	while (lem->answer != NULL)
	{
		if (lem->answer->next == NULL)
			break;
		parse_this_turn(lem, lem->answer->line, iturn);
		lem->answer = lem->answer->next;
		iturn++;
	}
	(void)vs;
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_movement.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 18:25:13 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 16:01:15 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"

void	move_this_ant(t_lem *lem, t_visulem *vs, t_ant *ant, int tour, int numant)
{
	if (ant->turn < ant->nbmoves)
	{
		ant->pos.x = vs->ants[lem->turns[tour][numant][0]].path[ant->turn][0];
		ant->pos.y = vs->ants[lem->turns[tour][numant][0]].path[ant->turn][1];
	}
	if (ant->turn + ant->nbmoves / 50 >= ant->nbmoves)
		ant->turn = ant->nbmoves - 1;
	else if (ant->nbmoves / 50 == 0)
		ant->turn++;
	else
		ant->turn += ant->nbmoves / 50;
}

void	my_delay(int clock)
{
	int	wait;

	wait = SDL_GetTicks() - clock;
	if (wait < 33)
		SDL_Delay(33 - wait);
}

void	allmoves(t_lem *lem, t_visulem *vs)
{
	int tour = 0;
	int	ant;
	int i;
	int j;
	int alloc;
	int turn = 0;
	int	totalmoves;

	int clock;
	while (tour < lem->nb_turn)
	{
		ant = 0;
		totalmoves = 0;
		while (lem->turns[tour][ant] != NULL)
		{
			i = ft_abs(vs->ants[lem->turns[tour][ant][0]].pos.x - (vs->rooms[lem->turns[tour][ant][1]].x + vs->room_size / 4));
			j = ft_abs(vs->ants[lem->turns[tour][ant][0]].pos.y - (vs->rooms[lem->turns[tour][ant][1]].y + vs->room_size / 4));
			if (i > j)
				alloc = i;
			else
				alloc = j;
			if ((vs->ants[lem->turns[tour][ant][0]].path = (int**)malloc(sizeof(int*) * alloc)) == NULL)
				error_init(lem, vs, 2);

			if ((vs->ants[lem->turns[tour][ant][0]].nbmoves = bresenham(&vs->ants[lem->turns[tour][ant][0]].pos,
																	vs->rooms[lem->turns[tour][ant][1]].x + vs->room_size / 4,
																	vs->rooms[lem->turns[tour][ant][1]].y + vs->room_size / 4,
																	vs->ants[lem->turns[tour][ant][0]].path)) == 0)
				error_init(lem, vs, 2);
			if (vs->ants[lem->turns[tour][ant][0]].nbmoves > totalmoves)
				totalmoves = vs->ants[lem->turns[tour][ant][0]].nbmoves;
			ant++;
		}
		turn = 0;
		while (turn <= 60)
		{
			clock = SDL_GetTicks();
			ant = 0;
			while (lem->turns[tour][ant] != NULL)
			{
				move_this_ant(lem, vs, &vs->ants[lem->turns[tour][ant][0]], tour, ant);
				ant++;
			}
			if ((print_all(vs, lem)) != 0)
				error_init(lem, vs, 2);
			turn++;
			my_delay(clock);
		}
		ant = 0;
		while (lem->turns[tour][ant] != NULL)
		{
			vs->ants[lem->turns[tour][ant][0]].turn = 0;
			free_path(vs->ants[lem->turns[tour][ant][0]]);
			ant++;
		}
		tour++;
	}
	vs->bool_end = 1;
}
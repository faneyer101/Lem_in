/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   settings.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 00:28:49 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 16:01:12 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"

void	change_ant_pos(t_visulem *vs, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->nb_ant)
	{
		vs->ants[i].pos.x = vs->rooms[0].x + vs->room_size / 4;
		vs->ants[i].pos.y = vs->rooms[0].y + vs->room_size / 4;
		i++;
	}
}

void	change_size(t_visulem *vs, uint8_t direction)
{
	if (!direction)
	{
		switch (vs->room_size)
		{
		case 40:
			vs->room_size = 20;
			break;

		case 20:
			vs->room_size = 12;
			break;

		case 80:
			vs->room_size = 40;

		default:
			break;
		}
	}
	else
		switch (vs->room_size)
		{
			case 40:
				vs->room_size = 80;
				break;

			case 20:
				vs->room_size = 40;
				break;

			case 12:
				vs->room_size = 20;
				break;

			default:
				break;
		}
}

void    settings(SDL_Event event, t_visulem *vs)
{
    switch (event.key.keysym.sym)
	{
        case SDLK_LEFT:
			change_size(vs, 0);
			break;
		
		case SDLK_RIGHT:
			change_size(vs, 1);
	}
}
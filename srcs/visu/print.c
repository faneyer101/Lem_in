/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 05:45:09 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 18:31:11 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"

int		create_ants(t_visulem *vs, t_lem *lem)
{
	int	i;

	if (SDL_SetRenderDrawColor(vs->renderer, 220, 0, 0, 255) != 0)
		ret_msg(1, "error on RenderColor in create_ants()");
	i = 0;
	while (i < lem->nb_ant)
	{
		vs->ants[i].pos.h = vs->room_size / 2;
		vs->ants[i].pos.w = vs->room_size / 2;
		if (SDL_RenderFillRect(vs->renderer, &vs->ants[i].pos) != 0)
			ret_msg(1, "error on RenderFillRect in create_ants()");
		i++;
	}
	return (0);
}

int		print_all(t_visulem *vs, t_lem *lem)
{
	SDL_Rect rectangle;
	int	nbroom = lem->nb_room - 2;
	int i = 1;
	if ((SDL_RenderClear(vs->renderer)) != 0)
		ret_msg(2, "print_all error while clearing the renderer");
	if ((SDL_RenderCopy(vs->renderer, vs->background, NULL, &vs->bgrect)) != 0)
		ret_msg(2, "print_all error on RenderCopy");
	if ((SDL_SetRenderDrawColor(vs->renderer, 100, 100, 100, 255)) != 0)
		ret_msg(2, "print_all error on RenderDrawColor (For the rooms)");
    while (nbroom > 0)
    {
        rectangle.x = vs->rooms[i].x;
        rectangle.y = vs->rooms[i].y;
        rectangle.w = vs->room_size;
        rectangle.h = vs->room_size;

        if ((SDL_RenderFillRect(vs->renderer, &rectangle)) != 0)
			ret_msg(2, "print_all error while printing the rooms");

        i ++;
		nbroom--;
    }
	if ((drawalllines(lem, vs, vs->rooms)) != 0)
		ret_msg(2, "print_all error while drawing links");
	if ((SDL_SetRenderDrawColor(vs->renderer, 45, 45, 45, 255)) != 0)
		ret_msg(2, "print_all error on RenderDrawColor (For endroom)");
	vs->endroom.h = vs->room_size;
	vs->endroom.w = vs->room_size;
	if ((SDL_RenderFillRect(vs->renderer, &vs->endroom)) != 0)
		ret_msg(2, "print_all error while drawing endroom");
	if ((SDL_SetRenderDrawColor(vs->renderer, 160, 160, 160, 255)) != 0)
		ret_msg(2, "print_all error on RenderDrawColor (For startroom)");
	vs->startroom.h = vs->room_size;
	vs->startroom.w = vs->room_size;
	if ((SDL_RenderFillRect(vs->renderer, &vs->startroom)) != 0)
		ret_msg(2, "print_all error while drawing startroom");
	if ((create_ants(vs, lem)) != 0)
		return(2);
	SDL_RenderPresent(vs->renderer);
	return (0);
}

int		Draw_Fatline(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	if (SDL_RenderDrawLine(renderer, x1 - 1, y1, x2 - 1, y2))
		return(1);
	if (SDL_RenderDrawLine(renderer, x1, y1 - 1, x2, y2 - 1))
		return(1);
	if (SDL_RenderDrawLine(renderer, x1 + 1, y1, x2 + 1, y2))
		return(1);
	if (SDL_RenderDrawLine(renderer, x1, y1 + 1, x2, y2 + 1))
		return(1);

	if (SDL_RenderDrawLine(renderer, x1, y1, x2, y2))
		return(1);
	return(0);
}

int		Draw_BigFatline(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	if (Draw_Fatline(renderer, x1, y1, x2, y2))
		return(1);

	if (SDL_RenderDrawLine(renderer, x1 - 2, y1, x2 - 2, y2))
		return(1);
	if (SDL_RenderDrawLine(renderer, x1, y1 - 2, x2, y2 - 2))
		return(1);
	if (SDL_RenderDrawLine(renderer, x1 + 2, y1, x2 + 2, y2))
		return(1);
	if (SDL_RenderDrawLine(renderer, x1, y1 + 2, x2, y2 + 2))
		return(1);
	return(0);
}

int		drawalllines(t_lem *lem, t_visulem *vs, t_room *room)
{
	int matrixi = 0;
	int matrixj;

	while (matrixi < lem->nb_room)
	{
		matrixj = matrixi;
		while (matrixj < lem->nb_room)
		{
			if (lem->room_matrix[matrixi][matrixj] == '1')
				if ((Draw_BigFatline(vs->renderer, room[matrixi].x + vs->room_size / 2,
				room[matrixi].y + vs->room_size / 2,
				room[matrixj].x + vs->room_size / 2,
				room[matrixj].y + vs->room_size / 2)) != 0)
					ret_msg(1, "Something failed while drawing links between rooms");
			if (lem->room_matrix[matrixi][matrixj] == '2')
				if ((Draw_Fatline(vs->renderer, room[matrixi].x + vs->room_size / 2,
				room[matrixi].y + vs->room_size / 2,
				room[matrixj].x + vs->room_size / 2,
				room[matrixj].y + vs->room_size / 2)) != 0)
					ret_msg(1, "Something failed while drawing links between rooms");
			matrixj++;
		}
		matrixi++;
	}
	return (0);
}
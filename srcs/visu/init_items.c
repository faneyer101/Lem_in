/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_items.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 16:41:46 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 18:31:43 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"

int     init_background(t_visulem *vs)
{
    SDL_Surface *image = NULL;
	vs->background = NULL;
	vs->bgrect.x = 0;
	vs->bgrect.y = 0;
	if (!(image = IMG_Load("srcs/visu/img/background.jpg")))
		return(ret_msg(1, "Error on backgroung image loading\n"));
	if (!(vs->background = SDL_CreateTextureFromSurface(vs->renderer, image)))
        return(ret_msg(1, "Error on vs->background = SDL_CreateTextureFromSurface(vs->renderer, image)\n"));
	SDL_FreeSurface(image);
	SDL_QueryTexture(vs->background, NULL, NULL, &vs->bgrect.w, &vs->bgrect.h);
	if ((SDL_RenderCopy(vs->renderer, vs->background, NULL, &vs->bgrect)) != 0)
        return(ret_msg(1, "Error on SDL_RenderCopy(vs->renderer, vs->background, NULL, &vs->bgrect)\n"));
    return (0);
}

int     init_rooms(t_lem *lem, t_visulem *vs)
{
    int i;

	i = 0;
	if (!(vs->rooms = (t_room*)malloc(sizeof(t_room) * (lem->nb_room))))
	{
		ft_putendl_fd("Could not allocate memory for vs->rooms", 2);
		ft_putendl_fd("Program will exit", 2);
		exit(0);
	}
	while(i < lem->nb_room)
	{
		vs->rooms[i].x = lem->room_coords[i][0];
		vs->rooms[i].y = lem->room_coords[i][1];
		i++;
	}
    i = 1;
    if (SDL_SetRenderDrawColor(vs->renderer, 100, 100, 100, 255) != 0)
        return(ret_msg(1, "error on RenderColor in init_rooms()\n"));
    SDL_Rect rectangle;
	int	nbroom = lem->nb_room - 2;
    while (nbroom > 0)
    {
		rectangle.x = vs->rooms[i].x;
		rectangle.y = vs->rooms[i].y;
		rectangle.w = vs->room_size;
		rectangle.h = vs->room_size;

    	if (SDL_RenderFillRect(vs->renderer, &rectangle) != 0)
			return(ret_msg(1, "error on RenderFillRect in init_rooms()\n"));
		i++;
		nbroom--;
    }
    return (0);
}

int     init_startend(t_lem *lem, t_visulem *vs)
{
    if (SDL_SetRenderDrawColor(vs->renderer, 160, 160, 160, 255)!= 0)
        return(ret_msg(1, "error on RenderColor in init_startend()\n"));
    vs->startroom.x = vs->rooms[0].x;
    vs->startroom.y = vs->rooms[0].y;
    vs->startroom.w = vs->room_size;
    vs->startroom.h = vs->room_size;
    if (SDL_RenderFillRect(vs->renderer, &vs->startroom)!= 0)
        return(ret_msg(1, "error on RenderFillRect in init_startend()\n"));
	if (SDL_SetRenderDrawColor(vs->renderer, 45, 45, 45, 255) != 0)
        return(ret_msg(1, "error on RenderColor in init_startend()\n"));
    vs->endroom.x = vs->rooms[lem->nb_room - 1].x;
    vs->endroom.y = vs->rooms[lem->nb_room - 1].y;
    vs->endroom.w = vs->room_size;
    vs->endroom.h = vs->room_size;
    if (SDL_RenderFillRect(vs->renderer, &vs->endroom) != 0)
        return(ret_msg(1, "error on RenderFillRect in init_startend()\n"));
    return (0);
}

int		init_ants(t_lem *lem, t_visulem *vs)
{
	int	i;

	i = 0;
	if (!(vs->ants = (t_ant*)malloc(sizeof(t_ant) * lem->nb_ant)))
		return(ret_msg(1, "Malloc failed on vs->ants in init_ants()\n"));
	if (SDL_SetRenderDrawColor(vs->renderer, 220, 0, 0, 255) != 0)
		return(ret_msg(2, "error on RenderColor in init_ants()\n"));
	while (i < lem->nb_ant)
	{
		vs->ants[i].pos.h = vs->room_size / 2;
		vs->ants[i].pos.w = vs->room_size / 2;
		vs->ants[i].pos.x = vs->rooms[0].x + vs->room_size / 4;
		vs->ants[i].pos.y = vs->rooms[0].y + vs->room_size / 4;
		if (SDL_RenderFillRect(vs->renderer, &vs->ants[i].pos) != 0)
			return(ret_msg(2, "error on RenderFillRect in init_ants()\n"));
		vs->ants[i].turn = 0;
		i++;
	}
	if (create_ants(vs, lem) != 0)
		return (1);
	return (0);
}

void     init_items(t_lem *lem, t_visulem *vs)
{
	uint8_t	ret;

	ret = 0;
   	if ((ret = init_background(vs)) != 0)
		error_init(lem, vs, ret);
    if ((ret = init_rooms(lem, vs)) != 0)
		error_init(lem, vs, ret);
    if ((ret = init_startend(lem, vs)) != 0)
		error_init(lem, vs, ret);
    if ((ret = drawalllines(lem, vs, vs->rooms)) != 0)
		error_init(lem, vs, ret);
	if ((ret = init_ants(lem, vs)) != 0)
		error_init(lem, vs, ret);
}
/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_vs.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 17:24:17 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 19:54:01 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"

void	error_init(t_lem *lem, t_visulem *vs, uint8_t ret)
{
	int	i;

	i = 0;
	ft_putendl_fd("Program is freeing all allocated memory and will exit", 2);
	while (i < lem->nb_room)
	{
		free(lem->room_matrix[i]);
		free(lem->room_coords[i]);
		i++;
	}
	free(lem->room_matrix);
	free(lem->room_coords);
	if (ret == 1)
		free(vs->rooms);
	if (ret > 1)
	{
		free(vs->ants);
	}
	(void)vs;
	if(NULL != vs->renderer)
        SDL_DestroyRenderer(vs->renderer);
    if(NULL != vs->window)
        SDL_DestroyWindow(vs->window);
    IMG_Quit();
	//TTF_CloseFont(police);
	//TTF_Quit();
    SDL_Quit();
	exit(0);
}

int		ret_msg(uint8_t i, char *msg)
{
    ft_putendl_fd(msg, 2);
    return (i);
}

void	free_path(t_ant ant)
{
    int i;

    i = 0;
    while (i < ant.nbmoves)
    {
		free(ant.path[i]);
		i++;
    }
	free(ant.path);
}
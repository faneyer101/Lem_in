/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu_lemin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:56:58 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 00:28:28 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"
#include <fcntl.h>

void	visu_lemin(t_lem *lem)
{
	t_visulem	vs;
	vs.room_size = 40;
    vs.window = NULL;
    vs.renderer = NULL;
	vs.refreshed_r = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
	//TTF_Init();

	if (lem->biggestxcoord > 2000 || lem->biggestycoord > 1200 || lem->nb_ant > 9999 || lem->nb_room > 99)
	{
		ft_printf("There are some limitations to use the visualizer, for memory, screen size");
		ft_printf(", and because it would be too long and uninteresting to watch\n");
		ft_printf("Limits are:\n");
		ft_printf("-Window size 2000x1200 max, check the coords of your rooms\n");
		ft_printf("-Maximum number of ants is 9999\n");
		ft_printf("-Maximum number of rooms is 99\n");
		error_init(lem, &vs, 0);
	}

    // Rendu de base (fond)
	int	window_width = lem->biggestxcoord + 100;
	int	window_height = lem->biggestycoord + 100;
    if ((SDL_CreateWindowAndRenderer(window_width, window_height, 0, &vs.window, &vs.renderer)) != 0)
		error_init(lem, &vs, 0);

	init_items(lem, &vs);



	// Jeu d'essai avec liste chainee //////////
	// Jeu d'essai avec liste chainee //////////
	// Jeu d'essai avec liste chainee //////////
	ft_printf("\n\n");
	lem->nb_turn = 0;

	int		fd = open("visu.map", O_RDONLY);
	char	*line;

	lem->begin_answer = (t_list_answ*)malloc(sizeof(t_list_answ));
	lem->answer = lem->begin_answer;
	while (get_next_line(fd, &line))
	{
		lem->answer->line = ft_strdup(line);
		lem->answer->next = (t_list_answ*)malloc(sizeof(t_list_answ));
		lem->answer = lem->answer->next;
		lem->nb_turn++;
		ft_strdel(&line);
	}
	lem->answer->next = NULL;

	lem->answer = lem->begin_answer;
	parse_answer(lem, &vs);


	vs.bool_end = 0;
	SDL_bool program_launched = SDL_TRUE;

	while(program_launched)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				
				case SDL_KEYDOWN:
					if (vs.bool_end)
					{
						program_launched = SDL_FALSE;
						break;
					}
					settings(event, &vs);
					change_ant_pos(&vs, lem);
					if ((print_all(&vs, lem)) != 0)
						error_init(lem, &vs, 2);
					break;

				case SDL_MOUSEBUTTONDOWN:
					if (vs.bool_end)
					{
						program_launched = SDL_FALSE;
						break;
					}
					allmoves(lem, &vs);
					break;

				default:
					break;
			}
			if ((print_all(&vs, lem)) != 0)
				error_init(lem, &vs, 2);
		}
	}

    //  
    // Destroy et termine
	//free_turns(lem);
	free_parsed(lem);
    if(NULL != vs.renderer)
        SDL_DestroyRenderer(vs.renderer);
    if(NULL != vs.window)
        SDL_DestroyWindow(vs.window);
    IMG_Quit();
	//TTF_CloseFont(police);
	//TTF_Quit();
    SDL_Quit();
}
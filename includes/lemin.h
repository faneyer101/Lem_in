/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 14:22:40 by faneyer      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 01:19:25 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft_nsalle/libft.h"
# include "../sdl2/SDL.h"

typedef struct			s_ts_ant
{
	int					ipos;
	int					num;
	int					*path;
}						t_ts_ant;

typedef struct			s_translate
{
	int					turn;
	int					nbturn;
	int					nbpath;
	int					l_path;
	int					onboard;
	int					remaining;
	int					finished;
	t_ts_ant			*allants;
	struct s_list_answ	*antlist;
	struct s_list_answ	*s_antlist;
}						t_translate;

typedef struct			s_list_answ
{
	char				*line;
	struct s_list_answ	*next;
}						t_list_answ;

typedef struct			s_list_path
{
	int					*path;
	int					size;
	struct s_list_path	*next;
}						t_list_path;

typedef struct			s_ant
{
	SDL_Rect			pos;
	int					**path;
	int					nbmoves;
	int					turn;
}						t_ant;

typedef struct			s_room
{
	int					x;
	int					y;
}						t_room;

typedef struct			s_rooms
{
	char				*name;
	char				start;
	char				end;
}						t_rooms;

typedef struct			s_resolv
{
	t_list_path			*list;
	int					etage;
	int					colone;
	int					size;
	int					ok;
	int					soluce;
	int					nbturn;
}						t_resolv;

typedef struct			s_soluce
{
	int					**path;
	t_list_path			**listpath;
	t_list_path			**pathsoluce;
}						t_soluce;

typedef struct			s_lem
{
	char				**room_matrix;
	char				**tabfile;
	int					nblinks;
	char				startfound;
	char				endfound;
	int					startindex;
	int					endindex;
	int					curs;
	int					**room_coords;
	int					biggestxcoord;
	int					biggestycoord;
	int					***turns;
	char				*start;
	char				*end;
	int					i_parsingline;
	int					*shortest_path;
	int					nb_path;
	t_rooms				*rooms;
	int					nb_room;
	long long int		nb_ant;
	int					nb_path_max;
	t_soluce			soluce;
	int					**tab_ant;
	t_list_path			**tab_soluce;

	int					nb_turn;
	int					clvl;
	int					*level;
	int					*bookmark;
	t_list_path			*b_queue;
	t_list_path			*queue;
	t_list_answ			*begin_answer;
	t_list_answ			*answer;
	t_list_path			*begin_path;
	t_list_path			*path;
	t_list_path			*save;
}						t_lem;

typedef	struct			s_visulem
{
	SDL_Window			*window;
	uint8_t				room_size;
	SDL_Renderer		*renderer;
	SDL_Renderer		*refreshed_r;
	SDL_Texture			*background;
	SDL_Rect			bgrect;
	SDL_Rect			startroom;
	SDL_Rect			endroom;
	SDL_Rect			antrect;
	t_room				*rooms;
	t_ant				*ants;
	char				bool_end;
}						t_visulem;

void					exit_lemin(void);
void					lem_parsing(t_lem *lem);
void					exit_early_parsing(t_lem *lem);
void					exit_after_rooms(t_lem *lem);
void					free_tabfile(t_lem *lemin);
void					error_matrix(t_lem *lem, int bool);
void					error_get_roomname(t_lem *lem, char **r1, char **r2);

char					*clean_join(char *s1, char *s2);
char					*file_to_line(void);

void					parse_rooms(t_lem *lem);
void					remove_paths(t_lem *lem);

void					check_dupe_roomname(t_lem *lem);
void					check_com_cut(t_lem *lem, int i, char start);
void					check_roomerrors(t_lem *lem);
void					check_emptyline(char *line);

void					parse_coords(t_lem *lem);
void					check_coords(char **tab, t_lem *lem);
void					visu_lemin(t_lem *lem);
int						drawalllines(t_lem *lem, t_visulem *vs, t_room *room);
int						print_all(t_visulem *vs, t_lem *lem);
int						create_ants(t_visulem *vs, t_lem *lem);
void					free_path(t_ant ant);
void					error_init(t_lem *lem, t_visulem *vs, uint8_t ret);
int						ret_msg(uint8_t i, char *msg);
void					init_items(t_lem *lem, t_visulem *vs);
int						bresenham(SDL_Rect *rect, int x2, int y2, int **path);
void					settings(SDL_Event event, t_visulem *vs);
void					change_ant_pos(t_visulem *vs, t_lem *lem);
void					allmoves(t_lem *lem, t_visulem *vs);
void					parse_answer(t_lem *lem, t_visulem *vs);
void					matrix_next(t_lem *lem, int i, int j);

int						find_end(t_lem *lem);
void					store_all_paths(t_lem *lem, int *path);
int						*tabdup(int *tab, int *size, t_lem *lem);
void					remove_last_path(int *path);
void					add_to_path(int *path, int c);
size_t					get_tab_size(int *tab);

void					translate_answ(t_lem *lem);
void					remove_longest(t_lem *lem, t_translate *info);

int						nbturn(t_lem *lem, t_translate *info, int nb_ant,
							int turn);
t_list_path				*create_path(int size, int *path, t_lem *lem);
t_list_path				*destroy_firstq(t_list_path *begin_queue);
t_list_path				*push_queue(t_list_path *begin_queue, int *path,
							t_lem *lem);
t_list_path				*found_bm(t_lem *lem, t_list_path *cur);

void					test(t_lem *lem);
void					print_all_paths(t_lem *lem);
void					print_path(int *path, t_lem *lem, int size);

int						init_range_list(t_lem *lem);
int						init_solution(t_lem *lem);
int						already_visited(int *path, int room);

int						create_tab_ant(t_lem *lem, t_resolv solver, int	nbant);
void					init_tab_soluce(t_lem *lem, t_list_path **stab_soluce);
int						start_tab_soluce(t_lem *lem, t_resolv solver,
							t_list_path **tab_soluce);
int						search_best_solution(t_lem *lem,
							t_list_path **tab_soluce, t_resolv *solver);
void					init_struct(t_lem *lem, t_resolv *solver, int a);
void					free_list_path(t_lem *lem);
int						free_tab_soluce(int isize, t_list_path **tab,
							int jsize);
void					free_parsed(t_lem *lem);
#endif

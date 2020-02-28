/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 19:47:37 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 16:01:14 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lemin.h"
#include "../../sdl2/SDL.h"

int			bresenham(SDL_Rect *rect, int x2, int y2, int **path)
{
	int x, y;
	int Dx,Dy;
  	int xincr,yincr;
  	int erreur;
  	int i;
	int count = 0;
	
	Dx = ft_abs(x2 - rect->x);
  	Dy = ft_abs(y2 - rect->y);
	if(rect->x < x2)
        xincr = 1;
  	else
        xincr = -1;
  	if(rect->y < y2)
        yincr = 1;
  	else
        yincr = -1;
  	x = rect->x;
  	y = rect->y;
  	if(Dx > Dy)
    {
        erreur = Dx / 2;
        i = 0;
        while (i < Dx)
        {
            x += xincr;
            erreur += Dy;
            if (erreur > Dx)
            {
                erreur -= Dx;
                y += yincr;
            }
		    path[count] = (int*)malloc(sizeof(int) * 2);
		    path[count][0] = x;
		    path[count][1] = y;
		    count++;
            i++;
        }
    }
    else
    {
        erreur = Dy / 2;
        i = 0;
        while (i < Dy)
        {
            y += yincr;
            erreur += Dx;
            if (erreur>Dy)
            {
                erreur -= Dy;
                x += xincr;
            }
		path[count] = (int*)malloc(sizeof(int) * 2);
		path[count][0] = x;
		path[count][1] = y;
		count++;
        i++;
        }
    }
	return(count);
}
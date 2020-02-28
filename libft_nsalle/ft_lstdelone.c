/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelone.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 20:03:34 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 22:14:57 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Takes as a parameter a link’s pointer address and frees the
**	memory of the link’s content using the function del given as
**	a parameter, then frees the link’s memory using free(3). The
**	memory of next must not be freed under any circumstance.
**	Finally, the pointer to the link that was just freed must be
**	set to NULL (quite similar to the function ft_memdel in the
**	mandatory part).
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *freel;

	if (alst && *alst)
	{
		freel = *alst;
		del(freel, sizeof(freel));
		*alst = NULL;
	}
}

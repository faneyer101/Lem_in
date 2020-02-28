/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 20:03:34 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 22:14:58 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Takes as a parameter the adress of a pointer to a link and
**	frees the memory of this link and every successors of that link
**	using the functions del and free(3). Finally the pointer to
**	the link that was just freed must be set to NULL (quite similar
**	to the function ft_memdel from the mandatory part).
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *freel;

	if (alst && *alst)
	{
		while (*alst)
		{
			freel = *alst;
			*alst = (*alst)->next;
			del(freel, sizeof(freel));
		}
		*alst = NULL;
	}
}

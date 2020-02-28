/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpush_back.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:25 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:55:00 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstpush_back adds a new element of type t_list to the
**	end of the list. It assigns data to the given argument.
**	If necessary, it'll update the pointer at the beginning of the list.
*/

#include "libft.h"

void	ft_lstpush_back(t_list **alst, void *content)
{
	if (*alst)
	{
		if ((*alst)->next)
			ft_lstpush_back(&(*alst)->next, content);
		else
			(*alst)->next = ft_lstcreate(content);
	}
	else
		*alst = ft_lstcreate(content);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpush_front.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:28 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:55:00 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstpush_front adds a new element of type t_list to the
**	beginning of the list. It assigns data to the given argument.
**	If necessary, it'll update the pointer at the beginning of the list.
*/

#include "libft.h"

void	ft_lstpush_front(t_list **alst, void *data)
{
	t_list	*list;

	list = ft_lstcreate(data);
	if ((*alst))
		list->next = *alst;
	*alst = list;
}

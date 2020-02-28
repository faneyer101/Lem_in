/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstremove_if.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:36 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:58:28 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstremove_if erases the elements of which the data is equal
**	to the reference data off the list.
*/

#include "libft.h"

void	ft_lstremove_if(t_list **begin_list, void *content_ref, int (*cmp)())
{
	t_list	*to_free;

	if (*begin_list)
	{
		if (cmp((*begin_list)->content, content_ref) == 0)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			free(to_free);
			ft_lstremove_if(begin_list, content_ref, cmp);
		}
		else
			ft_lstremove_if(&(*begin_list)->next, content_ref, cmp);
	}
}

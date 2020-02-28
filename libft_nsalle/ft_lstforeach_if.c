/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstforeach_if.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:06 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:58:02 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstforeach_if applies a function given as argument to the
**	information held in some links of the list. A reference information as well
**	as a comparative function should allow us to select the right links of the
**	list, thus those that are equal to the reference information.
*/

#include "libft.h"

void	ft_lstforeach_if(t_list *lst, void (*f)(void *),
		void *content_ref, int (*cmp)())
{
	if (lst)
	{
		if ((*cmp)(lst->content, content_ref) == 0)
			f(lst->content);
		if (lst->next)
			ft_lstforeach_if(lst->next, f, content_ref, cmp);
	}
}

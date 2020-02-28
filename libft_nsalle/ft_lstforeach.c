/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstforeach.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:09 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:58:05 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstforeach applies a function given as argument to the
**	information within each of the list's links.
*/

#include "libft.h"

void	ft_lstforeach(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		f(lst->content);
		ft_lstforeach(lst->next, f);
	}
}

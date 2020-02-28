/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmerge.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:21 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:33:19 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstmerge places elements of lst2 at the end of an alst1;
*/

#include "libft.h"

void	ft_lstmerge(t_list **alst1, t_list *lst2)
{
	if ((*alst1) == NULL)
		*alst1 = lst2;
	else if ((*alst1)->next == NULL)
		(*alst1)->next = lst2;
	else
		ft_lstmerge(&((*alst1)->next), lst2);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsize.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:48 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:58:41 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstsize returns the number of elements in the list.
*/

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	return (ft_lstsize(lst->next) + 1);
}

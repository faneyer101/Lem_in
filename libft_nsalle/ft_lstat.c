/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 03:38:38 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:16:56 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstat returns the Nth element of the list.
**	In case of error, it returns a null pointer.
*/

#include "libft.h"

t_list	*ft_lstat(t_list *lst, unsigned int nbr)
{
	if (!lst)
		return (NULL);
	while (nbr-- && lst)
		lst = lst->next;
	return (lst);
}

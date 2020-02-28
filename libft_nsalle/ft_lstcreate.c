/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstcreate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/18 00:02:49 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:54:11 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Allocates (with malloc(3)) and returns a new element of t_list type.
*/

#include "libft.h"

t_list	*ft_lstcreate(void *content)
{
	t_list *link;

	if (!(link = malloc(sizeof(t_list))))
		return (NULL);
	link->content = content;
	link->next = NULL;
	return (link);
}

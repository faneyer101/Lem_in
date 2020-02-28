/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstpush_params.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 20:35:32 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 20:50:36 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The function ft_lstpush_params creates a new list incluiding command-line
**	arguments. The first argument will be at the end of the list.
**
**		RETURN VALUE
**	The first link's address in the list is returned.
*/

#include "libft.h"

t_list	*ft_lstpush_params(int ac, char **av)
{
	int		i;
	t_list	*list;

	list = NULL;
	i = 1;
	if (ac)
		while (i < ac)
		{
			ft_lstpush_front(&list, av[i]);
			i++;
		}
	return (list);
}

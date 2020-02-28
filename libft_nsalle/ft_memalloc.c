/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:08:36 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:10:58 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Allocates (with malloc(3)) and returns a “fresh” memory
**	area. The memory allocated is initialized to 0. If the allocation
**	fails, the function returns NULL.
**
**		RETURN VALUE
**	The allocated memory area.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	return (ft_memset(mem, 0, size));
}

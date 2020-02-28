/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:23:02 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 19:59:14 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The  memmove()  function  copies  n bytes from memory area src to memory
**	area dest.  The memory areas may overlap: copying takes place as though the
**	bytes in src are first copied into a temporary array that does not overlap
**	src or dest, and the bytes are then copied from the temporary array to dest.
**
**		RETURN VALUE
**	The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = (char *)dest;
	sp = (const char*)src;
	if (sp < dp)
	{
		sp += n;
		dp += n;
		while (n--)
			*--dp = *--sp;
	}
	else if (sp != dp)
		ft_memcpy(dp, sp, n);
	return (dest);
}

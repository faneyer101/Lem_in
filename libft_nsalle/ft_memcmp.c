/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:17:02 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:17:33 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to be n bytes long.
**
**		RETURN VALUE
**	The memcmp() function returns zero if the two strings are identical,
**	otherwise returns the difference between the first two differing bytes
**	(treated as unsigned char values, so that `\200' is greater than `\0',
**	for example).  Zero-length strings are always identical.
**	This behavior is not required by C and portable code should only depend on
**	the sign of the returned value.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	if (n)
	{
		p1 = s1;
		p2 = s2;
		while (n--)
		{
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
		}
	}
	return (0);
}

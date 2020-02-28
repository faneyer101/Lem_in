/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 06:08:07 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 22:13:00 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Appends src to string dst of size siz (unlike strncat, siz is the full size
**	of dst, not space left).  At most siz-1 characters will be copied.
**	Always NUL terminates (unless siz <= strlen(dst)).
**
**		RETURN VALUE
**	Returns strlen(src) + MIN(siz, strlen(initial dst)).
** 	If retval >= siz, truncation occurred.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (dest[i])
		i++;
	res = 0;
	while (src[res])
		res++;
	res += size <= i ? size : i;
	j = 0;
	while (src[j] && (i + 1) < size)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 17:44:31 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:24:58 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*d;

	if (!n)
		return (dst);
	d = dst;
	while (n && *src)
	{
		*dst++ = *src++;
		n--;
	}
	while (n)
	{
		*dst++ = '\0';
		n--;
	}
	return (d);
}

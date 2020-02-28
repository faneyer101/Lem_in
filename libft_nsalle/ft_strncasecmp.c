/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncasecmp.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:59:15 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 23:53:33 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The strcasecmp() function compares the two strings s1 and s2, ignoring the
**	case of the characters. It returns an integer less than, equal to, or
**	greater than zero if s1 is found, respectively, to be less than, to match,
**	or be greater than s2.
**	The strncasecmp() function is similar, except it only compares the first n
**	bytes of s1.
**
**		RETURN VALUE
**	The strcasecmp() and strncasecmp() functions return an integer less than,
**	equal to, or greater than zero if s1 (or the first n bytes thereof) is found
**	respectively, to be less than, to match, or be greater than s2.
*/

#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	int					result;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	if (p1 == p2)
		return (0);
	while (n-- && (result = ft_tolower(*p1) - ft_tolower(*p2++)) == 0)
		if (*p1++ == '\0')
			break ;
	return (result);
}

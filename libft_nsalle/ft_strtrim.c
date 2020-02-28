/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:19:10 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 20:33:44 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Allocates (with malloc(3)) and returns a copy of the string given as
**	argument without whitespaces at the beginning or at the end of the string.
**	Will be considered as whitespaces the following characters ’ ’, ’\n’ and
**	’\t’. If s has no whitespaces at the beginning or at the end, the function
**	returns a copy of s. If the allocation fails the function returns NULL.
**
**		RETURN VALUE
**	The “fresh” trimmed string or a copy of s.
*/

#include "libft.h"

static int	ft_iswhitespace(int c)
{
	return (c == 32 || (9 <= c && c <= 10));
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	start = 0;
	if (!s)
		return (NULL);
	while (ft_iswhitespace(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[len]))
		len--;
	return (ft_strsub(s, start, len - start + 1));
}

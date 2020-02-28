/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 23:27:20 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:14:56 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The strrchr() function returns a pointer to the last occurrence of the
**	character c in the string s.
**
**		RETURN VALUE
**	The  strrchr() function returns a pointer to the matched character or NULL
**	if the character is not found.
**	The terminating null byte is considered part of the string, so that if c is
**	specified as '\0', these functions return a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*str;

	str = s;
	str = str + ft_strlen(s);
	while (*str != (char)c && str != s)
		str--;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

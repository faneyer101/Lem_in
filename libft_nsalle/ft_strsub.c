/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:16:13 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:13:04 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Allocates (with malloc(3)) and returns a “fresh” substring
**	from the string given as argument. The substring begins at
**	index start and is of size len. If start and len aren’t refering
**	to a valid substring, the behavior is undefined. If the
**	allocation fails, the function returns NULL.
**
**		RETURN VALUE
**	The substring.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s || !(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	while (start--)
		s++;
	str = ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}

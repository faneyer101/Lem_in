/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:57:06 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:15:22 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Applies the function f to each character of the string given
**	as argument to create a “fresh” new string (with malloc(3))
**	resulting from the successive applications of f.
**
**		RETURN VALUE
**	The “fresh” string created from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (str - len);
}

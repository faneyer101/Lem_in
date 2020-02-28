/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:58:48 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:37:13 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Applies the function f to each character of the string passed
**	as argument by giving its index as first argument to create a
**	“fresh” new string (with malloc(3)) resulting from the successive
**	applications of f.
**
**		RETURN VALUE
**	The “fresh” string created from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (*s)
		*str++ = f(i++, *(s++));
	*str = '\0';
	return (str - i);
}

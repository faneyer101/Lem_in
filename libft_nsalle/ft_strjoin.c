/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:17:32 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 20:36:57 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’,
**	result of the concatenation of s1 and s2. If the allocation fails the
**	function returns NULL.
**
**		RETURN VALUE
**	The “fresh” string result of the concatenation of the 2 strings.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if ((!s1 || !s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

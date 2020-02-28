/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:12:32 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 00:53:38 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Lexicographical comparison between s1 and s2 up to n characters
**	or until a ’\0’ is reached. If the 2 strings are identical,
**	the function returns 1, or 0 otherwise.
**
**		RETURN VALUE
**	1 or 0 according to if the 2 strings are identical or not.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (s1 && s2)
		if (!ft_strncmp(s1, s2, n))
			return (1);
	return (0);
}

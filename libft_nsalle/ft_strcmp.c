/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 23:32:38 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:07:15 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The strcmp() function lexicographically compares the null-terminated strings
**	s1 and s2.
**
**		RETURN VALUE
**	The strcmp() function returns an integer greater than, equal to, or less
**	than 0, according as the string s1 is greater than, equal to, or less than
**	the string s2.
**	The comparison is done using unsigned characters, so that `\200' is greater
**	than `\0'.
*/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
		s1++ && s2++;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

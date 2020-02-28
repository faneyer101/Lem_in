/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wordcount.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 01:27:15 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 20:13:44 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Counts the amount of whole words between the set character(s) c in the
**	string s.
**
**		RETURN VALUE
**	Number of words.
*/

#include "libft.h"

size_t		ft_wordcount(const char *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

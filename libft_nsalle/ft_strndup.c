/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/12 00:53:11 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 10:19:47 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The strndup() function is similar, but copies at most n bytes.  If s is
**	longer than n, only n bytes are copied, and a terminating null byte ('\0')
**	is added.
**
**		RETURN VALUE
**	On success the strdup() function returns a pointer to the duplicated string.
**	It returns NULL if insufficient memory was available, with errno set to
**	indicate the cause of the error.
*/

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *dp;

	if (!(dp = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(dp, s, n);
	dp[n] = '\0';
	return (dp);
}

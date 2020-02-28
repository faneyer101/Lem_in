/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:20:04 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 16:04:21 by faneyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Allocates (with malloc(3)) and returns an array of “fresh” strings (all
**	ending with ’\0’, including the array itself) obtained by spliting s using
**	the character c as a delimiter. If the allocation fails the function returns
**	NULL.
**	Example : ft_strsplit("*hello*fellow***students*", ’*’) returns the array
**	["hello", "fellow", "students"].
**
**		RETURN VALUE
**	The array of “fresh” strings result of the split.
*/

#include "libft.h"

static char		*ft_strdupn(const char *src, int n, size_t len)
{
	char	*str;
	size_t	i;

	if (!len)
		return (0);
	if (!(str = malloc(sizeof(*src) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[n + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		**ft_fill(char **tab, const char *str, char c)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			len = 0;
			while (str[i] && str[i] != c)
			{
				i++;
				len++;
			}
			tab[j++] = ft_strdupn(str, (i - len), len);
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit(const char *str, char c)
{
	char **tab;

	if (!str || !(tab = malloc(sizeof(char *) * (ft_wordcount(str, c) + 1))))
		return (NULL);
	tab = ft_fill(tab, str, c);
	return (tab);
}

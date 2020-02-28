/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strspn.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 14:38:39 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 14:49:32 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(char *s, char *accept)
{
	size_t	i;
	size_t	j;
	size_t	boobool;

	i = 0;
	boobool = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				boobool = 1;
				break ;
			}
			j++;
		}
		if (!boobool)
			return (i);
		boobool = 0;
		i++;
	}
	return (i);
}

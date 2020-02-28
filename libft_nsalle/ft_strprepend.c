/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strprepend.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 00:26:29 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 19:30:44 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strprepend(char *str, int nb, char c, int skip)
{
	int		i;
	int		j;
	char	*buff;

	if (nb > 0)
	{
		i = 0 + skip;
		if (!(buff = ft_strdup(str + i)))
			return (NULL);
		j = 0;
		while (nb--)
			str[i++] = c;
		while (buff[j])
			str[i++] = buff[j++];
		str[i] = '\0';
		ft_memdel((void*)&buff);
	}
	return (str);
}

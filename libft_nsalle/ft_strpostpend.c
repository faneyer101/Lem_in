/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strpostpend.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 00:27:32 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 22:06:24 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strpostpend(char *str, int nb, char c)
{
	int	i;

	i = ft_strlen(str);
	while (nb--)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

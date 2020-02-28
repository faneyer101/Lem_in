/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_reverse_bits.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:47:18 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:47:21 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_bits(unsigned char bit)
{
	int				i;
	unsigned char	last;
	unsigned char	reversed;

	i = 0;
	reversed = 0;
	while (i < 7)
	{
		last = bit & 1;
		bit >>= 1;
		reversed += last;
		reversed <<= 1;
		i++;
	}
	return (reversed);
}

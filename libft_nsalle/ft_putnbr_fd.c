/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:38:40 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:42:53 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Outputs the integer n to the file descriptor fd.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n < 0)
		ft_putchar_fd('-', fd);
	nb = (n < 0 ? -n : n);
	if (nb > 9)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd(((nb % 10) + 48), fd);
}

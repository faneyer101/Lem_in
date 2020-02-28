/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:38:09 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:37:50 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Outputs the char c to the file descriptor fd.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	(void)write(fd, &c, 1);
}

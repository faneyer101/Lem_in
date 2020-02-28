/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isascii.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:55:47 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:02:02 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Checks whether c is a 7-bit unsigned char value that fits into the ASCII
**	character set.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

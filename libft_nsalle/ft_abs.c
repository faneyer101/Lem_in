/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_abs.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:43:05 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 11:23:49 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Returns the absolute value of the given integer.
*/

#include "libft.h"

long long int	ft_abs(long long int n)
{
	return ((n < 0) ? -n : n);
}

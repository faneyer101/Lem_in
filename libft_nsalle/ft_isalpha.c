/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isalpha.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:54:50 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:20:25 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Checks for an alphabetic character; in the standard "C" locale, it is
**	equivalent to (isupper(c) || islower(c)).  In some locales, there may be
**	additional characters for which isalpha()  is  true—letters which are
**	neither uppercase nor lowercase.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}

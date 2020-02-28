/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isxdigit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 23:35:12 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 02:04:28 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The isxdigit() function tests for any hexadecimal-digit character.
**	Regardless of locale, this includes the following characters only:
**
**	``0''         ``1''         ``2''         ``3''         ``4''
**	``5''         ``6''         ``7''         ``8''         ``9''
**	``A''         ``B''         ``C''         ``D''         ``E''
**	``F''         ``a''         ``b''         ``c''         ``d''
**	``e''         ``f''
**
**	The ishexnumber() function behaves similarly to isxdigit(), but may
**	recognize additional characters, depending on the current locale setting.
**	The value of the argument must be representable as an unsigned char or
**	the value of EOF.
**
**		RETURN VALUE
**	The isxdigit() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'));
}

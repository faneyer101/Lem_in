/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_islower.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:58:30 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 02:06:19 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The islower() function tests for any lower-case letters.  The value of
**	the argument must be representable as an unsigned char or the value of EOF.
**	In the ASCII character set, this includes the following characters
**	(with their numeric values shown in octal):
**
**	141 ``a''     142 ``b''     143 ``c''     144 ``d''     145 ``e''
**	146 ``f''     147 ``g''     150 ``h''     151 ``i''     152 ``j''
**	153 ``k''     154 ``l''     155 ``m''     156 ``n''     157 ``o''
**	160 ``p''     161 ``q''     162 ``r''     163 ``s''     164 ``t''
**	165 ``u''     166 ``v''     167 ``w''     170 ``x''     171 ``y''
**	172 ``z''
**
**		RETURN VALUE
**	The islower() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

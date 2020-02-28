/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iscntrl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:56:52 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 02:06:19 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The iscntrl() function tests for any control character.  The value of
**	the argument must be representable as an unsigned char or the value of EOF.
**	In the ASCII character set, this includes the following characters
**	(preceded by their numeric values, in octal):
**
**	000 NUL       001 SOH       002 STX       003 ETX       004 EOT
**	005 ENQ       006 ACK       007 BEL       010 BS        011 HT
**	012 NL        013 VT        014 NP        015 CR        016 SO
**	017 SI        020 DLE       021 DC1       022 DC2       023 DC3
**	024 DC4       025 NAK       026 SYN       027 ETB       030 CAN
**	031 EM        032 SUB       033 ESC       034 FS        035 GS
**	036 RS        037 US        177 DEL
**
**		RETURN VALUE
**	The iscntrl() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

#include "libft.h"

int		ft_iscntrl(int c)
{
	return ((0 <= c && c <= 31) || c == 127);
}

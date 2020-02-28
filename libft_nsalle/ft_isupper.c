/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isupper.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 23:35:22 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 02:01:11 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The isupper() function tests for any upper-case letter.  The value of
**	the argument must be representable as an unsigned char or the value of EOF.
**	In the ASCII character set, this includes the following characters
**	(preceded by their numeric values, in octal):
**
**	101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
**	106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
**	113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
**	120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
**	125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
**	132 ``Z''
**
**		RETURN VALUE
**	The isupper() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

#include "libft.h"

int		ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

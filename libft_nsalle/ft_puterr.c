/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puterr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 00:33:20 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 00:33:25 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	Outputs an error message as a string to the error output followed by a ’\n’.
*/

#include "libft.h"

void	ft_puterr(char const *error)
{
	ft_putendl_fd(error, 2);
}

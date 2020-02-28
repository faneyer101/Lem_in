/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 15:39:04 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:07:02 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_struct_resetter(t_printf *pf)
{
	*pf = (t_printf){NULL, 'a', 0.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		pf->nbc, pf->type};
}

void	pf_flag_cleaner(t_printf *pf)
{
	if (pf->type == 'x' || pf->type == 'X' || pf->type == 'o' ||
		pf->type == 'u' || pf->tp < 0)
	{
		pf->plus = 0;
		pf->space = 0;
	}
	pf->zero = (pf->moins || pf->precibool) ? 0 : pf->zero;
	pf->space = pf->plus ? 0 : pf->space;
	if (pf->plus && pf->tp < 0)
		pf->plus = 0;
	if (pf->plus)
		pf->space = 0;
	if (pf->sharp && (pf->type == 'x' || pf->type == 'X'))
		pf->sharp = 2;
}

void	pf_size_parser(t_printf *pf, const char *format)
{
	if (format[0] == 'l' && format[1] != 'l')
		pf->size = 'l';
	if (format[0] == 'l' && format[1] == 'l')
		pf->size = 'L';
	if (format[0] == 'h' && format[1] != 'h')
		pf->size = 'h';
	if (format[0] == 'h' && format[1] == 'h')
		pf->size = 'H';
	if (format[0] == 'L')
		pf->size = 'F';
	if (format[0] == 'b' || format[0] == 'B')
	{
		pf->size = format[0];
		pf->base = ft_atoi(format + 1);
	}
}

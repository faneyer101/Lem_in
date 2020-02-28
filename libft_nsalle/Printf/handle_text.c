/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_text.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 21:07:12 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:07:05 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		pf_char_handler(va_list va, t_printf *pf)
{
	char	to_print;
	int		width;
	size_t	nullchar;

	pf_buffer_alloc(&pf->buff, 1, pf);
	to_print = va_arg(va, int);
	nullchar = 0;
	if (!to_print)
		nullchar = 1;
	pf->buff[0] = to_print;
	width = (pf->width - (ft_strlen(pf->buff))) - nullchar;
	if (width > 0 && !pf->moins)
		pf_strprepend(pf->buff, width, (pf->zero ? '0' : ' '), 0);
	if (width > 0 && pf->moins)
		ft_strpostpend(pf->buff, width, ' ');
	write(1, pf->buff, ft_strlen(pf->buff) + nullchar);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)) + nullchar);
}

int		pf_text_handler(char const *format, va_list va, t_printf *pf)
{
	int		width;
	char	*sto_print;

	if (format[pf->nbc] == 'c')
		return (pf_char_handler(va, pf));
	sto_print = va_arg(va, char *);
	if (!sto_print)
	{
		sto_print = "(null)";
		pf_buffer_alloc(&pf->buff, 6, pf);
	}
	else
		pf_buffer_alloc(&pf->buff, ft_strlen(sto_print), pf);
	if (pf->precibool)
		ft_strncpy(pf->buff, sto_print, MIN(pf->precival,
		ft_strlen(sto_print)));
	else
		ft_strcpy(pf->buff, sto_print);
	width = pf->width - ft_strlen(pf->buff);
	if (width > 0 && !pf->moins)
		pf_strprepend(pf->buff, width, (pf->zero ? '0' : ' '), 0);
	if (width > 0 && pf->moins)
		ft_strpostpend(pf->buff, width, ' ');
	ft_putstr(pf->buff);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)));
}

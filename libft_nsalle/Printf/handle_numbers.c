/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_numbers.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 21:04:36 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:07:14 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_int_handler(const char *format, va_list va, t_printf *pf, int base)
{
	int	i;

	pf_number_buffer(pf, va, base);
	i = pf->precival - pf_count_digits(pf->buff, 0) - (pf->sharp == 1);
	pf_strprepend(pf->buff, i, '0', (pf->tp <= 0));
	i = pf->width - ft_strlen(pf->buff) - pf->plus - pf->space;
	if (pf->moins && i > 0)
		ft_strpostpend(pf->buff, i, ' ');
	if (pf->zero && i > 0)
		pf_strprepend(pf->buff, i, '0', (pf->tp <= 0));
	pf_strprepend(pf->buff, pf->width - ft_strlen(pf->buff)
				- (pf->plus + pf->space), ' ', 0);
	pf_add_plus(pf);
	if (pf->space && pf->tp >= 0)
		pf_strprepend(pf->buff, 1, ' ', 0);
	pf_add_sharp(pf, format[pf->nbc]);
	pf->buff = pf->size == 'B' ? ft_strtoupper(pf->buff) : pf->buff;
	ft_putstr(pf->buff);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)));
}

int	pf_uint_handler(const char *format, va_list va, t_printf *pf, int base)
{
	int	i;

	pf_number_buffer(pf, va, base);
	i = pf->precival - pf_count_digits(pf->buff, 0) - (pf->sharp == 1);
	pf_strprepend(pf->buff, i, '0', (pf->utp == 0));
	i = pf->width - ft_strlen(pf->buff) - pf->plus - pf->space;
	if (pf->moins && i > 0)
		ft_strpostpend(pf->buff, i, ' ');
	if (pf->zero && i > 0)
		pf_strprepend(pf->buff, i, '0', (pf->utp == 0));
	pf_strprepend(pf->buff, pf->width - ft_strlen(pf->buff)
		- (pf->plus + pf->space), ' ', 0);
	if (pf->space)
		pf_strprepend(pf->buff, 1, ' ', 0);
	pf_add_sharp(pf, format[pf->nbc]);
	ft_putstr(pf->buff);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)));
}

int	pf_hexa_handler(const char *format, va_list va, t_printf *pf, int base)
{
	int	i;
	int	nb;

	pf_number_buffer(pf, va, base);
	nb = pf->utp == 0 ? 0 : pf->sharp;
	i = pf->precival - pf_count_digits(pf->buff, 1);
	pf_strprepend(pf->buff, i, '0', 0);
	i = pf->width - ft_strlen(pf->buff) - nb;
	if (pf->moins && i > 0)
		ft_strpostpend(pf->buff, i, ' ');
	if (pf->zero && i > 0)
		pf_strprepend(pf->buff, i, '0', 0);
	i = pf->width - ft_strlen(pf->buff) - nb;
	pf_strprepend(pf->buff, i, ' ', 0);
	pf_add_sharp(pf, format[pf->nbc]);
	pf->buff = format[pf->nbc] == 'X' ? ft_strtoupper(pf->buff) : pf->buff;
	ft_putstr(pf->buff);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)));
}

int	pf_octal_handler(const char *format, va_list va, t_printf *pf, int base)
{
	int	i;
	int	nb;

	pf_number_buffer(pf, va, base);
	nb = (pf->utp == 0 ? 0 : pf->sharp)
		+ (!pf->utp && pf->sharp && pf->precibool && !pf->precival);
	i = pf->precival - pf_count_digits(pf->buff, 1) - nb;
	pf_strprepend(pf->buff, i, '0', 0);
	i = pf->width - ft_strlen(pf->buff) - nb;
	if (pf->moins && i > 0)
		ft_strpostpend(pf->buff, i, ' ');
	if (pf->zero && i > 0)
		pf_strprepend(pf->buff, i, '0', 0);
	i = pf->width - ft_strlen(pf->buff) - nb;
	pf_add_sharp(pf, format[pf->nbc]);
	pf_strprepend(pf->buff, i, ' ', 0);
	ft_putstr(pf->buff);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)));
}

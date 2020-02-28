/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_numbers.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 21:13:55 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:07:03 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

long long int			pf_signed_sizer(t_printf *prin, va_list va)
{
	long long int n;

	if (prin->size == 'L')
		n = va_arg(va, long long int);
	else if (prin->size == 'l')
		n = va_arg(va, long int);
	else if (prin->size == 'h')
		n = (short int)va_arg(va, int);
	else if (prin->size == 'H')
		n = (char)va_arg(va, int);
	else
		n = (int)va_arg(va, int);
	return (n);
}

unsigned long long int	pf_unsigned_sizer(t_printf *prin, va_list va)
{
	unsigned long long int n;

	if (prin->size == 'L')
		n = va_arg(va, unsigned long long int);
	else if (prin->size == 'l')
		n = va_arg(va, unsigned long int);
	else if (prin->size == 'h')
		n = (unsigned short int)va_arg(va, unsigned int);
	else if (prin->size == 'H')
		n = (unsigned char)va_arg(va, unsigned int);
	else
		n = (unsigned int)va_arg(va, unsigned int);
	return (n);
}

void					pf_number_buffer(t_printf *pf, va_list va, int base)
{
	if (pf->type == 'u' || pf->type == 'x' || pf->type == 'X'
		|| pf->type == 'o')
	{
		pf->utp = pf_unsigned_sizer(pf, va);
		pf_buffer_alloc(&pf->buff, ft_ullonglen(pf->utp), pf);
		pf_utoa_base(pf->utp, base, pf);
	}
	else
	{
		pf->tp = pf_signed_sizer(pf, va);
		pf_buffer_alloc(&pf->buff, ft_longlen(pf->tp), pf);
		pf_itoa_base(pf->tp, base, pf);
	}
	pf_flag_cleaner(pf);
}

void					pf_itoa_base(long long n, int base, t_printf *pf)
{
	size_t				i;
	size_t				digit;
	unsigned long long	nb;

	if (pf->precibool && !pf->precival && !pf->tp)
		return ;
	i = 0;
	if (base != 10 && n < 0)
		n = 4294967296 + n;
	nb = n < 0 ? -n : n;
	while (nb)
	{
		digit = nb % base;
		pf->buff[i++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
		nb /= base;
	}
	if (n < 0 && base == 10)
		pf->buff[i++] = '-';
	else if (n == 0)
		pf->buff[i++] = '0';
	pf->buff[i] = '\0';
	ft_strrev(pf->buff);
}

void					pf_utoa_base(long long n, int base, t_printf *pf)
{
	size_t				i;
	size_t				digit;
	unsigned long long	nb;

	if (pf->precibool && !pf->precival && !pf->utp)
		return ;
	i = 0;
	nb = n;
	while (nb)
	{
		digit = nb % base;
		pf->buff[i++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
		nb /= base;
	}
	if (n == 0)
		pf->buff[i++] = '0';
	pf->buff[i] = '\0';
	ft_strrev(pf->buff);
}

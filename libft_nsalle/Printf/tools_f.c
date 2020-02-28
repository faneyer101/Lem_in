/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_f.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 16:23:37 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:07:03 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

long double		pf_float_sizer(t_printf *prin, va_list va)
{
	long double	n;

	if (prin->size == 'F')
		n = va_arg(va, long double);
	else
		n = (double)va_arg(va, double);
	if (((*(__int128_t*)&n >> 79) & 1) && n == 0.0)
		prin->szero = 1;
	return (n);
}

void			pf_round_up(t_printf *prin, char *nbr, char *ovf)
{
	int		i;

	ft_strclr(prin->buff);
	prin->buff = ft_strcpy(prin->buff, nbr);
	prin->buff[ft_strlen(prin->buff) - 1] += (ovf[0] >= '5');
	while ((i = ft_strcspn(prin->buff, ":/")) != (int)ft_strlen(prin->buff))
	{
		prin->buff[i] = (prin->buff[i] == ':') ? '0' : '.';
		prin->buff[i - 1]++;
		if (i == 0)
			pf_strprepend(prin->buff, 1, '1', 0);
	}
	if ((prin->precibool && !prin->precival && !prin->sharp))
		prin->buff[ft_strlen(prin->buff) - 1] = '\0';
	if (prin->precibool && !prin->precival && (ovf[0] >= '5' && !ovf[1])
	&& ((prin->buff[ft_strlen(prin->buff) - 1] + 1) % 2 == 0))
		prin->buff[ft_strlen(prin->buff) - 1]--;
}

void			pf_complete_float(t_printf *prin, int i, long double n,
					int sign)
{
	char	*number;
	char	*overflow;

	prin->buff[i++] = '.';
	while (n != .0)
	{
		n *= 10;
		prin->buff[i] = n + '0';
		n -= prin->buff[i++] - '0';
	}
	prin->buff[i] = '\0';
	if (sign)
		pf_strprepend(prin->buff, 1, '-', 0);
	if (!(number = ft_strndup(prin->buff, ft_strcspn(prin->buff, ".")
		+ 1 + prin->precival)))
		pf_die(prin->buff);
	if (!(overflow = ft_strdup(prin->buff + ft_strlen(number))))
	{
		ft_memdel((void**)&number);
		pf_die(prin->buff);
	}
	pf_round_up(prin, number, overflow);
	ft_memdel((void **)&number);
	ft_memdel((void **)&overflow);
}

void			pf_big_ftoa(long double n, t_printf *prin, size_t i)
{
	size_t		len;
	int			sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	len = pf_flen(n);
	while (i++ < len)
		n /= 10;
	i = 0;
	if (n == 0)
		prin->buff[i++] = '0';
	while (len--)
	{
		n *= 10;
		prin->buff[i] = n + '0';
		n -= prin->buff[i++] - '0';
	}
	pf_complete_float(prin, i, n, sign);
}

void			pf_small_ftoa(long double n, t_printf *prin)
{
	size_t				i;
	size_t				digit;
	unsigned long long	nb;
	int					sign;

	sign = 0;
	i = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	nb = n;
	if (nb == 0)
		prin->buff[i++] = '0';
	n -= nb;
	while (nb)
	{
		digit = nb % 10;
		prin->buff[i++] = digit + '0';
		nb /= 10;
	}
	ft_strrev(prin->buff);
	pf_complete_float(prin, i, n, sign);
}

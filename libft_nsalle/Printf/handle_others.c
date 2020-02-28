/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_others.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 21:07:34 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:07:06 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		pf_pointer_handler(va_list va, t_printf *pf)
{
	t_ulong		ptr;
	int			i;

	ptr = (t_ulong)va_arg(va, void *);
	pf_buffer_alloc(&pf->buff, ft_ulonglen(ptr), pf);
	pf_itoa_base(ptr, 16, pf);
	pf_strprepend(pf->buff, 1, 'x', 0);
	pf_strprepend(pf->buff, 1, '0', 0);
	i = pf->width - ft_strlen(pf->buff);
	if (i > 0 && !pf->moins)
		pf_strprepend(pf->buff, i, ' ', 0);
	if (i > 0 && pf->moins)
		ft_strpostpend(pf->buff, i, ' ');
	ft_putstr(pf->buff);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)));
}

int		pf_percent_handler(t_printf *pf)
{
	int	width;

	pf_buffer_alloc(&pf->buff, 1, pf);
	pf->buff[0] = '%';
	width = pf->width - ft_strlen(pf->buff);
	if (width > 0 && !pf->moins)
		pf_strprepend(pf->buff, width, (pf->zero ? '0' : ' '), 0);
	if (width > 0 && pf->moins)
		ft_strpostpend(pf->buff, width, ' ');
	ft_putstr(pf->buff);
	return (ft_delret(&pf->buff, ft_strlen(pf->buff)));
}

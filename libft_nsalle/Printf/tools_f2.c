/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_f2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 16:23:37 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:12:30 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		f_is_nan(long double f)
{
	return (!(f == f));
}

int		f_is_inf(long double f)
{
	if (f == (1.0 / 0.0) || f == -(1.0 / 0.0))
		return (1);
	else
		return (0);
}

size_t	pf_flen(long double n)
{
	size_t	i;

	i = 0;
	while (n >= 1.0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	pf_special_flag_helper(t_printf *pf)
{
	pf->precival = 0;
	pf->precibool = 1;
	pf->zero = 0;
	pf->sharp = 0;
	pf->plus = 0;
}

void	pf_flag_manager_f(long double f, t_printf *pf)
{
	if (f_is_nan(f) || f_is_inf(f))
	{
		pf_special_flag_helper(pf);
		if (f_is_nan(f))
		{
			pf->plus = 0;
			pf->fnan = 1;
		}
		else
		{
			pf->finf = 1;
			if (f == -(1.0 / 0))
				pf->finf = 2;
		}
	}
	if (!pf->precibool)
	{
		pf->precibool = 1;
		pf->precival = 6;
	}
	if (pf->szero)
	{
		pf->plus = 0;
		pf->space = 0;
	}
}

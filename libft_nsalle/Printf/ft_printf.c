/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 20:12:44 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:05:19 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_die(char *buff)
{
	if (buff)
		ft_memdel((void**)&buff);
	exit(-1);
}

int		color_ret(char *color, int ret)
{
	ft_putstr(color);
	return (ret);
}

int		parse_color(const char *format)
{
	if (ft_strnstr(format, "GREEN", 6))
		return (color_ret("\e[32m", 6));
	if (ft_strnstr(format, "BLUE", 5))
		return (color_ret("\e[34m", 5));
	if (ft_strnstr(format, "END", 4))
		return (color_ret("\e[0m", 4));
	if (ft_strnstr(format, "YELL", 5))
		return (color_ret("\e[33m", 5));
	if (ft_strnstr(format, "RED", 4))
		return (color_ret("\e[31m", 4));
	if (ft_strnstr(format, "CYAN", 5))
		return (color_ret("\e[36m", 5));
	if (ft_strnstr(format, "INV", 4))
		return (color_ret("\e[7m", 4));
	if (ft_strnstr(format, "UND", 4))
		return (color_ret("\e[4m", 4));
	if (ft_strnstr(format, "BOLD", 5))
		return (color_ret("\e[1m", 5));
	ft_putchar('{');
	return (0);
}

int		start_printf(int *i, int *len, const char *restrict format)
{
	if (!format)
		return (0);
	*i = 0;
	*len = 0;
	return (1);
}

int		ft_printf(const char *restrict str, ...)
{
	int			i;
	int			len;
	t_printf	pf;
	va_list		va;

	if (!(start_printf(&i, &len, str)))
		return (0);
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			pf_parse_input(str + i, va, &pf, &len);
			i += pf.nbc;
			len--;
		}
		else if (str[i] != '%' && str[i] != '{' && i < (int)ft_strlen(str))
			ft_putchar(str[i]);
		else if (ft_strchr(str, '{'))
			i += parse_color(str + i);
		i++;
		len++;
	}
	va_end(va);
	return (len);
}

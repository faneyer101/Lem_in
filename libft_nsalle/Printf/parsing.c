/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 16:50:14 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:07:04 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void		pf_setup_struct(t_printf *pf, const char *format)
{
	int i;

	i = 1;
	pf_struct_resetter(pf);
	while (format[i] == ' ' || format[i] == '-' || format[i] == '+'
		|| format[i] == '0' || format[i] == '#')
	{
		pf->space = format[i] == ' ' ? 1 : pf->space;
		pf->moins = format[i] == '-' ? 1 : pf->moins;
		pf->plus = format[i] == '+' ? 1 : pf->plus;
		pf->zero = format[i] == '0' ? 1 : pf->zero;
		pf->sharp = format[i] == '#' ? 1 : pf->sharp;
		i++;
	}
	pf->width = ft_atoi(format + i);
	while (ft_isdigit(format[i]))
		i++;
	if ((format + i)[0] == '.')
	{
		pf->precibool = 1;
		pf->precival = ft_atoi((format + i) + 1);
	}
	while (format[i] == '.' || ft_isdigit(format[i]))
		i++;
	pf_size_parser(pf, format + i);
}

void		pf_parse_input(const char *format, va_list va, t_printf *pf,
				int *len)
{
	int			i;

	i = 1;
	while (format[i] == ' ' || format[i] == '-' || format[i] == '+'
		|| format[i] == '0' || format[i] == '#')
		i++;
	while (ft_isdigit(format[i]))
		i++;
	i += (format[i] == '.');
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == 'L' || (format[i] == 'l' && format[i + 1] != 'l')
		|| (format[i] == 'h' && format[i + 1] != 'h'))
		i += 1;
	else if ((format[i] == 'l' && format[i + 1] == 'l')
		|| (format[i] == 'h' && format[i + 1] == 'h'))
		i += 2;
	if (format[i] == 'b' || format[i] == 'B')
		i += 1 + ft_intlen(ft_atoi(format + i + 1));
	pf->nbc = i;
	pf->type = format[i];
	pf_setup_struct(pf, format);
	*len += pf_handle_input(format, va, pf);
}

int			pf_handle_input(const char *format, va_list va, t_printf *pf)
{
	int			len;

	if (pf->size == 'b' || pf->size == 'B')
		len = pf_int_handler(format, va, pf, pf->base);
	else if (format[pf->nbc] == 'd' || format[pf->nbc] == 'i')
		len = pf_int_handler(format, va, pf, 10);
	else if (format[pf->nbc] == 'u')
		len = pf_uint_handler(format, va, pf, 10);
	if (format[pf->nbc] == 'o')
		len = pf_octal_handler(format, va, pf, 8);
	if (format[pf->nbc] == 'x' || format[pf->nbc] == 'X')
		len = pf_hexa_handler(format, va, pf, 16);
	if ((format[pf->nbc] == 'c' || format[pf->nbc] == 's'))
		len = pf_text_handler(format, va, pf);
	if (format[pf->nbc] == 'p')
		len = pf_pointer_handler(va, pf);
	if (format[pf->nbc] == '%')
		len = pf_percent_handler(pf);
	if (format[pf->nbc] == 'f')
		len = pf_f_handler(va, pf);
	return (len);
}

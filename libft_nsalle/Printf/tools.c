/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 10:35:41 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:05:37 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

void		pf_add_sharp(t_printf *prin, char type)
{
	int	i;

	if (prin->sharp)
	{
		i = ft_strcspn(prin->buff, "x0123456789abcdef");
		if (prin->utp)
		{
			if (type == 'x' || type == 'X')
				pf_strprepend(prin->buff, 1, type, i);
			if (prin->buff[0] != '0' && (type == 'x' || type == 'X'))
				pf_strprepend(prin->buff, 1, '0', i);
			if (type == 'o')
				pf_strprepend(prin->buff, 1, '0', i);
		}
		if (prin->buff[0] != '0' && prin->precibool && !prin->precival
			&& type == 'o')
			pf_strprepend(prin->buff, 1, '0', 0);
	}
}

void		pf_add_plus(t_printf *prin)
{
	int	i;

	i = 0;
	if (prin->plus && prin->tp >= 0)
	{
		i = ft_strcspn(prin->buff, "0123456789");
		pf_strprepend(prin->buff, 1, '+', i);
	}
}

void		pf_buffer_alloc(char **buff, int len, t_printf *pf)
{
	int		biggest;

	biggest = len > (int)pf->width ? len : pf->width;
	biggest = (int)pf->precival > biggest ? pf->precival : biggest;
	if (!(*buff = ft_memalloc(sizeof(char) * biggest + 3)))
		exit(-1);
}

int			pf_count_digits(char *str, int x)
{
	int	nb;
	int	i;
	int (*fdigit)(int);

	i = 0;
	nb = 0;
	fdigit = x ? &ft_isxdigit : &ft_isdigit;
	while (str[i])
		if (fdigit(str[i++]))
			nb++;
	return (nb);
}

char		*pf_strprepend(char *str, int nb, char c, int skip)
{
	int		i;
	int		j;
	char	*buff;

	if (nb > 0)
	{
		i = 0 + skip;
		if (!(buff = ft_strdup(str + i)))
			pf_die(str);
		j = 0;
		while (nb--)
			str[i++] = c;
		while (buff[j])
			str[i++] = buff[j++];
		str[i] = '\0';
		ft_memdel((void*)&buff);
	}
	return (str);
}

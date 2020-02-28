/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 12:09:55 by nsalle       #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 20:06:28 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"

# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

# define SIZE 1
# define TYPE 2
# define OPT 3

typedef struct	s_printf
{
	char		*buff;
	uint8_t		size;
	long double	ftp;
	int64_t		tp;
	uint64_t	utp;
	uint8_t		moins;
	uint8_t		plus;
	uint8_t		sharp;
	uint8_t		zero;
	uint8_t		space;
	uint64_t	width;
	uint64_t	precival;
	uint8_t		precibool;
	uint8_t		fnan;
	uint8_t		finf;
	uint8_t		szero;
	uint8_t		base;
	uint64_t	nbc;
	char		type;
}				t_printf;

/*
** Main entry to the function
*/

int				ft_printf(const char *restrict format, ...);

/*
** Parsing, output and tools
*/

void			pf_size_parser(t_printf *pf, const char *format);
void			pf_flag_cleaner(t_printf *pf);
void			pf_parse_input(const char *format, va_list va, t_printf *pf,
				int *len);
void			pf_struct_resetter(t_printf *pf);
int				pf_handle_input(const char *format, va_list va, t_printf *pf);
void			pf_add_sharp(t_printf *prin, char type);
void			pf_add_plus(t_printf *prin);
void			pf_buffer_alloc(char **buff, int len, t_printf *pf);
void			pf_die(char *buff);
char			*pf_strprepend(char *str, int nb, char c, int skip);

/*
** Floats
*/

void			pf_small_ftoa(long double n, t_printf *prin);
void			pf_big_ftoa(long double n, t_printf *prin, size_t i);
void			pf_flag_manager_f(long double f, t_printf *pf);
long double		pf_float_sizer(t_printf *prin, va_list va);
size_t			pf_flen(long double n);
int				pf_f_handler(va_list va, t_printf *pf);
int				f_is_inf(long double f);
int				f_is_nan(long double f);

/*
** Other numbers
*/

void			pf_utoa_base(long long n, int base, t_printf *pf);
void			pf_itoa_base(long long n, int base, t_printf *pf);
int				pf_int_handler(const char *format, va_list va, t_printf *pf,
				int base);
int				pf_uint_handler(const char *format, va_list va, t_printf *pf,
				int base);
int				pf_hexa_handler(const char *format, va_list va, t_printf *pf,
				int base);
int				pf_octal_handler(const char *format, va_list va, t_printf *pf,
				int base);
void			pf_number_buffer(t_printf *pf, va_list va, int base);
int				pf_count_digits(char *str, int x);

/*
** Text
*/

int				pf_char_handler(va_list va, t_printf *pf);
int				pf_text_handler(char const *format, va_list va, t_printf *pf);

/*
** Others
*/

int				pf_pointer_handler(va_list va, t_printf *pf);
int				pf_percent_handler(t_printf *pf);

#endif

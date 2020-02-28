/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 00:32:57 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 20:29:36 by nsalle      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# include "get_next_line.h"
# include "ft_printf.h"

typedef unsigned long t_ulong;

/*
**	List structure definition
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	Function prototypes
*/

long long int		ft_abs(long long int n);
long long int		ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstcreate(void *content);
int					ft_delret(void *ptr, int ret);
size_t				ft_intlen(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
char				*ft_itoa_base(int n, int base);
char				*ft_itoa(int n);
t_list				*ft_lstat(t_list *begin_list, unsigned int nbr);
void				ft_lstclear(t_list **begin_list);
t_list				*ft_lstfind(t_list *begin_list, void *content_ref,
					int (*cmp)());
void				ft_lstforeach_if(t_list *begin_list, void (*f)(void *),
					void *content_ref, int (*cmp)());
void				ft_lstforeach(t_list *begin_list, void (*f)(void *));
t_list				*ft_lstlast(t_list *begin_list);
void				ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void				ft_lstpush_back(t_list **begin_list, void *content);
void				ft_lstpush_front(t_list **begin_list, void *data);
t_list				*ft_lstpush_params(int ac, char **av);
void				ft_lstremove_if(t_list **begin_list, void *content_ref,
					int (*cmp)());
void				ft_lstrev(t_list **begin_list);
size_t				ft_lstsize(t_list *begin_list);
t_list				*ft_lstsort(t_list *lst, int (*cmp)());
size_t				ft_llonglen(long long n);
size_t				ft_longlen(long n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_print_bits(unsigned char bit);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_puterr(char const *error);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int nbr);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putstr(char const *str);
void				*ft_realloc(void *ptr, size_t size);
unsigned char		ft_reverse_bits(unsigned char bit);
int					ft_strcasecmp(const char *s1, const char *s2);
char				*ft_strcasestr(const char *haystack, const char *needle);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strspn(char *s, char *accept);
size_t				ft_strcspn(const char *s, const char *reject);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strndup(const char *s, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
int					ft_stroccur(char *str, char c);
long long int		ft_pow(int nb, int exp);
char				*ft_strpostpend(char *str, int nb, char c);
char				*ft_strprepend(char *str, int nb, char c, int skip);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtoupper(char *str);
char				*ft_strtrim(char const *s);
unsigned char		ft_swap_bits(unsigned char bit);
void				ft_swap(int *a, int *b);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_ullonglen(unsigned long long n);
size_t				ft_ulonglen(t_ulong n);
size_t				ft_wordcount(const char *s, char c);
int					get_next_line(const int fd, char **line);

#endif

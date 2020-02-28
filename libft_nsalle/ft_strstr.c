/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/11 23:38:41 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 02:06:19 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The strstr() function finds the first occurrence of the substring needle in
**	the string haystack.  The terminating null bytes ('\0') are not compared.
**
**		RETURN VALUE
**	This function returns a pointer to the beginning of the located substring,
**	or NULL if the substring is not found.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *result;
	char *search;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		result = (char *)haystack;
		search = (char *)needle;
		while (*haystack && *search && *haystack == *search)
		{
			haystack++;
			search++;
		}
		if (!*search)
			return (result);
		haystack = result + 1;
	}
	return (0);
}

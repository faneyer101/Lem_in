/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:42:27 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 03:22:16 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**		DESCRIPTION
**	The realloc() function changes the size of the memory block pointed to by
**	ptr to size bytes.  The contents will be unchanged in the range from the
**	start of the region up to the minimum of the  old  and  new sizes.
**	If the new size is larger than the old size, the added memory will not be
**	initialized.
**	If ptr is NULL, then the call is equivalent to malloc(size), for all values
**	of size; if size is equal to zero, and ptr is not NULL, then the call is
**	equivalent to free(ptr).  Unless ptr is NULL, it must have been returned by
**	an earlier call to malloc(), calloc() or realloc().
**	If the area pointed  to  was  moved,  a free(ptr) is done.
**
**		RETURN VALUE
**	The realloc() function returns a pointer to the newly allocated memory,
**	which is suitably aligned for any built-in type and may be different from
**	ptr, or NULL if the request fails.  If size was equal to  0, either NULL or
**	a pointer suitable to be passed to free() is returned.
**	If realloc() fails, the original block is left untouched; it is not freed
**	or moved.
*/

/*
**	1. If the first argument is NULL function which works the same as malloc.
**	2. If size is 0 realloc works the same as free() and returns NULL because no
**	new areas need to be reserved.
**	3. Using the function malloc, a space equivalent to the size of the newer
**	and if the allocation fails return NULL. The original area remains.
**	4. The data in the source area to be copied to newly allocated space
**	5. Source area to be released using free().
**	6. Return the address of the beginning of a new space
*/

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *nptr;

	if (!ptr)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!(nptr = malloc(size)))
		return (NULL);
	ft_memcpy(nptr, ptr, size);
	free(ptr);
	return (nptr);
}

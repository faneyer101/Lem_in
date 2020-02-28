/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 00:32:42 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 00:32:49 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

/*
** Max FDS:
** Set max FDS with command "ulimit -n"
*/

# define BUFF_SIZE 128
# define FDS 4864 + 1
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

int		get_next_line(const int fd, char **line);

#endif

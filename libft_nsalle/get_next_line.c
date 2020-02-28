/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-la-m <jde-la-m@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 19:11:33 by jde-la-m     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 12:32:30 by jde-la-m    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	check_line(char **readfile, char **line)
{
	char	*tmp;
	char	*pchr;
	size_t	i;

	i = 0;
	pchr = *readfile;
	while (pchr[i] != '\n')
		if (!pchr[i++])
			return (0);
	*line = ft_strndup(*readfile, i);
	tmp = ft_strdup(&pchr[i + 1]);
	if (!*line || !tmp)
		return (-1);
	ft_strdel(readfile);
	if (!(*readfile = ft_strdup(tmp)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

static int	read_file(int fd, char *buffer, char **readfile, char **line)
{
	char	*tmp;
	int		rbytes;
	int		ret;

	while ((rbytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rbytes] = '\0';
		if (*readfile)
		{
			if (!(tmp = ft_strjoin(*readfile, buffer)))
				return (-1);
			ft_strdel(readfile);
			*readfile = tmp;
		}
		else if (!(*readfile = ft_strdup(buffer)))
			return (-1);
		ret = check_line(readfile, line);
		if (ret == -1)
			return (ret);
		else if (ret == 1)
			break ;
	}
	return (RET_VALUE(rbytes));
}

int			get_next_line(const int fd, char **line)
{
	static char	*readfile[FDS];
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (!line || (fd < 0 || fd >= FDS) || (read(fd, readfile[fd], 0) < 0))
		return (-1);
	if (readfile[fd] && check_line(&readfile[fd], line))
		return (1);
	ret = read_file(fd, buffer, &readfile[fd], line);
	if (ret || readfile[fd] == NULL || readfile[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = readfile[fd];
	readfile[fd] = NULL;
	return (1);
}

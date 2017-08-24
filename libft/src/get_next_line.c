/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:09:49 by tbeauzam          #+#    #+#             */
/*   Updated: 2016/12/08 11:52:49 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	copy_until_newline(char *dest, char *src, size_t len, char c)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (i);
	while (src[i	] != c && i < len)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (i);
}

static char		*append_buffer(char *line, char *buffer)
{
	size_t	copied_len;
	size_t	remaining_len;
	char	temp[BUFF_SIZE + 1];

	copied_len = copy_until_newline(temp, buffer, ft_strlen(buffer), '\n');
	remaining_len = ft_strlen(buffer) - copied_len;
	if (copied_len == ft_strlen(buffer))
		ft_strclr(buffer);
	else
	{
		ft_memmove(buffer, ft_strchr(buffer, '\n') + 1, remaining_len);
		ft_strclr(buffer + remaining_len);
	}
	if (line[0] == 0)
		ft_memcpy(line, temp, copied_len);
	else
		ft_strcat(line, temp);
	return (line);
}

static t_list	*set_list(t_list **list, int fd, char *buffer)
{
	t_list	*current;

	current = NULL;
	current = *list;
	if (!current)
	{
		*list = NULL;
		current = ft_lstnew(buffer, BUFF_SIZE + 1);
		CUR_FD = fd;
		*list = current;
	}
	if (current && (int)CUR_FD != fd)
	{
		while (current)
		{
			if ((int)CUR_FD == fd)
				return (current);
			current = current->next;
		}
		ft_lstadd_front(list, ft_lstnew(buffer, BUFF_SIZE + 1));
		current = *list;
		CUR_FD = fd;
	}
	return (current);
}

static int		get_line(t_list *current, char *temp, char *buffer, char **line)
{
	int		ret;

	ret = -1;
	while (!(ft_strchr(CUR_BUFF, '\n')) && ret != 0)
	{
		if (ft_strlen(CUR_BUFF) > 0)
			append_buffer(temp, CUR_BUFF);
		else
		{
			if ((ret = read(CUR_FD, buffer, BUFF_SIZE)) > 0)
				buffer[ret] = '\0';
			else if (ret == 0 && temp[0] == 0)
				return (0);
			else if (ret == -1)
				return (-1);
			ft_memcpy(CUR_BUFF, buffer, ret);
		}
	}
	append_buffer(temp, CUR_BUFF);
	*line = ft_strdup(temp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				result;
	char			temp[MAX_LEN_LINE];
	char			buffer[BUFF_SIZE + 1];
	static t_list	*list;
	t_list			*current;

	result = 0;
	ft_bzero(buffer, BUFF_SIZE + 1);
	ft_bzero(temp, MAX_LEN_LINE);
	if (fd < 0 || BUFF_SIZE < 1 || !(current = set_list(&list, fd, buffer)))
		return (-1);
	if ((result = get_line(current, temp, buffer, line)) == 1)
		return (1);
	else if (result == 0)
		return (0);
	else
		return (-1);
}

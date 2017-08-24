/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauzam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:08 by tbeauzam          #+#    #+#             */
/*   Updated: 2017/01/17 18:31:11 by tbeauzam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "libft.h"

# define BUFF_SIZE 1000
# define MAX_LEN_LINE 200000
# define CUR_BUFF current->content
# define CUR_FD current->content_size

int		get_next_line(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:50:26 by ichubare          #+#    #+#             */
/*   Updated: 2017/03/16 19:50:29 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*create_list(int fd, t_list **start)
{
	t_list		*elem;
	t_list		*copy;

	copy = *start;
	while (copy)
	{
		if (fd == (int)copy->content_size)
			return (copy);
		copy = copy->next;
	}
	elem = (t_list*)malloc(sizeof(t_list));
	elem->content = ft_strnew(0);
	elem->content_size = fd;
	elem->next = NULL;
	if (*start == NULL)
		*start = elem;
	else
		ft_lstadd(&(*start), elem);
	return (elem);
}

static int		print_with_n(t_list **str, int *i, char **line, char **row)
{
	char	*ptr;

	ptr = ft_strchr(*row, 10);
	i[0] += ptr - (*row);
	if (i[1] < i[0])
	{
		i[0] = i[1];
		(*line) = ft_strnew(i[0] + ft_strlen((char*)(*str)->content));
		(*line) = ft_strcpy(*line, (char*)(*str)->content);
		(*line) = ft_strncat(*line, *row, i[0]);
		ft_memdel(&(*str)->content);
		return (1);
	}
	(*line) = ft_strnew(i[0] + ft_strlen((char*)(*str)->content));
	(*line) = ft_strcpy(*line, (char*)(*str)->content);
	(*line) = ft_strncat(*line, *row, i[0]);
	ft_memdel(&(*str)->content);
	((*str)->content) = ft_strnew(i[1] - i[0] + 1);
	((*str)->content) = ft_strncpy((char*)(*str)->content, *row +
	(ptr - *row + 1), (i[1] - i[0] - 1));
	ft_strdel(&(*row));
	return (1);
}

static int		ret_one(char **line, char *row, int *i, t_list **str)
{
	(*line) = ft_strnew(i[1] + ft_strlen((*str)->content));
	(*line) = ft_strncat(ft_strcpy(*line, (*str)->content), row, i[1]);
	ft_memdel(&(*str)->content);
	ft_strdel(&row);
	return (1);
}

static int		read_function(t_list **str, char **line, int *i, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*ptr;
	char	*row;

	row = ft_strnew(0);
	buf[BUFF_SIZE] = '\0';
	while (((i[2] = read(fd, buf, BUFF_SIZE)) >= 0) && (i[1] += i[2]) >= 0)
	{
		ptr = row;
		row = ft_strjoin(row, buf);
		ft_strdel(&ptr);
		if (ft_strchr(row, 10) != NULL && i[1] > 0)
			return (print_with_n(&(*str), i, line, &row));
		else if (i[2] == 0 && i[1] == 0 && ((*str)->content == NULL ||
			ft_strlen((*str)->content) == 0))
		{
			((*str)->content != NULL) ? free((*str)->content) : 0;
			ft_strdel(&row);
			return (0);
		}
		else if (i[2] < BUFF_SIZE)
			return (ret_one(line, row, i, str));
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*start;
	char			*ptr;
	char			*row;
	t_list			*str;
	int				i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = BUFF_SIZE;
	str = create_list(fd, &start);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if ((str->content != NULL) && (ptr = ft_strchr((char*)str->content, 10))
		!= NULL)
	{
		(*line) = ft_strnew((int)(ptr - (char*)str->content));
		(*line) = ft_strncpy(*line, (char*)str->content,
			(int)(ptr - (char*)str->content));
		row = str->content;
		str->content = ft_strnew(ft_strlen(ptr + 1));
		str->content = ft_strcpy((char*)str->content, ptr + 1);
		ft_strdel(&row);
		return (1);
	}
	return (read_function(&str, &(*line), i, fd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:03:46 by tferrieu          #+#    #+#             */
/*   Updated: 2019/09/23 14:03:49 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_lst(const int fd, t_list **fds, t_list **pos)
{
	if (!(*fds))
	{
		if (!(*fds = (t_list *)malloc(sizeof(t_list))))
			return (-1);
		if (!((*fds)->content = ft_strnew(MOVE_SIZE + 1)))
			return (-1);
		(*fds)->content_size = fd;
		(*fds)->next = NULL;
	}
	(*pos) = *fds;
	while ((*pos)->content_size != (size_t)fd && (*pos)->next)
		(*pos) = (*pos)->next;
	if ((*pos)->content_size != (size_t)fd)
	{
		if (!((*pos)->next = (t_list *)malloc(sizeof(t_list))))
			return (-1);
		(*pos) = (*pos)->next;
		if (!((*pos)->content = ft_strnew(MOVE_SIZE + 1)))
			return (-1);
		(*pos)->content_size = fd;
		(*pos)->next = NULL;
	}
	return (1);
}

static int	backn(char **line, char *buff, int bol, t_list *pos)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < bol && buff[i] && buff[i] != '\n' && buff[i] != 13)
		i++;
	if (!(tmp = ft_strnew(i)))
		return (-1);
	i = 0;
	while (i < bol && buff[i] && buff[i] != '\n' && buff[i] != 13)
	{
		tmp[i] = buff[i];
		i++;
	}
	if (!(*line = ft_strjoin_free(line, &tmp, 3)))
		return (-1);
	ft_strclr(pos->content);
	if (i != bol)
		pos->content = ft_strcpy(pos->content, buff + i + 1);
	ft_strclr(buff);
	return (i == bol);
}

int			get_next_move(const int fd, char **line)
{
	static t_list	*fds;
	t_list			*pos;
	char			*buff;
	int				bol;
	int				status;

	if (fd < 0 || !line || init_lst(fd, &fds, &pos) < 1 ||
			!(buff = ft_strnew(MOVE_SIZE + 1)))
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	buff = ft_strcpy(buff, pos->content);
	bol = ft_strlen(buff);
	while ((status = backn(line, buff, bol, pos)) > 0 &&
			(bol = read(fd, buff, MOVE_SIZE)) > 0)
		;
	free(buff);
	return (status && ft_strlen(*line) ? -1 : 1);
}

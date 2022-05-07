/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:11:51 by vtheobal          #+#    #+#             */
/*   Updated: 2021/06/14 18:44:44 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	sbros(int reat, char *buff, char *ost)
{
	if (ost)
		free (ost);
	if (buff)
		free(buff);
	if (reat > 0)
		return (1);
	if (reat < 0)
		return (-1);
	return (reat);
}

int	get_next_line(int fd, char **line)
{
	int			reat;
	static char	*ost;
	char		*buff;

	reat = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read(fd, buff, 0) || !line || !buff || BUFFER_SIZE <= 0)
		return (sbros(-1, buff, 0));
	while (reat)
	{
		if (ft_strchr(ost, '\n') != 0)
			break ;
		reat = read(fd, buff, BUFFER_SIZE);
		buff[reat] = '\0';
		ost = ft_strjoin(ost, buff);
		if (!ost)
			return (sbros(-1, buff, 0));
	}
	*line = ft_substr(ost, 0, len(ost, '\n'), 0);
	if (!(*line))
		return (sbros(reat, buff, ost));
	ost = ft_substr(ost, len(ost, '\n') + 1, len(ost, '\0') - len(ost, '\n'), 1);
	if (!ost && reat)
		return (sbros(-1, buff, 0));
	return (sbros(reat, buff, 0));
}

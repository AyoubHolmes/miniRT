/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checkers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:47:06 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/26 18:50:28 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				pl_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 4)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) \
			&& ft_isvector(data[2], ft_isfloat) && \
			ft_isvector(data[3], ft_iscolorfloat))
			return (1);
		else
			return (-13);
	}
	return (-12);
}

int				sq_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 5)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) &&\
			ft_isvector(data[2], ft_isfloat) && \
			ft_ispositivefloat(data[3]) && ft_isvector(data[4] \
			, ft_iscolorfloat))
			return (1);
		else
			return (-15);
	}
	return (-14);
}

int				cy_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 6)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) \
			&& ft_isvector(data[2], ft_isfloat) && \
			ft_isvector(data[3], ft_iscolorfloat) \
			&& ft_ispositivefloat(data[4]) \
			&& ft_ispositivefloat(data[5]))
			return (1);
		else
			return (-17);
	}
	return (-16);
}

int				tr_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 5)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) \
			&& ft_isvector(data[2], ft_isfloat) && \
			ft_isvector(data[3], ft_isfloat) && \
			ft_isvector(data[4], ft_iscolorfloat))
			return (1);
		else
			return (-19);
	}
	return (-18);
}

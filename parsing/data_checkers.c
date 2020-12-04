/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:34:31 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/26 18:50:28 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				r_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 3)
	{
		data = ft_split_whitespaces(line);
		if (ft_isint(data[1]) && ft_isint(data[1]))
			return (1);
		else
			return (-3);
	}
	return (-2);
}

int				a_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 3)
	{
		data = ft_split_whitespaces(line);
		if (ft_isintensityfloat(data[1]) && \
			ft_isvector(data[2], ft_iscolorfloat))
			return (1);
		else
			return (-5);
	}
	return (-4);
}

int				c_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 4)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) && \
			ft_isvector(data[2], ft_isfloat) && ft_ispositiveint(data[3]))
			return (1);
		else
			return (-7);
	}
	return (-6);
}

int				l_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 4)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) && \
			ft_isintensityfloat(data[2]) && \
			ft_isvector(data[3], ft_iscolorfloat))
			return (1);
		else
			return (-9);
	}
	return (-8);
}

int				sp_checker(char *line)
{
	int			i;
	char		**data;

	i = ft_nbr_words(line, ' ');
	if (i == 4)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) && ft_ispositivefloat(data[2]) && \
			ft_isvector(data[3], ft_iscolorfloat))
			return (1);
		else
			return (-11);
	}
	return (-10);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:34:31 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:05:06 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				r_checker(char *line, t_err *err)
{
	int			i;
	char		**data;

	i = nb_word(line);
	if (i == 3)
	{
		data = ft_split_whitespaces(line);
		if (ft_isint(data[1]) && ft_isint(data[1]))
		{
			if (err->r_exists == 0)
			{
				err->r_exists = 1;
				return (1);
			}
			else if (err->r_exists == 1)
				return (-23);
		}
		else
			return (-3);
	}
	return (-2);
}

int				a_checker(char *line, t_err *err)
{
	int			i;
	char		**data;

	i = nb_word(line);
	if (i == 3)
	{
		data = ft_split_whitespaces(line);
		if (ft_isintensityfloat(data[1]) && \
			ft_isvector(data[2], ft_iscolorfloat))
		{
			if (err->am_exists == 0)
			{
				err->am_exists = 1;
				return (1);
			}
			else if (err->am_exists == 1)
				return (-24);
		}
		else
			return (-5);
	}
	return (-4);
}

int				c_checker(char *line, t_err *err)
{
	int			i;
	char		**data;

	i = nb_word(line);
	if (i == 4)
	{
		data = ft_split_whitespaces(line);
		if (ft_isvector(data[1], ft_isfloat) && \
			ft_isvector(data[2], ft_isfloat) && ft_ispositiveint(data[3]))
			{
				err->c_exists = 1;
				return (1);
			}
		else
			return (-7);
	}
	return (-6);
}

int				l_checker(char *line)
{
	int			i;
	char		**data;

	i = nb_word(line);
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

	i = nb_word(line);
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

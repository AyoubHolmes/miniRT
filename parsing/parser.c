/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:22:15 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:15:46 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_err			error_return(char *line)
{
	t_err err;

	my_free_main(line);
	err.line = -1;
	err.is_checked = -20;
	return (err);
}

void			error_procedure(t_err *err, char *line)
{
	err->is_checked = data_checker(line, err);
	my_free_main(line);
}

t_err			err_init()
{
	t_err err;

	err.line = 0;
	err.am_exists = 0;
	err.c_exists = 0;
	err.r_exists = 0;
	return (err);
}

void			end_file_check(t_err *err)
{
	if (err->c_exists == 0)
		err->is_checked = -25;
	else if (err->r_exists == 0)
		err->is_checked = -26;
	else if (err->am_exists == 0)
		err->is_checked = -27;
	else
		err->is_checked = 1;
}

t_err			file_checker(char *file)
{
	int			tab[3];
	char		*line;
	int			fd;
	int			rest;
	t_err		err;

	fd = open(file, O_RDONLY);
	err = err_init();
	rest = 1;
	while (rest == 1)
	{
		rest = get_next_line(fd, &line);
		if (rest < 0)
			return (error_return(line));
		err.line++;
		if (line[0] == '\0')
			continue;
		error_procedure(&err, line);
		if (err.is_checked != 1)
			return (err);
	}
	close(fd);
	end_file_check(&err);
	return (err);
}

t_data			file_parser(char *file)
{
	t_data		d;
	char		**data;
	char		*line;
	int			fd;
	int			rest;

	d.obj = NULL;
	fd = open(file, O_RDONLY);
	rest = 1;
	while (rest == 1)
	{
		rest = get_next_line(fd, &line);
		if (line[0] == '\0')
		{
			my_free_main(line);
			continue;
		}
		data = ft_split_whitespaces(line);
		data_insertion(&d, data);
		my_free_main(line);
	}
	close(fd);
	return (d);
}

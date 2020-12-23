/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:57:49 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:14:12 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx.h>

int					key_press(int keycode, t_main *m)
{
	if (keycode == 53 || keycode == 12)
	{
		free_list(m->d.lights);
		free_list(m->d.obj);
		exit(0);
	}
	if (keycode == 123)
	{
		m->d.cameras = get_cam_previous(&m->d.cameras);
		graphic_drawer(m);
	}
	if (keycode == 124)
	{
		m->d.cameras = get_cam_next(&m->d.cameras);
		graphic_drawer(m);
	}
	return (0);
}

t_data				parse(char **argv, t_main *m, int ac)
{
	t_data			d;

	m->is_save = 0;
	d = file_parser(argv[1]);
	if (ac == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		m->is_save = 1;
	d.cameras = getcams(d);
	d.lights = get_ligths(d.obj);
	return (d);
}

t_resolution		resize(t_resolution r, int a, int b)
{
	if ((r.x <= 0 || r.x >= a))
		r.x = a;
	if ((r.y <= 0 || r.y >= b))
		r.y = b;
	return (r);
}

t_err				file_is_empty(char *filename)
{
	t_err err;
	int fd;
	char *line;
	int rest;

	err.is_checked = 1;
	fd = open(filename, O_RDONLY);
	rest = get_next_line(fd, &line);
	free(line);
	if (rest == 0)
		err.is_checked = -23;
	return (err);
}

int					main_checker(int argc, char **argv)
{
	t_err			err;

	err.is_checked = -21;
	err.line = -1;
	if (argc == 2 || (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0
		&& ft_strlen(argv[2]) == 6))
	{
		err = file_extension_checker(argv[1]);
		if (err.is_checked == 1)
		{
			err = file_checker(argv[1]);
			if (err.is_checked == 1)
				return (1);
			error_printer(err);
			return (0);
		}
	}
	error_printer(err);
	return (0);
}

int					main(int argc, char **argv)
{
	t_main			m;
	int				a;
	int				b;

	if (main_checker(argc, argv))
	{
		m.d = parse(argv, &m, argc);
		m.w.mlx_ptr = mlx_init();
		mlx_get_screen_size(m.w.mlx_ptr, &a, &b);
		m.d.r = resize(m.d.r, a, b);
		m.w.win_ptr = mlx_new_window(m.w.mlx_ptr, m.d.r.x, m.d.r.y, "miniRT");
		m.w.img_ptr = mlx_new_image(m.w.mlx_ptr, m.d.r.x, m.d.r.y);
		m.w.img_data = (int *)mlx_get_data_addr(m.w.img_ptr,
						&m.w.bpp, &m.w.size_l, &m.w.img_endian);
		graphic_drawer(&m);
		if (m.is_save == 0)
		{
			mlx_hook(m.w.win_ptr, 2, 0, key_press, &m);
			mlx_hook(m.w.win_ptr, 2, 0, key_press, &m);
			mlx_loop(m.w.mlx_ptr);
		}
	}
	return (0);
}

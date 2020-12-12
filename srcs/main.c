/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:57:49 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/04 10:17:53 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx.h>

t_objects	*light_frees(t_objects *p, t_objects *q, t_objects *lst)
{
	my_free_main(p);
	my_free_main(q);
	return (lst);
}

t_objects *get_ligths(t_objects *obj)
{
	t_objects	*p;
	t_objects	*q;
	t_objects	*lst;

	p = obj;
	lst = NULL;
	if (!(q = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	while (p != NULL)
	{
		if (p->id == 3)
		{
			q->content = p->content;
			q->id = 3;
			q->next = NULL;
			ft_lstadd_back(&lst, q);
		}
		p = p->next;
	}
	return (light_frees(p, q, lst));
}

int key_press(int keycode, t_main *m)
{
	if(keycode == 53 || keycode == 12)
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

t_data parse(char **argv, t_main *m, int ac)
{
	t_data d;

	m->is_save = 0;
	d = file_parser(argv[1]);
	if (ac == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		m->is_save = 1;
	d.cameras = getcams(d);
	d.lights = get_ligths(d.obj);
	return (d);
}

t_resolution resize(t_resolution R, int a, int b)
{
	if ((R.x <= 0 || R.x >= a))
		R.x = a;
	if ((R.y <= 0 || R.y >= b))
		R.y = b;
	return (R);
}

int main_checker(int argc, char **argv)
{
	t_err err;

	err.is_checked = -21;
	err.line = -1;
	if (argc == 2 || (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0))
	{
		err = file_checker(argv[1]);
		if (err.is_checked == 1)
			return (1);
		error_printer(err);
		return (0);
	}
	error_printer(err);
	return(0);

}

int			main(int argc, char **argv)
{
	t_main	m;
	int		a;
	int		b;

	if (main_checker(argc, argv))
	{
		m.d = parse(argv, &m, argc);
		m.w.mlx_ptr = mlx_init();
		//mlx_get_screen_size(m.w.mlx_ptr, &a, &b);
		//m.d.r = resize(m.d.r, a, b);
		m.w.win_ptr = mlx_new_window(m.w.mlx_ptr,m.d.r.x,m.d.r.y,"miniRT");
		m.w.img_ptr = mlx_new_image(m.w.mlx_ptr,m.d.r.x,m.d.r.y);
		m.w.img_data = (int *)mlx_get_data_addr(m.w.img_ptr, &m.w.bpp, &m.w.size_l, &m.w.img_endian);
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

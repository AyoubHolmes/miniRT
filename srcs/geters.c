/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:13:07 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/22 17:48:42 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx.h>

int				inter(t_ray r, double *distance,
				double *t, t_p_shadow *t_shadow)
{
	if (t_shadow->p->id == 4)
		return (sphere_handler(r, distance, t, t_shadow));
	if (t_shadow->p->id == 5)
		return (plane_handler(r, distance, t, t_shadow));
	if (t_shadow->p->id == 6)
		return (square_handler(r, distance, t, t_shadow));
	if (t_shadow->p->id == 7)
		return (cylinder_handler(r, distance, t, t_shadow));
	if (t_shadow->p->id == 8)
		return (triangle_handler(r, distance, t, t_shadow));
	return (t_shadow->color);
}

int				get_pixel_color(t_ray r, double *distance,
				double *d_shadow, t_data d)
{
	double		t;
	t_objects	*p;
	t_p_shadow	t_shadow;

	t_shadow.color = 0;
	*distance = INT_MAX;
	t_shadow.d_shadow = INT_MAX;
	p = d.obj;
	t_shadow.am = d.a;
	t_shadow.obj = d.obj;
	t_shadow.cam_dir = r.b;
	t_shadow.lights = d.lights;
	while (p != NULL)
	{
		t_shadow.p = p;
		t_shadow.color = inter(r, distance, &t, &t_shadow);
		p = p->next;
	}
	return (t_shadow.color);
}

void			save_draw_handler(t_main *m)
{
	if (m->is_save == 1)
		save_bmp_image(*m);
	else
		mlx_put_image_to_window(m->w.mlx_ptr, m->w.win_ptr, m->w.img_ptr, 0, 0);
}

void			graphic_drawer(t_main *m)
{
	int			i;
	int			j;
	int			k;
	double		distance[4];
	t_ray		r;

	j = 0;
	k = 0;
	while (j < m->d.r.y)
	{
		i = m->d.r.x - 1;
		while (i >= 0)
		{
			distance[2] = (double)i / (double)m->d.r.x;
			distance[3] = (double)j / (double)m->d.r.y;
			r = get_t_ray(m->d, distance[2], distance[3]);
			m->w.img_data[k++] = get_pixel_color(r, &distance[0], &distance[1],
								m->d);
			i--;
		}
		j++;
	}
	save_draw_handler(m);
}

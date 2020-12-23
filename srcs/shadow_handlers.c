/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:27:58 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 09:34:59 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int					shadow_checker(t_p_shadow *t_shadow)
{
	double			a;
	double			b;
	t_vector		v1;
	t_vector		v2;

	a = length(substract(t_shadow->light_pos, t_shadow->new_start));
	b = length(substract(t_shadow->pos_hit, t_shadow->new_start));
	v1 = make_unit_vector(t_shadow->cam_dir);
	v2 = make_unit_vector(substract(t_shadow->pos_hit, t_shadow->light_pos));
	if (scalar(v1, v2) >= 0.01 && a >= b)
		return (1);
	return (0);
}

t_vector			appro_corrector(t_vector v)
{
	t_vector v2;

	v2 = add(v, (t_vector){1e-4f, 1e-4f, 1e-4f});
	return (v2);
}

double				t_shadow_calculator(t_objects *p, t_ray r, double *distance)
{
	double t;

	t = -1;
	if (p->id == 4)
		t = equation_sphere(r, p, distance);
	else if (p->id == 5)
		t = equation_plane(r, p, distance);
	else if (p->id == 6)
		t = equation_square(r, p, distance);
	else if (p->id == 7)
		t = equation_cylinder(r, p, distance).t;
	else if (p->id == 8)
		t = equation_triangle(r, p, distance);
	return (t);
}

double				inter_shadow_funcs(t_p_shadow *t_shadow,
					t_objects *p, t_objects *lights)
{
	double			t;
	t_objects		*l;
	t_ray			r;

	t_shadow->new_start = add(t_shadow->new_start,
					multiple(1e-4f, t_shadow->object_dir));
	r.a = appro_corrector(t_shadow->new_start);
	l = lights;
	while (l != NULL)
	{
		t_shadow->light_pos = (*(t_light*)l->content).light_pos;
		r.b = make_unit_vector(appro_corrector(\
			substract(t_shadow->light_pos, t_shadow->new_start)));
		t = t_shadow_calculator(p, r, &t_shadow->d_shadow);
		if (t > 0)
		{
			t_shadow->pos_hit = line_point(r, t);
			return (t);
		}
		l = l->next;
	}
	return (-1);
}

int					shadow_handler(t_p_shadow *t_shadow,
					t_objects *lights, int color)
{
	t_vector		shadow_color;
	t_objects		*p;
	double			t;

	shadow_color = multiple((double)1 / 255, t_shadow->color_shadow);
	p = t_shadow->obj;
	while (p != NULL)
	{
		if (p != t_shadow->p)
		{
			t = inter_shadow_funcs(t_shadow, p, lights);
			if (t >= 0 && shadow_checker(t_shadow) == 1)
			{
				shadow_color = multiple(t_shadow->am.perc, shadow_color);
				return (rgb_maker(color_clamping(shadow_color)));
			}
		}
		p = p->next;
	}
	return (color);
}

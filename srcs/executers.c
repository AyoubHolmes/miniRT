/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:40:58 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/04 13:12:06 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector			light_dif_spec(t_vector norm,
						t_vector *vecs, t_objects *lights, t_vector color)
{
	t_vector		diffuse;
	t_objects		*l;
	t_light			light;
	t_vector		li;
	t_vector		r1;

	diffuse = (t_vector){0, 0, 0};
	l = lights;
	color = multiple((double)1 / 255, color);
	while (l != NULL)
	{
		light = *(t_light*)l->content;
		li = make_unit_vector(substract(light.light_pos, vecs[0]));
		r1 = make_unit_vector(substract(multiple(2 * scalar(norm, li), norm)
		, li));
		diffuse = add(diffuse, color_diffuse(multiple((double)1 / 255,
		color), light, li, norm));
		diffuse = add(diffuse, color_spec(multiple((double)1 / 255,
		light.light_color), r1, vecs[1], light.brightness));
		l = l->next;
	}
	return (diffuse);
}

int					color_calculator(t_ray r,
					double t, t_objects *lights, t_vector norm)
{
	t_vector		a_dif_spec[2];
	t_objects		*l;
	t_vector		color;
	t_vector		*vecs;

	vecs = (t_vector*)malloc(sizeof(t_vector) * 2);
	a_dif_spec[0] = (t_vector){0, 0, 0};
	color = (t_vector){0, 0, 0};
	l = lights;
	a_dif_spec[0] = multiple(0.5, multiple((double)1 / 255, r.color_obj));
	vecs[0] = line_point(r, t);
	vecs[1] = make_unit_vector(multiple(-1, r.b));
	a_dif_spec[1] = light_dif_spec(norm, vecs, lights, r.color_obj);
	color = add(a_dif_spec[0], a_dif_spec[1]);
	free(vecs);
	return (rgb_maker(color_clamping(color)));
}

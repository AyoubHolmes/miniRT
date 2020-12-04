/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:47:37 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/04 11:53:54 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera		icam(t_vector *vecs, double fov, \
					int xresolution, int yresolution)
{
	t_icam		calc;
	t_camera	cam;

	calc.up = (t_vector){0, 1, 0};
	calc.aspect = (double)xresolution / (double)yresolution;
	calc.theta = fov * M_PI / 180;
	calc.half_height = tan(calc.theta / 2);
	calc.half_width = calc.aspect * calc.half_height;
	cam.origine = vecs[0];
	calc.w = make_unit_vector(multiple(-1, vecs[1]));
	calc.u = make_unit_vector(v_product(calc.w, calc.up));
	calc.v = v_product(calc.w, calc.u);
	calc.v1 = substract(cam.origine, multiple(calc.half_width, calc.u));
	calc.v2 = add(multiple(calc.half_height, calc.v), calc.w);
	cam.start_point = substract(calc.v1, calc.v2);
	cam.horizontal = multiple(2 * calc.half_width, calc.u);
	cam.vertical = multiple(2 * calc.half_height, calc.v);
	return (cam);
}

t_ray			get_t_ray(t_data d, double u, double v)
{
	t_camera	cam;
	t_vector	vecs[2];

	vecs[0] = d.cameras->cam.view_point;
	vecs[1] = d.cameras->cam.cam_normal;
	cam = icam(vecs, d.cameras->cam.fov, d.r.x, d.r.y);
	return (initialize_t_ray(cam.origine, substract(add(cam.start_point, \
		add(multiple(u, cam.horizontal), multiple(v, cam.vertical))), \
		cam.origine)));
}

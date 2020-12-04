/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:26:32 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:30:21 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray		initialize_t_ray(t_vector a, t_vector b)
{
	t_ray r;

	r.a = a;
	r.b = (b);
	r.distance = 1e30f;
	return (r);
}

t_vector	t_ray_origine(t_ray r)
{
	return (r.a);
}

t_vector	t_ray_direction(t_ray r)
{
	return (r.b);
}

t_vector	line_point(t_ray r, double t)
{
	return (add(r.a, multiple(t, r.b)));
}

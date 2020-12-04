/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:00:28 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/04 12:17:34 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vector.h"

typedef struct			s_ray
{
	t_vector			a;
	t_vector			b;
	double				distance;
	int					id;
	t_vector			color_obj;
}						t_ray;

t_ray					initialize_t_ray(t_vector a, t_vector b);
t_vector				t_ray_origine(t_ray r);
t_vector				t_ray_direction(t_ray r);
t_vector				line_point(t_ray r, double t);
#endif

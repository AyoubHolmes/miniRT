/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:54:17 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:03:03 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		color_diffuse(t_vector color_obj, \
				t_light light, t_vector li, t_vector norm)
{
	t_vector	color;
	double		l;

	l = scalar(li, norm);
	l = l < 0 ? 0 : l;
	color.x = color_obj.x * light.light_color.x * l * light.brightness;
	color.y = color_obj.y * light.light_color.y * l * light.brightness;
	color.z = color_obj.z * light.light_color.z * l * light.brightness;
	return (color);
}

t_vector		color_spec(t_vector light_color,\
				t_vector r, t_vector v, double brighness)
{
	t_vector	color;
	double		l;
	double		alpha;

	alpha = 800;
	l = scalar(r, v);
	l = l < 0 ? 0 : l;
	color.x = light_color.x * pow(l, alpha);
	color.y = light_color.y * pow(l, alpha);
	color.z = light_color.z * pow(l, alpha);
	return (color);
}

int				rgb_maker(t_vector rgb)
{
	return (((int)(rgb.x * 255.99) << 16) + \
		((int)(rgb.y * 255.99) << 8) + (int)(rgb.z * 255.99));
}

t_vector		color_clamping(t_vector color)
{
	color.x = (color.x < 1) ? color.x : 1;
	color.x = (color.x >= 0) ? color.x : 0;
	color.y = (color.y < 1) ? color.y : 1;
	color.y = (color.y >= 0) ? color.y : 0;
	color.z = (color.z < 1) ? color.z : 1;
	color.z = (color.z >= 0) ? color.z : 0;
	return (color);
}

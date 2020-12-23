/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:50:14 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:36:30 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects		*sphere_initialize(char **sc, \
				char **color_sphere, char *sphere_diametre)
{
	t_objects	*obj;
	t_sphere	*sphere;

	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		return (0);
	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	sphere->sphere_center = initialize_vector(ft_atof(sc[0]), \
							ft_atof(sc[1]), ft_atof(sc[2]));
	sphere->sphere_diametre = ft_atof(sphere_diametre);
	sphere->color_sphere = initialize_vector(ft_atof(color_sphere[0]), \
							ft_atof(color_sphere[1]), ft_atof(color_sphere[2]));
	obj->id = 4;
	obj->content = sphere;
	obj->next = NULL;
	return (obj);
}

t_objects		*plane_initialize(char **p_c, \
				char **p_n, char **c_p)
{
	t_objects	*obj;
	t_plane		*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		return (0);
	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	plane->plane_center = initialize_vector(ft_atof(p_c[0]),
							ft_atof(p_c[1]), ft_atof(p_c[2]));
	plane->plane_norm = initialize_vector(ft_atof(p_n[0]), \
							ft_atof(p_n[1]), ft_atof(p_n[2]));
	plane->color_plane = initialize_vector(ft_atof(c_p[0]), \
							ft_atof(c_p[1]), ft_atof(c_p[2]));
	obj->id = 5;
	obj->content = plane;
	obj->next = NULL;
	return (obj);
}

t_objects		*square_initialize(char **s_c, \
				char **s_q, char **c_s, char *size)
{
	t_objects	*obj;
	t_square	*square;

	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	if (!(square = (t_square*)malloc(sizeof(t_square))))
		return (0);
	square->size = ft_atof(size);
	square->square_center = initialize_vector(ft_atof(s_c[0]),
							ft_atof(s_c[1]), ft_atof(s_c[2]));
	square->square_norm = initialize_vector(ft_atof(s_q[0]),
							ft_atof(s_q[1]), ft_atof(s_q[2]));
	square->color_square = initialize_vector(ft_atof(c_s[0]),
							ft_atof(c_s[1]), ft_atof(c_s[2]));
	obj->id = 6;
	obj->content = square;
	obj->next = NULL;
	return (obj);
}

t_objects		*cylinder_initialize(t_cy_init cy_init)
{
	t_objects	*obj;
	t_cylinder	*cylinder;

	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	if (!(cylinder = (t_cylinder*)malloc(sizeof(t_cylinder))))
		return (0);
	cylinder->cylinder_diametre = ft_atof(cy_init.cylinder_diametre);
	cylinder->cylinder_height = ft_atof(cy_init.cylinder_height);
	cylinder->cylinder_center = initialize_vector(ft_atof(\
				cy_init.cylinder_center[0]),
				ft_atof(cy_init.cylinder_center[1]), \
				ft_atof(cy_init.cylinder_center[2]));
	cylinder->cylinder_norm = initialize_vector(\
			ft_atof(cy_init.cylinder_norm[0]), \
			ft_atof(cy_init.cylinder_norm[1]), ft_atof(cy_init.cylinder_norm[2]));
	cylinder->cylinder_color = initialize_vector(\
			ft_atof(cy_init.color_cylinder[0]),\
			ft_atof(cy_init.color_cylinder[1]), ft_atof(cy_init.color_cylinder[2]));
	obj->id = 7;
	obj->content = cylinder;
	obj->next = NULL;
	return (obj);
}

t_objects		*triangle_initialize(char **first_point, char **second_point\
				, char **third_point, char **triangle_color)
{
	t_objects	*obj;
	t_triangle	*tr;

	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	if (!(tr = (t_triangle*)malloc(sizeof(t_triangle))))
		return (0);
	tr->first_point = initialize_vector(ft_atof(\
				first_point[0]),
				ft_atof(first_point[1]), ft_atof(first_point[2]));
	tr->second_point = initialize_vector(ft_atof(\
				second_point[0]),
				ft_atof(second_point[1]), ft_atof(second_point[2]));
	tr->third_point = initialize_vector(ft_atof(\
				third_point[0]),
				ft_atof(third_point[1]), ft_atof(third_point[2]));
	tr->triangle_color = initialize_vector(ft_atof(\
				triangle_color[0]),
				ft_atof(triangle_color[1]), ft_atof(triangle_color[2]));
	obj->id = 8;
	obj->content = tr;
	obj->next = NULL;
	return (obj);
}

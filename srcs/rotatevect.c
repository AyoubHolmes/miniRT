/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatevect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:40:08 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:45:58 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		rot_x(t_vector vec, double teta)
{
	double tmp;

	tmp = vec.y;
	teta = teta * M_PI / 180.0;
	vec.y = (vec.y * cos(teta)) - (vec.z * sin(teta));
	vec.z = tmp * sin(teta) + (vec.z * cos(teta));
	return (vec);
}

t_vector		rot_y(t_vector vec, double teta)
{
	double		tmp;

	tmp = vec.z;
	teta = teta * M_PI / 180.0;
	vec.z = (vec.z * cos(teta)) - (vec.x * sin(teta));
	vec.x = tmp * sin(teta) + (vec.x * cos(teta));
	return (vec);
}

t_vector		rot_z(t_vector vec, double teta)
{
	double		tmp;

	tmp = vec.x;
	teta = teta * M_PI / 180.0;
	vec.x = (vec.x * cos(teta)) - (vec.y * sin(teta));
	vec.y = tmp * sin(teta) + (vec.y * cos(teta));
	return (vec);
}

t_vector		rotatevect(t_vector torot, t_vector rotvec)
{
	torot = rot_x(torot, rotvec.x);
	torot = rot_y(torot, rotvec.y);
	torot = rot_z(torot, rotvec.z);
	return (torot);
}

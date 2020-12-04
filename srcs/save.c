/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:02:37 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:26:15 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bmp			init_bmph(t_main move)
{
	t_bmp		res;

	res.id[0] = 'B';
	res.id[1] = 'M';
	res.file_size = 54 + 4 * (int)move.d.r.x * (int)move.d.r.y;
	res.unused = 0;
	res.offset = 54;
	res.dib = 54 - 14;
	res.width = (int)move.d.r.x;
	res.height = -(int)move.d.r.y;
	res.plane[0] = 1;
	res.plane[1] = 0;
	res.bpp[0] = 32;
	res.bpp[1] = 0;
	res.compression = 0;
	res.raw_bitmap_size = 4 * (int)move.d.r.x * (int)move.d.r.y;
	res.resx = 0;
	res.resy = 0;
	res.number_of_colors = 0;
	res.important_colors = 0;
	return (res);
}

void			save_bmp_image(t_main move)
{
	t_bmp		img;
	int			file;

	file = open("rt.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	img = init_bmph(move);
	write(file, &img, 54);
	write(file, move.w.img_data, img.raw_bitmap_size);
	close(file);
}

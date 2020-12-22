/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:15:52 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/22 18:46:21 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <limits.h>
# include "camera.h"
# include "bmp.h"
# define BUFFER_SIZE 100

typedef struct					s_window
{
	void						*mlx_ptr;
	void						*win_ptr;
	void						*img_ptr;
	int							*img_data;
	int							bpp;
	int							size_l;
	int							img_endian;
}								t_window;

typedef struct					s_resolution
{
	int							x;
	int							y;
	int							done;
}								t_resolution;

typedef struct					s_ambient
{
	double						perc;
	t_vector					t_ambient_color;
	int							done;
}								t_ambient;

typedef struct					s_cam_data
{
	t_vector					view_point;
	t_vector					cam_normal;
	double						fov;
}								t_cam_data;

typedef struct					s_light
{
	t_vector					light_pos;
	double						brightness;
	t_vector					light_color;
}								t_light;

typedef struct					s_sphere
{
	t_vector					sphere_center;
	double						sphere_diametre;
	t_vector					color_sphere;
}								t_sphere;

typedef struct					s_plane
{
	t_vector					plane_center;
	t_vector					plane_norm;
	t_vector					color_plane;
}								t_plane;

typedef struct					s_square
{
	t_vector					square_center;
	t_vector					square_norm;
	double						size;
	t_vector					color_square;
}								t_square;

typedef struct					s_cylinder
{
	t_vector					cylinder_center;
	t_vector					cylinder_norm;
	t_vector					cylinder_color;
	double						cylinder_diametre;
	double						cylinder_height;
}								t_cylinder;

typedef struct					s_triangle
{
	t_vector					first_point;
	t_vector					second_point;
	t_vector					third_point;
	t_vector					triangle_color;
}								t_triangle;

typedef struct					s_objects
{
	void						*content;
	int							id;
	struct s_objects			*next;
}								t_objects;

typedef struct					s_camlist
{
	t_cam_data					cam;
	struct s_camlist			*next;
	struct s_camlist			*prev;
}								t_camlist;

typedef struct					s_data
{
	t_resolution				r;
	t_ambient					a;
	t_camlist					*cameras;
	t_objects					*lights;
	t_objects					*obj;
	t_objects					*last_obj;
	int							pixel;
}								t_data;

typedef struct					s_passage_cy
{
	t_vector					n;
	double						t;
	double						distance;
}								t_passage_cy;

typedef struct					s_p_shadow
{
	int							color;
	t_ambient					am;
	t_vector					new_start;
	t_vector					color_shadow;
	t_vector					light_pos;
	t_vector					pos_hit;
	t_vector					object_dir;
	double						d_shadow;
	t_objects					*obj;
	t_objects					*p;
	t_vector					cam_dir;
	t_objects					*lights;
}								t_p_shadow;

typedef struct					s_main
{
	t_data						d;
	t_window					w;
	int							is_save;
}								t_main;

typedef struct					s_err
{
	int							is_checked;
	int							line;
}								t_err;

typedef struct					s_icam
{
	t_camera					cam;
	t_vector					up;
	t_vector					u;
	t_vector					v;
	t_vector					w;
	double						aspect;
	double						theta;
	double						half_height;
	double						half_width;
	t_vector					v1;
	t_vector					v2;

}								t_icam;

typedef struct					s_cy_init
{
	char						**cylinder_center;
	char						**cylinder_norm;
	char						**color_cylinder;
	char						*cylinder_diametre;
	char						*cylinder_height;
}								t_cy_init;

t_objects						*ft_lstnew(void *content);
void							ft_lstadd_back(t_objects **alst, t_objects \
								*new);
t_camlist						*ft_double_lst_cam_new(t_cam_data cam);
void							fcam_add(t_camlist **alst, t_camlist *new);
t_camlist						*fcam_last(t_camlist **alst);
t_camlist						*get_cam_previous(t_camlist **alst);
t_camlist						*get_cam_next(t_camlist **alst);
t_camlist						*getcams(t_data d);
t_ray							get_t_ray(t_data d, double u, double v);
t_objects						*get_ligths(t_objects *obj);
int								ft_strncmp(const char *s1, \
								const char *s2, size_t n);
void							ft_putchar_fd(char c, int fd);
void							ft_putnbr_fd(int n, int fd);
void							save_bmp_image(t_main move);
t_bmp							init_bmph(t_main	move);
t_objects						*cam_initializer(char **vp, char \
								**cn, char *fov);
t_objects						*ligth_initializer(char **lp, \
								char **lc, char *brightness);
t_objects						*sphere_initialize(char **sc, \
								char **color_sphere, char *sphere_diametre);
t_objects						*plane_initialize(char **plane_center, char \
								**plane_norm, char **color_plane);
t_objects						*square_initialize(char **square_center, \
								char **square_norm, char **color_square, \
								char *size);
t_objects						*cylinder_initialize(t_cy_init cy_init);
t_objects						*triangle_initialize(char **first_point, char \
								**second_point, char **third_point, \
								char **triangle_color);
void							vector_printer (t_vector v);
void							resolution_printer(t_resolution res);
void							ambient_printer (t_ambient ab);
void							camera_printer (t_cam_data *cam);
void							light_printer (t_light *light);
void							sphere_printer (t_sphere *s);
void							plane_printer (t_plane *p);
void							square_printer (t_square *p);
void							cylinder_printer(t_cylinder *cy);
void							triangle_printer(t_triangle *tr);
void							objects_debugger(t_data d);
int								ft_isdigit(int c);
int								ft_isint(char *c);
int								ft_ispositiveint(char *c);
int								ft_isfloat(char *c);
int								ft_ispositivefloat(char *c);
int								ft_isintensityfloat(char *c);
int								ft_iscolorfloat(char *c);
int								ft_isvector(char *c, int (*func)());
int								data_checker(char *line);
int								r_checker(char *line);
int								a_checker(char *line);
int								c_checker(char *line);
int								l_checker(char *line);
int								sp_checker(char *line);
int								pl_checker(char *line);
int								sq_checker(char *line);
int								cy_checker(char *line);
int								tr_checker(char *line);
int								ft_putstr_fd(char *s, int fd);
void							error_printer(t_err err);
int								ft_nbr_words(char *str, char c);
int								nb_word(char *str);
void							*ft_memcpy(void *dst, const \
								void *src, size_t n);
size_t							ft_strlen(const char *s);
char							*ft_substr(char const *src, unsigned \
								int start, size_t n);
char							*ft_strchr(char *str, int c);
char							*ft_strjoin(char const *s1, char const *s2);
int								get_next_line(int fd, char **line);
char							**ft_split(char const *s, char c);
char							**ft_split_whitespaces(char *str);
int								data_id(char **data);
void							data_insertion(t_data *d, char **data);
void							r_insertion(t_data *d, char **data);
void							a_insertion(t_data *d, char **data);
void							c_insertion(t_data *d, char **data);
void							l_insertion(t_data *d, char **data);
void							sp_insertion(t_data *d, char **data);
void							pl_insertion(t_data *d, char **data);
void							sq_insertion(t_data *d, char **data);
void							cy_insertion(t_data *d, char **data);
void							tr_insertion(t_data *d, char **data);
t_vector						color_diffuse(t_vector color_obj, t_light \
								light, t_vector li, t_vector norm);
t_vector						color_spec(t_vector light_color, t_vector \
								r, t_vector v, double brighness);
int								rgb_maker(t_vector rgb);
t_vector						color_clamping(t_vector color);
double							equation_sphere(t_ray r, t_objects *obj, \
								double *distance);
double							equation_plane(t_ray r, t_objects *obj, \
								double *distance);
double							equation_square(t_ray r, t_objects *obj, \
								double *distance);
t_passage_cy					equation_cylinder(t_ray r, t_objects *obj,\
								double *distance);
double							equation_triangle(t_ray r, t_objects *obj,\
								double *distance);
int								sphere_handler(t_ray r, double *distance,
								double *t, t_p_shadow *t_shadow);
int								plane_handler(t_ray r, double *distance,
								double *t, t_p_shadow *t_shadow);
int								square_handler(t_ray r, double *distance,
								double *t, t_p_shadow *t_shadow);
int								cylinder_handler(t_ray r, double *distance,
								double *t, t_p_shadow *t_shadow);
int								triangle_handler(t_ray r, double *distance,
								double *t, t_p_shadow *t_shadow);
int								shadow_handler(t_p_shadow *t_shadow, t_objects \
								*lights, int color);
int								color_calculator(t_ray r, double t, t_p_shadow *t_shadow,
												t_vector n);
int								get_pixel_color(t_ray r, double *distance,
								double *d_shadow, t_data d);
int								mlx_get_screen_size(void *mlx_ptr, \
								int *sizex, int *sizey);
void							rotate(t_data *d, char **data);
void							translate(t_data *d, char **data);
void							my_free_main(void *t);
void							free_list(t_objects *list);
t_vector						rotatevect(t_vector to_rot, t_vector rotvec);
t_err							file_checker(char *file);
t_data							file_parser(char *file);
void							graphic_drawer(t_main *m);
int								key_press(int keycode, t_main *m);
#endif

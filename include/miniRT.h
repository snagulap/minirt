/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:25:12 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/12 19:16:42 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "ray.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef t_vec3			t_color;

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900

typedef struct s_rgb // colors
{
	double red;
	double green;
	double blue;
	double rgb_in_hex_representation;
}						t_rgb;

typedef struct s_ambient_lightning
{
	double				ambient_lighting_ratio;
	t_rgb				color;
}						t_ambient_lightning;

// typedef struct s_camera
// {
// 	t_coordinates		coordinatess_of_the_view_point;
// 	double				light_lighting_ratio;
// 	t_coordinates		normalized_orientation_vector;
// 	double				horizontal_field_of_view_in_degrees;
// }

typedef struct s_camera
{
	t_ray				ray;
	double				fov;
	double				theta;
	double				aspect_ratio;
	int					image_width;
	int					image_height;
	double				focal_length;
	double				viewport_height;
	double				viewport_width;
	t_vec3				pixel_delta_u;
	t_vec3				pixel_delta_v;
	t_vec3				pixel00_loc;
	t_vec3				viewport_upper_left;
}						t_camera;

// typedef struct s_light
// {
// 	t_coordinates		coordinates_of_the_light_point;
// 	double				light_brightness_ratio;
// 	t_rgb rgb_colors; // bonus
// }						t_light;

typedef struct s_light
{
	t_vec3				coordinates_of_the_light_point;
	double				light_brightness_ratio;
	t_rgb rgb_colors; // bonus
}						t_light;

typedef struct s_sphere
{
	t_vec3				center;
	double				radius;
	t_rgb				rgb_colors;
}						t_sphere;

// typedef struct s_plane
// {
// 	t_coordinates		coordinates_of_a_point_in_the_plane;
// 	t_coordinates		normalized_normal_vector;
// 	t_rgb				rgb_colors;
// }						t_plane;

typedef struct s_plnae
{
	t_vec3				pointC;
	t_vec3				normalV;
}						t_plane;

typedef struct s_cylinder
{
	t_vec3				coordinates_of_center_of_the_cylinder;
	t_vec3				normalized_vector_of_axis_of_cylinder;
	double				cylinder_diameter;
	double				cylinder_hight;
	t_rgb				rgb_colors;
}						t_cylinder;

typedef struct s_minirt
{
	t_ambient_lightning	lightning;
	t_camera			camera;
	t_light				light;
	//	light			*light_arr; (bonus)
	t_sphere			*sphere_arr;
	t_plane				*plane_arr;
	t_cylinder			*cylinder_arr;
}						miniRT;

// void					image_Setup(void *mlx, void *window, t_camera cam);
void					image_Setup1(void *mlx, void *window);
t_camera				camera_viewpoint(void);
// void					camera_viewpoint(void *mlx, void *window);
t_color					rayColor(const t_ray *ray);
int						solveQuadratic(double a, double b, double c,
							double *root1, double *root2);
int						hitSphere(const t_sphere *sphere, const t_ray *ray,
							double *t);

int						solveQuadratic(double a, double b, double c,
							double *root1, double *root2);
int						hitPlane(const t_ray *ray, const t_plane *plane,
							double *t, t_vec3 *normal);

double					ft_atodouble(char *str, int *i);
int						ft_line_error_message(int line);
int						ft_check_color_range(t_rgb *color);
int						ft_check_normalized_vector_range(t_vec3 *xyz);

// ft_init_check_input
void					ft_check_input(miniRT *data, char *argv);
// void	camera_viewpoint(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:25:12 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/04 14:15:14 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <math.h>

typedef struct s_rgb // colors
{
	double	red;
	double	green;
	double	blue;
	double	rgb_in_hex_representation;
}	t_rgb;

typedef struct s_vec
{
	double	e[3];
}	t_vec3;

typedef struct s_coorinates
{
	double	x;
	double	y;
	double	z;
}	t_coordinates;

typedef struct s_ambient_lightning
{
	double	ambient_lighting_ratio;
	t_rgb	color;
}	t_ambient_lightning;

typedef struct s_camera
{
	t_coordinates	coordinatess_of_the_view_point;
	double			light_lighting_ratio;
	t_coordinates	normalized_orientation_vector;
	double			horizontal_field_of_view_in_degrees;
}	t_camera;

typedef struct s_light
{
	t_coordinates	coordinates_of_the_light_point;
	double			light_brightness_ratio;
	t_rgb			rgb_colors;//bonus
}	t_light;

typedef struct s_sphere
{
	t_coordinates	coordinates_of_the_sphere_center;
	double			sphere_diameter;
	t_rgb			rgb_colors;
}	t_sphere;

typedef struct s_plane
{
	t_coordinates	coordinates_of_a_point_in_the_plane;
	t_coordinates	normalized_normal_vector;
	t_rgb			rgb_colors;
}	t_plane;

typedef struct s_cylinder
{
	t_coordinates	coordinates_of_center_of_the_cylinder;
	t_coordinates	normalized_vector_of_axis_of_cylinder;
	double			cylinder_diameter;
	double			cylinder_hight;
	t_rgb			rgb_colors;
}	t_cylinder;

typedef struct s_minirt
{
	t_ambient_lightning		lightning;
	t_camera				camera;
	t_light					light;//light             *light_arr; (bonus)
	t_sphere				*sphere_arr;
	t_plane					*plane_arr;
	t_cylinder				*cylinder_arr;
}	t_minirt;

t_vec3 make_vec3(double e0, double e1, double e2);
t_vec3 vec3_negate(t_vec3 v);
double vec3_get(const t_vec3* v, int i);
void   vec3_set(t_vec3* v, int i, double value);
t_vec3 vec3_add(t_vec3 u, t_vec3 v);
t_vec3 vec3_subtract(t_vec3 u, t_vec3 v);
t_vec3 vec3_multiply(t_vec3 u, t_vec3 v);
t_vec3 vec3_scalar_multiply(t_vec3 v, double t);
t_vec3 vec3_scalar_divide(t_vec3 v, double t);
double vec3_dot(t_vec3 u, t_vec3 v);
t_vec3 vec3_cross(t_vec3 u, t_vec3 v);
double vec3_length(t_vec3 v);
double vec3_length_squared(t_vec3 v);
t_vec3 vec3_normalize(t_vec3 v);


#endif
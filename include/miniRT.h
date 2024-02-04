/* ************************************************************************** */
/*                                                                            */ 
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:25:12 by snagulap          #+#    #+#             */
/*   Updated: 2024/01/13 17:29:00 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "ray.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
// typedef t_vec3	t_color;

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900



typedef struct s_plnae
{
	t_vec3				pointC;
	t_vec3				normalV;
    t_rgb				rgb_colors;
}						t_plane;
typedef struct s_obj
{
	t_vec3				cor;
	t_vec3				nv;
	float				rad;
	float				cy_he;
	float				cy_dia;
	double				radius;
	t_vec3				rgb;
}						t_obj;

typedef struct s_hittable{
    int type;  // Type identifier for different hittable objects
    struct {
        t_obj objt;
    }data;
} t_hittable;

// typedef struct s_hittble_list{
//     t_hittable** objects;
//     size_t size;
// } t_hittable_list;

typedef struct s_point3{
    double x, y, z;
} t_point3;

typedef struct s_camera
{
	t_ray				ray;
	double				fov;
	double				theta;
	double				aspect_ratio;
	int					image_width;
	int					image_height;
	double				focal_length;
	double				viewport_height_half;
	double				viewport_width_half;
	double				viewport_u;
	double				viewport_v;
	t_vec3				pixel_delta_u;
	t_vec3				pixel_delta_v;
	t_vec3				pixel00_loc;
	t_vec3				viewport_upper_left;
}						t_camera;

typedef struct s_light {
    t_vec3 light_point;
    double brightness;
    t_vec3 color; // Change t_rgb to t_color
} t_light;

typedef struct s_ambient_lightning
{
	double				am_ratio;
	t_vec3				color;
}						t_ambient_lightning;

// typedef struct s_cylinder
// {
// 	t_vec3				coordinates_of_center_of_the_cylinder;
// 	t_vec3				normalized_vector_of_axis_of_cylinder;
// 	double				cylinder_diameter;
// 	double				cylinder_hight;
// 	t_color				rgb_colors;
// }						t_cylinder;

t_vec3	make_color(double red, double green, double blue);
// t_rgb	make_color_rgb(double red, double green, double blue);

typedef struct {
    bool front_face;
    float t;
    t_vec3 p;
    t_vec3 normal;
    t_vec3 color;  // Assuming t_color and t_vec3 are defined appropriately
} t_hit_record;

// typedef struct s_minirt
// {
// 	t_ambient_lightning	lightning;
// 	t_camera			camera;
// 	t_light				light;
// 	//	light			*light_arr; (bonus)
// 	t_sphere			*sphere_arr;
// 	t_plane				*plane_arr;
// 	t_cylinder			*cylinder_arr;
// }						miniRT;

// void					image_Setup(void *mlx, void *window, t_camera cam);
void					image_Setup1(void *mlx, void *window);
bool hit_sphere(const t_ray* r, double tmin, double tmax, t_hit_record* rec, t_obj *objt);
// void					camera_viewpoint(void *mlx, void *window);
// void					camera_viewpoint(void *mlx, void *window);
// t_color					rayColor(t_ray *ray);
// t_color rayColor(t_ray *ray, t_sphere   *sphere);
// t_color rayColor(t_ray *ray, t_plane *plane);
// t_color rayColor(const t_ray *ray, const t_plane *plane);
// t_color rayColor(t_ray *ray, t_sphere *spheres, int sphere_count, t_plane *planes, int plane_count, t_light *lights, int light_count);

// int						solveQuadratic(double a, double b, double c,
							// double *root1, double *root2);
// int						hitSphere(const t_sphere *sphere, const t_ray *ray,
							// double *t);
// int hit_sphere(const t_sphere* sphere, const t_ray* ray, float t_min, float t_max, t_hit_record* rec);
// int hitSphere(const t_sphere *sphere, const t_ray *ray, double *t, t_vec3 *normal);
// int	hitSphere(const t_sphere *sphere, const t_ray *ray, double *t);
// int						solveQuadratic(double a, double b, double c,
// 							double *root1, double *root2);
// int						hitPlane(const t_plane *plane, t_vec3 shadow_ray,
// 							double *t, t_vec3 *normal);
int	hitPlane(const t_ray *ray, t_plane *plane, double *t, t_vec3 *normal);

t_vec3	rayColor(t_ray *ray, t_obj* object);
// double					ft_atodouble(char *str, int *i);
// int						ft_line_error_message(int line);
// // int						ft_check_color_range(t_rgb *color);
// int						ft_check_normalized_vector_range(t_vec3 *xyz);

void	camera_viewpoint(void *mlx, void *window, t_camera *camera);
// // ft_init_check_input
// void					ft_check_input(miniRT *data, char *argv);
// void	camera_viewpoint(void);

#endif
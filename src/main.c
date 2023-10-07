/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:14:55 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/07 20:49:02 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ray.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

typedef t_vec3	t_color;

t_vec3	pix_color(t_vec3 pixel_color)
{
	t_vec3	v2;

	v2.e[0] = (int)(255.999 * pixel_color.e[0]);
	v2.e[1] = (int)(255.999 * pixel_color.e[1]);
	v2.e[2] = (int)(255.999 * pixel_color.e[2]);
	return (v2);
}

t_vec3	unit_vector(const t_vec3 *v)
{
	double	length;
	t_vec3	unit;

	length = sqrt(v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]);
	unit.e[0] = v->e[0] / length;
	unit.e[1] = v->e[1] / length;
	unit.e[2] = v->e[2] / length;
	return (unit);
}

double	hit_sphere(t_vec3 center, double radius, t_ray *r)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec3_sub(r->orig, center);
	a = vec3_dot(r->dir, r->dir);
	b = 2.0 * vec3_dot(oc, r->dir);
	c = vec3_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		return (-1.0);
	}
	else
	{
		return ((-b - sqrt(discriminant)) / (2.0 * a));
	}
}

t_color	ray_color_sphere(t_ray *r)
{
	double	t;
	t_vec3	N;
	t_color	color;
	t_vec3	unit_direction;
	double	a;
	t_color	white_color;
	t_color	blue_color;
	t_color	interpolated_color;

	t = hit_sphere(make_vec3(0, 0, -1), 0.5, r);
	if (t > 0.001)
	{
		N = vec3_normalize(vec3_sub(ray_at(r, t), make_vec3(0, 0, -1)));
		color.e[0] = 0.5 * (N.e[0] + 1);
		color.e[1] = 0.5 * (N.e[1] + 1);
		color.e[2] = 0.5 * (N.e[2] + 1);
		return (color);
	}
	unit_direction = vec3_normalize(r->dir);
	a = 0.5 * (unit_direction.e[1] + 1.0);
	white_color.e[0] = 1.0;
	white_color.e[1] = 1.0;
	white_color.e[2] = 1.0;
	blue_color.e[0] = 0.5;
	blue_color.e[1] = 0.7;
	blue_color.e[2] = 1.0;
	interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a
		* blue_color.e[0];
	interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a
		* blue_color.e[1];
	interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a
		* blue_color.e[2];
	return (interpolated_color);
}

void	render(void *mlx, void *window, int image_width, int image_height,
		t_color pixel_color)
{
	int	color;

	for (int j = 0; j < image_width; j++)
	{
		for (int i = 0; i < image_height; i++)
		{
			color = ((int)(255.999 * pixel_color.e[0]) << 16) | ((int)(255.999
						* pixel_color.e[1]) << 8) | (int)(255.999
					* pixel_color.e[2]);
			mlx_pixel_put(mlx, window, j, i, color);
		}
	}
}

// void	camera_viewpoint(void *mlx, void *window)
// {
// 	int		j;
// 	int		i;
// 	int		color;
// 	double	aspect_ratio;
// 	int		image_width;
// 	double	focal_length;
// 	double	viewport_height;
// 	int		image_height;
// 	double	viewport_width;
// 	t_vec3	camera_center;
// 	t_vec3	viewport_u;
// 	t_vec3	viewport_v;
// 	t_vec3	pixel_delta_u;
// 	t_vec3	pixel_delta_v;
// 	t_vec3	viewport_upper_left;
// 	t_vec3	pixel_center;
// 	t_vec3	ray_direction;
// 	t_ray	r;
// 	t_color	pixel_color;

// 	j = 0;
// 	i = 0;
// 	aspect_ratio = 16.0 / 9.0;
// 	image_width = 800;
// 	focal_length = 1.0;
// 	viewport_height = 1.0;
// 	image_height = (int)(image_width / aspect_ratio);
// 	viewport_width = ((double)image_width / image_height);
// 	camera_center = make_vec3(0, 0, 0);
// 	viewport_u = make_vec3(viewport_width, 0, 0);
// 	viewport_v = make_vec3(0, -viewport_height, 0);
// 	pixel_delta_u = vec3_scalar_divide(viewport_u, image_width);
// 	pixel_delta_v = vec3_scalar_divide(viewport_v, image_height);
// 	viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera_center,
// 					vec3_scalar_multiply(viewport_u, 0.5)),
// 				vec3_scalar_multiply(viewport_v, 0.5)), make_vec3(focal_length,
// 				focal_length, 0.0));
// 	for (j = 0; j < image_height; j++)
// 	{
// 		for (i = 0; i < image_width; i++)
// 		{
// 			pixel_center = vec3_add(vec3_add(viewport_upper_left,
// 						vec3_scalar_multiply(pixel_delta_u, i)),
// 					vec3_scalar_multiply(pixel_delta_v, j));
// 			ray_direction = vec3_sub(pixel_center, camera_center);
// 			r = make_ray(camera_center, ray_direction);
// 			pixel_color = ray_color_sphere(&r);
// 			color = ((int)(255.999 * pixel_color.e[0]) << 16) | ((int)(255.999
// 						* pixel_color.e[1]) << 8) | (int)(255.999
// 					* pixel_color.e[2]);
// 			mlx_pixel_put(mlx, window, i, j, color);
// 		}
// 	}
// 	mlx_loop(mlx);
// 	mlx_destroy_window(mlx, window);
// }


void	camera_viewpoint(void *mlx, void *window)
{
	int		j;
	int		i;
	int		color;
	double	aspect_ratio;
	int		image_width;
	double	focal_length;
	double	viewport_height;
	int		image_height;
	double	viewport_width;
	t_vec3	camera_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel_center;
	t_vec3	ray_direction;
	t_vec3	pixel00_loc;
	t_ray	r;
	t_color	pixel_color;
	t_vec3	cal;
	t_vec3	cal1;
	t_vec3	cal2;

	j = 0;
	i = 0;
	aspect_ratio = 16.0 / 9.0;
	image_width = 800;
	focal_length = 1.0;
	viewport_height = 2.0;
	image_height = (int)(image_width / aspect_ratio);
	if (image_height < 1)
		image_height = 1;
	viewport_width = viewport_height * ((double)image_width / image_height);
	camera_center = make_vec3(0, 0, 0);
	viewport_u = make_vec3(viewport_width, 0, 0);
	viewport_v = make_vec3(0, -viewport_height, 0);
	pixel_delta_u = vec3_scalar_divide(viewport_u, image_width);
	pixel_delta_v = vec3_scalar_divide(viewport_v, image_height);
	cal = vec3_add(pixel_delta_u, pixel_delta_v);
	cal = vec3_scalar_multiply(cal, 0.5);
	cal1 = vec3_scalar_divide(viewport_v, 2.0);
	cal2 = vec3_scalar_divide(viewport_u, 2.0);
	cal1 = vec3_sub(cal1, cal2);
	cal2 = vec3_sub(camera_center, make_vec3(0, 0, focal_length));
	viewport_upper_left = vec3_sub(cal1, cal2);
	pixel00_loc = vec3_add(viewport_upper_left, cal);
	printf("%f %f %f\n", pixel00_loc.e[0], pixel00_loc.e[1], pixel00_loc.e[2]);
	for (j = 0; j < image_height; j++)
	{
		for (i = 0; i < image_width; i++)
		{
			pixel_center = vec3_add(pixel00_loc,
					vec3_scalar_multiply(pixel_delta_u, i));
			pixel_center = vec3_add(pixel_center,
					vec3_scalar_multiply(pixel_delta_v, j));
			ray_direction = vec3_sub(pixel_center, camera_center);
			r = make_ray(camera_center, ray_direction);
			pixel_color = ray_color_sphere(&r);
			color = ((int)(255.999 * pixel_color.e[0]) << 16) | ((int)(255.999
						* pixel_color.e[1]) << 8) | (int)(255.999
					* pixel_color.e[2]);
			mlx_pixel_put(mlx, window, i, j, color);
		}
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	
	mlx = mlx_init();
	if (!mlx)
		return (1);
	argc = 0;
	argv = 0;
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
	if (!window)
		return (1);
	camera_viewpoint(mlx, window);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	return (0);
}

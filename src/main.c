/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:14:55 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/06 23:13:45 by snagulap         ###   ########.fr       */
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

// void	render(void *mlx, void *window,t_color pixel_color)
// {
// 	int		color;
// 	int		j;
// 	int		i;
// 	t_rgb	rgb;

// 	j = 0;
// 	while (j < WINDOW_HEIGHT)
// 	{
// 		i = 0;
// 		while (i < WINDOW_WIDTH)
// 		{
// 			rgb.red = (double)i / (WINDOW_WIDTH - 1);
// 			rgb.green = (double)j / (WINDOW_HEIGHT - 1);
// 			rgb.blue = 0;
// 			rgb.red = (int)(255.999 * rgb.red);
// 			rgb.green = (int)(255.999 * rgb.green);
// 			rgb.blue = (int)(255.999 * rgb.blue);
// 			color = ((int)rgb.red << 16) | ((int)rgb.green << 8) | (int)rgb.blue;
// 			mlx_pixel_put(mlx, window, i, j, color);
// 			i++;
// 		}
// 		j++;
// 	}
// }

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

t_color	ray_color(const t_ray *r)
{
	t_color	white;
	t_color	light_blue;
	t_color	result;

	t_vec3 unit_direction = unit_vector(&(r->dir)); // Calculate unit direction
	double a = 0.5 * (unit_direction.e[1] + 1.0);   // Compute blending factor
	// Define colors for the sky gradient
	white.e[0] = 1.0;
	white.e[1] = 1.0;
	white.e[2] = 1.0;
	light_blue.e[0] = 0.5;
	light_blue.e[1] = 0.7;
	light_blue.e[2] = 1.0; // Calculate final color using linear interpolation
	result.e[0] = (1.0 - a) * white.e[0] + a * light_blue.e[0];
	result.e[1] = (1.0 - a) * white.e[1] + a * light_blue.e[1];
	result.e[2] = (1.0 - a) * white.e[2] + a * light_blue.e[2];
	return (result);
}
// t_vec3	calculate_ray_direction(double u, double v)
// {
// 	double	aspect_ratio;
// 	double	viewport_width;
// 	double	viewport_height;
// 	double	focal_length;
// 	double	x;
// 	double	y;
// 	t_vec3	direction;

// 	// Define your viewport properties
// 	aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
// 	viewport_width = 2.0;
// 	viewport_height = viewport_width / aspect_ratio;
// 	focal_length = 1.0;
// 	// Calculate the coordinates on the viewport
// 	x = u * viewport_width - viewport_width / 2.0;
// 	y = -(v * viewport_height - viewport_height / 2.0);
// 	// Calculate the ray direction from the camera position to the viewport point
// 	direction = make_vec3(x, y, -focal_length);
// 	direction = vec3_normalize(direction); // Normalize the direction vector
// 	return (direction);
// }

void	render(void *mlx, void *window, int image_width, int image_height, t_color	pixel_color)
{
	int		color;
	// t_vec3	camera_position;
	// double	u;
	// double	v;
	// t_vec3	ray_direction;
	// t_ray	r;

	// camera_position = make_vec3(0.0, 0.0, 0.0);
	for (int j = 0; j < image_width; j++)
	{
		for (int i = 0; i < image_height; i++)
		{
		// 	pixel_color.e[0] = (double)i / (image_width - 1);
		// 	pixel_color.e[1] = (double)j / (image_height - 1);
		// 	pixel_color.e[2] = 0.0;
			// Set up your ray here
			// u = (double)i / (image_width - 1);
			// v = (double)j / (image_height - 1);
			// ray_direction = calculate_ray_direction(u, v);
			// // Create a ray with the camera's position and the calculated direction
			// r = make_ray(camera_position, ray_direction);
			// pixel_color = ray_color(&r);
			// Convert pixel_color to RGB values (you can use pix_color if needed)
			color = ((int)(255.999 * pixel_color.e[0]) << 16) | ((int)(255.999
						* pixel_color.e[1]) << 8) | (int)(255.999
					* pixel_color.e[2]);
			mlx_pixel_put(mlx, window, j, i, color);
		}
	}
}

void	render1(int image_width, int image_height, t_color pixel_color)
{
	int		j;
	int		i;
	t_vec3	color;

	j = 0;
	while (j < image_height)
	{
		i = 0;
		while (i < image_width)
		{
			pixel_color.e[0] = (double)i / (image_width - 1);
			pixel_color.e[1] = (double)j / (image_height - 1);
			pixel_color.e[2] = 0;
			color = pix_color(pixel_color);
			i++;
		}
		j++;
	}
}

void	camera_viewpoint(void *mlx, void *window)
{
	int		j;
	int		i;
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
	t_ray	r;
	t_color	pixel_color;

	j = 0;
	i = 0;
	aspect_ratio = 16.0 / 9.0;
	image_width = 800;
	focal_length = 1.0;
	viewport_height = 2.0;
	image_height = (int)(image_width / aspect_ratio);
	viewport_width = viewport_height * ((double)image_width / image_height);
	camera_center = make_vec3(0, 0, 0);
	viewport_u = make_vec3(viewport_width, 0, 0);
	viewport_v = make_vec3(0, -viewport_height, 0);
	pixel_delta_u = vec3_scalar_divide(viewport_u, image_width);
	pixel_delta_v = vec3_scalar_divide(viewport_v, image_height);
	viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera_center,
					vec3_scalar_multiply(viewport_u, 0.5)),
				vec3_scalar_multiply(viewport_v, 0.5)), make_vec3(focal_length,
				focal_length, 0.0));
	pixel_center = vec3_add(vec3_add(viewport_upper_left,
				vec3_scalar_multiply(pixel_delta_u, i)),
			vec3_scalar_multiply(pixel_delta_v, j));
	ray_direction = vec3_sub(pixel_center, camera_center);
	r = make_ray(camera_center, ray_direction);
	pixel_color = ray_color(&r);
	render(mlx, window, image_width, image_height, pixel_color);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
}

int	main(int argc, char **argv)
{
	t_rgb	*rgb;
	// t_vec3	v1;
	// t_vec3	v2;
	// t_vec3	sum;
	// double	dot_product;
	// t_vec3	cross_product;
	// t_vec3	normalized;
	int		image_width;
	int		image_height;
	void	*mlx;
	void	*window;

	image_width = 256;
	image_height = 256;
	rgb = malloc(sizeof(struct t_rgb *));
	if (rgb == NULL)
		return (1);
	mlx = mlx_init();
	if (!mlx)
		return (1);
	argc = 0;
	argv = 0;
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
	if (!window)
		return (1);
	// render(mlx, window);
	// v1 = make_vec3(1.0, 2.0, 3.0);
	// v2 = make_vec3(3.0, 2.0, 1.0);
	// printf("v1: %f %f %f\n", v1.e[0], v1.e[1], v1.e[2]);
	// printf("v2: %f %f %f\n", v2.e[0], v2.e[1], v2.e[2]);
	// sum = vec3_add(v1, v2);
	// printf("Sum: %f %f %f\n", sum.e[0], sum.e[1], sum.e[2]);
	// dot_product = vec3_dot(v1, v2);
	// printf("Dot Product: %f\n", dot_product);
	// cross_product = vec3_cross(v1, v2);
	// printf("Cross Product: %f %f %f\n", cross_product.e[0], cross_product.e[1],
	// 	cross_product.e[2]);
	// normalized = vec3_normalize(v1);
	// printf("Normalized v1: %f %f %f\n", normalized.e[0], normalized.e[1],
	// 	normalized.e[2]);
	camera_viewpoint(mlx, window);
	mlx_loop(mlx);
	free(rgb);
	mlx_destroy_window(mlx, window);
	return (0);
}

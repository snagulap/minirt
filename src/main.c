/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:14:55 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/09 12:43:54 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ray.h"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 1000

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

double	hit_sphere(t_vec3 center, double radius, t_ray r)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec3_sub(r.orig, center);
	printf("%f %f %f\n", oc.e[0], oc.e[1], oc.e[2]);
	a = vec3_dot(r.dir, r.dir);
	b = 2.0 * vec3_dot(oc, r.dir);
	c = vec3_dot(oc, oc) - (radius * radius);
	discriminant = (b * b) - (c);
	printf("%f\n", discriminant);
	if (discriminant < 0)
	{
		return (-1.0);
	}
	else
	{
		return ((-b - sqrt(discriminant)) / (a));
	}
}

t_color	ray_color_sphere(t_ray r)
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
	printf("%f\n", t);
	if (t > 0.001)
	{
		N = vec3_normalize(vec3_sub(ray_at(r, t), make_vec3(0, 0, -1)));
		color.e[0] = 0.5 * (N.e[0] + 1);
		color.e[1] = 0.5 * (N.e[1] + 1);
		color.e[2] = 0.5 * (N.e[2] + 1);
		return (color);
	}
	// Background color
	unit_direction = vec3_normalize(r.dir);
	a = 0.5 * (unit_direction.e[1] + 1.0);
	white_color = make_vec3(1.0, 1.0, 1.0);
	blue_color = make_vec3(0.5, 0.7, 1.0);
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

int	solveQuadratic(double a, double b, double c, double *root1, double *root2)
{
	double	discriminant;
	double	sqrtDiscriminant;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		// No real roots
		return (0);
	}
	else if (discriminant == 0)
	{
		// One real root
		*root1 = -b / (2 * a);
		return (1);
	}
	else
	{
		// Two real roots
		sqrtDiscriminant = sqrt(discriminant);
		*root1 = (-b + sqrtDiscriminant) / (2 * a);
		*root2 = (-b - sqrtDiscriminant) / (2 * a);
		return (2);
	}
}


int	hitSphere(const t_Sphere *sphere, const t_ray *ray, double *t)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	int		numRoots;

	oc = vec3_sub(ray->orig, sphere->center);
	a = vec3_dot(ray->dir, ray->dir);
	b = 2.0 * vec3_dot(oc, ray->dir);
	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	double root1, root2;
	numRoots = solveQuadratic(a, b, c, &root1, &root2);
	if (numRoots == 0)
	{
		return (0);
	}
	else if (numRoots == 1)
	{
		if (root1 > 0)
		{
			*t = root1;
			return (1);
		}
		return (0);
	}
	else
	{
		if (root1 > 0 && root2 > 0)
		{
			*t = fmin(root1, root2);
			return (1);
		}
		else if (root1 > 0)
		{
			*t = root1;
			return (1);
		}
		else if (root2 > 0)
		{
			*t = root2;
			return (1);
		}
		return (0);
	}
}

t_color	rayColor(const t_ray *ray)
{
	t_Sphere	sphere;
	double		t;
	t_vec3		normal;
	t_color		color;
	t_color		white_color;
	t_color		blue_color;
	t_color		interpolated_color;
	t_vec3		unit_direction;
	double		a;

	sphere.center.e[0] = 0;
	sphere.center.e[1] = 0;
	sphere.center.e[2] = -1;
	sphere.radius = 0.5;
	// vec3_sub(ray_at(r, t), make_vec3(0, 0, -1)));
	if (hitSphere(&sphere, ray, &t))
	{
		normal.e[0] = ray->orig.e[0] + t * ray->dir.e[0] - sphere.center.e[0];
		normal.e[1] = ray->orig.e[1] + t * ray->dir.e[1] - sphere.center.e[1];
		normal.e[2] = ray->orig.e[2] + t * ray->dir.e[2] - sphere.center.e[2];
		normal = vec3_normalize(normal);
		normal = vec3_scalar_add(normal, 1.0);
		color = vec3_scalar_multiply(normal, 0.5);
		return (color);
	}
	// Background color
	unit_direction = vec3_normalize(ray->dir);
	a = 0.5 * (unit_direction.e[1] + 1.0);
	white_color = make_vec3(1.0, 1.0, 1.0);
	blue_color = make_vec3(0.5, 0.7, 1.0);
	interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a
		* blue_color.e[0];
	interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a
		* blue_color.e[1];
	interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a
		* blue_color.e[2];
	return (interpolated_color);
}

void	view_point_sphere(void *mlx, void *window)
{
	int		width;
	int		height;
	t_vec3	lowerLeftCorner;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	camera_view;
	double	u;
	double	v;
	t_ray	ray;
	t_color	color;
	int		img_col;

	width = 1600;
	height = 1000;
	lowerLeftCorner = make_vec3(-2.0, -1.0, -1.0);
	horizontal = make_vec3(4.0, 0.0, 0.0);
	vertical = make_vec3(0.0, 2.0, 0.0);
	camera_view = make_vec3(0,0,0);
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			u = (double)i / (double)width;
			v = (double)j / (double)height;
			ray.orig = camera_view;
			ray.dir.e[0] = lowerLeftCorner.e[0] + u * horizontal.e[0] + v
				* vertical.e[0];
			ray.dir.e[1] = lowerLeftCorner.e[1] + u * horizontal.e[1] + v
				* vertical.e[1];
			ray.dir.e[2] = lowerLeftCorner.e[2] + u * horizontal.e[2] + v
				* vertical.e[2];
			color = rayColor(&ray);
			img_col = ((int)(255.999 * color.e[0]) << 16) | ((int)(255.999
						* color.e[1]) << 8) | (int)(255.999 * color.e[2]);
			mlx_pixel_put(mlx, window, i, j, img_col);
		}
	}
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
	view_point_sphere(mlx, window);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	return (0);
}

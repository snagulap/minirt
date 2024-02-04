/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:14:55 by snagulap          #+#    #+#             */
/*   Updated: 2024/01/13 17:27:49 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "ray.h"

// t_vec3	pix_color(t_vec3 pixel_color)
// {
// 	t_vec3	v2;

// 	v2.e[0] = (int)(255.999 * pixel_color.e[0]);
// 	v2.e[1] = (int)(255.999 * pixel_color.e[1]);
// 	v2.e[2] = (int)(255.999 * pixel_color.e[2]);
// 	return (v2);
// }

// double	hit_sphere(t_vec3 center, double radius, t_ray r)
// {
// 	t_vec3	oc;
// 	double	a;
// 	double	b;
// 	double	c;
// 	double	discriminant;

// 	oc = vec3_sub(r.orig, center);
// 	printf("%f %f %f\n", oc.e[0], oc.e[1], oc.e[2]);
// 	a = vec3_dot(r.dir, r.dir);
// 	b = 2.0 * vec3_dot(oc, r.dir);
// 	c = vec3_dot(oc, oc) - (radius * radius);
// 	discriminant = (b * b) - (c);
// 	printf("%f\n", discriminant);
// 	if (discriminant < 0)
// 		return (-1.0);
// 	else
// 		return ((-b - sqrt(discriminant)) / (a));
// }

// t_color	ray_color_sphere(t_ray r)
// {
// 	double	t;
// 	t_vec3	N;
// 	t_color	color;
// 	t_vec3	unit_direction;
// 	double	a;
// 	t_color	white_color;
// 	t_color	blue_color;
// 	t_color	interpolated_color;

// 	t = hit_sphere(make_vec3(0, 0, -1), 0.5, r);
// 	if (t > 0.001)
// 	{
// 		N = vec3_normalize(vec3_sub(ray_at(r, t), make_vec3(0, 0, -1)));
// 		color.e[0] = 0.5 * (N.e[0] + 1);
// 		color.e[1] = 0.5 * (N.e[1] + 1);
// 		color.e[2] = 0.5 * (N.e[2] + 1);
// 		return (color);
// 	}
// 	// Background color
// 	unit_direction = vec3_normalize(r.dir);
// 	a = 0.5 * (unit_direction.e[1] + 1.0);
// 	white_color = make_vec3(1.0, 1.0, 1.0);
// 	blue_color = make_vec3(0.5, 0.7, 1.0);
// 	interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a
// 		* blue_color.e[0];
// 	interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a
// 		* blue_color.e[1];
// 	interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a
// 		* blue_color.e[2];
// 	return (interpolated_color);
// }

// void	render(void *mlx, void *window, int image_width, int image_height,
// 		t_color pixel_color)
// {
// 	int	color;

// 	for (int j = 0; j < image_width; j++)
// 	{
// 		for (int i = 0; i < image_height; i++)
// 		{
// 			color = ((int)(255.999 * pixel_color.e[0]) << 16) | ((int)(255.999
// 						* pixel_color.e[1]) << 8) | (int)(255.999
// 					* pixel_color.e[2]);
// 			mlx_pixel_put(mlx, window, j, i, color);
// 		}
// 	}
// }
/*
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
	t_ray	r;
	t_color	pixel_color;

	j = 0;
	i = 0;
	image_width = WINDOW_WIDTH;
	image_height = WINDOW_HEIGHT;
	focal_length = 1.0;
	viewport_height = 1.0;
	aspect_ratio = image_width / image_height;
	viewport_width = ((double)image_width / image_height);
	camera_center = make_vec3(0, 0, 0);
	viewport_u = make_vec3(viewport_width, 0, 0);
	viewport_v = make_vec3(0, -viewport_height, 0);
	pixel_delta_u = vec3_scalar_divide(viewport_u, image_width);
	pixel_delta_v = vec3_scalar_divide(viewport_v, image_height);
	viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera_center,
					vec3_scalar_multiply(viewport_u, 0.5)),
				vec3_scalar_multiply(viewport_v, 0.5)), make_vec3(focal_length,
				focal_length, 0.0));
	for (j = 0; j < image_height; j++)
	{
		for (i = 0; i < image_width; i++)
		{
			pixel_center = vec3_add(vec3_add(viewport_upper_left,
						vec3_scalar_multiply(pixel_delta_u, i)),
					vec3_scalar_multiply(pixel_delta_v, j));
			ray_direction = vec3_sub(pixel_center, camera_center);
			r = make_ray(camera_center, ray_direction);
			pixel_color = ray_color_sphere(r);
			color = ((int)(255.999 * pixel_color.e[0]) << 16) | ((int)(255.999
						* pixel_color.e[1]) << 8) | (int)(255.999
					* pixel_color.e[2]);
			mlx_pixel_put(mlx, window, i, j, color);
		}
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
}*/

t_vec3 view_point_sphere(int i, int j)
{
	double	width;
	double	height;
	// t_vec3	lowerLeftCorner;
	// t_vec3	horizontal;
	// t_vec3	vertical;
	// t_vec3	camera_view;
	// double	u;
	// double	v;
	// t_ray	ray;
	// t_color	color;
	// int		img_col;

	width = (double)WINDOW_WIDTH;
	height = (double)WINDOW_HEIGHT;
	double aspect_ratio = width / height;
	double fov = 70;
	double t = fov * M_PI / 180.0;
	float camera_width = tan(t / 2);
	float camera_height = camera_width / aspect_ratio;
	float u = (float) i / (width - 1);
	float v = (float) j / (height - 1);
	float x = 2.0 * camera_width * u - camera_width;
	float y = 2.0 * camera_height * v - camera_height;

	t_vec3 pixel_position = (t_vec3) {x, y, -1};
	return (pixel_position);
}
// void reder(void *mlx, void *window)
// {
// 	// t_vec3 pixel_poisition;
// 	t_color color;
// 	t_vec3 camera_position = {-50.0, 0, 20};
// 	// t_vec3 camera_orientation = {0.0, 0.0, 1.0};
// 	int	width;
// 	int	height;
// 	width = (int)WINDOW_WIDTH;
// 	height = (int)WINDOW_HEIGHT;

// 	for (int j = height - 1; j >= 0; j--)
// 	{
// 		for (int i = 0; i < width; i++)
// 		{
// 			t_vec3 pixel_position = view_point_sphere(i, j);
// 			// t_vec3 camera_direction = camera_orientation;
			
// 			// u = (double)i / (double)width;
// 			// v = (double)j / (double)height;
// 			// ray.orig = camera_view;
// 			// ray.dir.e[0] = lowerLeftCorner.e[0] + u * horizontal.e[0] + v
// 			// 	* vertical.e[0];
// 			// ray.dir.e[1] = lowerLeftCorner.e[1] + u * horizontal.e[1] + v
// 			// 	* vertical.e[1];
// 			// ray.dir.e[2] = lowerLeftCorner.e[2] + u * horizontal.e[2] + v
// 			// 	* vertical.e[2];
// 			t_ray ray = make_ray(camera_position, pixel_position);
// 			color = rayColor(&ray);
// 			int img_col = ((int)(255.999 * color.e[0]) << 16) | ((int)(255.999
// 						* color.e[1]) << 8) | (int)(255.999 * color.e[2]);
// 			mlx_pixel_put(mlx, window, i, j, img_col);
// 		}
// 	}
// }
// void	view_point_sphere(void *mlx, void *window)
// {
// 	int		width;
// 	int		height;
// 	t_vec3	lowerLeftCorner;
// 	t_vec3	horizontal;
// 	t_vec3	vertical;
// 	t_vec3	camera_view;
// 	double	u;
// 	double	v;
// 	t_ray	ray;
// 	t_color	color;
// 	int		img_col;

// 	width = WINDOW_WIDTH;
// 	height = WINDOW_HEIGHT;
// 	lowerLeftCorner = make_vec3(-2.0, -1.0, -1.0);
// 	horizontal = make_vec3(4.0, 0.0, 0.0);
// 	vertical = make_vec3(0.0, 2.0, 0.0);
// 	camera_view = make_vec3(-50.0, 0, 20.0);
// 	for (int j = height - 1; j >= 0; j--)
// 	{
// 		for (int i = 0; i < width; i++)
// 		{
// 			u = (double)i / (double)width;
// 			v = (double)j / (double)height;
// 			ray.orig = camera_view;
// 			ray.dir.e[0] = lowerLeftCorner.e[0] + u * horizontal.e[0] + v
// 				* vertical.e[0];
// 			ray.dir.e[1] = lowerLeftCorner.e[1] + u * horizontal.e[1] + v
// 				* vertical.e[1];
// 			ray.dir.e[2] = lowerLeftCorner.e[2] + u * horizontal.e[2] + v
// 				* vertical.e[2];
// 			color = rayColor(&ray);
// 			img_col = ((int)(255.999 * color.e[0]) << 16) | ((int)(255.999
// 						* color.e[1]) << 8) | (int)(255.999 * color.e[2]);
// 			mlx_pixel_put(mlx, window, i, j, img_col);
// 		}
// 	}
// }
/*
void	view_point(void *mlx, void *window, t_camera camera)
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
	double	focal_length;
	double	aspect_ratio;
	int		image_width;
	int		image_height;
	// double	viewport_height;
	// double	viewport_width;
	// t_vec3	viewport_u;
	// t_vec3	viewport_v;
	// t_vec3	pixel_delta_u;
	// t_vec3	pixel_delta_v;
	// t_vec3 viewport_upper_left;
	// // t_color	color;
	// t_vec3	pixel00_loc;
	camera.ray.orig = make_vec3(0, 0, 0);
	focal_length = camera.FOV * M_PI / 180.0;
	image_height = tan(focal_length / 2);
	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	// Calculate the image height, and ensure that it's at least 1.
	image_width = (int)(image_height * aspect_ratio);
	lowerLeftCorner = make_vec3(-2.0, -1.0, -1.0);
	horizontal = make_vec3(4.0, 0.0, 0.0);
	vertical = make_vec3(0.0, 2.0, 0.0);
	camera_view = make_vec3(-50.0,0,20.0);
	for (int j = height - 1; j >= 0; j--)
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
}*/

// void	image_Setup1(void *mlx, void *window)
// {
// 	t_vec3		pixel_center;
// 	t_ray		ray;
// 	t_color		color;
// 	int			img_col;
// 	t_vec3		ray_direction;
// 	int 		i;
// 	int			j;
// 	t_camera camera;
// 	double height;
// 	t_vec3	viewport_u;
// 	t_vec3	viewport_v;
	
// 	camera.ray.orig = make_vec3(0, 0, 0);
// 	camera.image_width = WINDOW_WIDTH;
// 	camera.aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
// 	// Calculate the image height, and ensure that it's at least 1.
// 	camera.image_height = (int)(camera.image_width / camera.aspect_ratio);
// 	// camera.image_height = (camera.image_height < 1) ? 1 : camera.image_height;
// 	// Camera
// 	camera.focal_length = vec3_length(camera.ray.orig);
// 	camera.theta = camera.fov * M_PI / 180.0;
// 	height = tan(camera.theta / 2) / camera.aspect_ratio;
// 	camera.viewport_height = height * camera.focal_length;
// 	camera.viewport_width = camera.viewport_height * ((double)camera.image_width
// 			/ camera.image_height);
// 	// Calculate the vectors across the horizontal and down the vertical viewport edges.
// 	viewport_u = make_vec3(camera.viewport_width, 0, 0);
// 	viewport_v = make_vec3(0, -camera.viewport_height, 0);
// 	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
// 	camera.pixel_delta_u = vec3_scalar_divide(viewport_u, camera.image_width);
// 	camera.pixel_delta_v = vec3_scalar_divide(viewport_v, camera.image_height);
// 	// Calculate the location of the upper-left pixel.
// 	camera.viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera.ray.orig, make_vec3(0,
// 						0, camera.focal_length)), vec3_scalar_divide(viewport_u, 2)),
// 			vec3_scalar_divide(viewport_v, 2));
// 	camera.pixel00_loc = vec3_add(camera.viewport_upper_left, vec3_scalar_multiply(vec3_add(camera.pixel_delta_u, camera.pixel_delta_v), 0.5));
// 	for (j = 0; j < camera.image_height; j++)
// 	{
// 		for (i = 0; i < camera.image_width; i++)
// 		{
// 			pixel_center = vec3_add(camera.pixel00_loc,
// 					vec3_add(vec3_scalar_multiply(camera.pixel_delta_u, i),
// 						vec3_scalar_multiply(camera.pixel_delta_v, j)));
// 			ray_direction = vec3_add(pixel_center, camera.ray.orig);
// 			ray = make_ray(camera.ray.orig, ray_direction);
// 			color = rayColor(&ray);
// 			img_col = ((int)(255.999 * color.e[0]) << 16) | ((int)(255.999
// 						* color.e[1]) << 8) | (int)(255.999 * color.e[2]);
// 			mlx_pixel_put(mlx, window, i, j, img_col);
// 		}
// 	}
// }

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	// t_camera	cam;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	argc = 0;
	argv = 0;
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
	if (!window)
		return (1);
	//    t_sphere spheres[2];
    // spheres[0] = (t_sphere){make_vec3(0, 0, 20.6), 12.6, make_color_rgb(0.0, 0.0, 255)};
    // spheres[1] = (t_sphere){make_vec3(5, 0, 25.0), 5.0, make_color_rgb(255.0, 0.0, 0.0)};

    // // Example: Create an array of planes
    // t_plane planes[1];
    // planes[0] = (t_plane){make_vec3(0, -10.0, 0), make_vec3(0, 1.0, 0)};

    // // Example: Create an array of lights
    // t_light lights[1];
    // lights[0] = (t_light){make_vec3(-40.0, 50.0, 0.0), 0.6, make_color(10, 0, 255)};

    // Example: Create your camera
    t_camera camera;
    // ... (initialize your camera)

    // Render the scene
    camera_viewpoint(mlx, window, &camera);
	// camera_viewpoint(mlx, window);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	return (0);
}

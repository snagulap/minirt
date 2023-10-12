/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:37:28 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/12 19:40:38 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	camera_setup(t_camera camera)
// {
// 	double	aspect_ratio;
// 	int		image_width;
// 	int		image_height;
// 	double	viewport_height;
// 	double	viewport_width;
// 	t_vec3	viewport_u;
// 	t_vec3	viewport_v;
// 	t_vec3	pixel_delta_u;
// 	t_vec3	pixel_delta_v;
// 	t_vec3 viewport_upper_left;
// 	// t_color	color;
// 	t_vec3	pixel00_loc;
// 	camera.ray.orig = make_vec3(0, 0, 0);
// 	image_width = WINDOW_WIDTH;
// 	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
// 	// Calculate the image height, and ensure that it's at least 1.
// 	image_height = (int)(image_width / aspect_ratio);
// 	// Viewport widths less than one are ok since they are real-valued.
// 	viewport_height = 2.0;
// 	viewport_width = viewport_height * aspect_ratio;
// 	viewport_u = make_vec3(viewport_width, 0, 0);
// 	viewport_v = make_vec3(0, -viewport_height, 0);
// 	pixel_delta_u = vec3_scalar_divide(viewport_u, image_width);
// 	pixel_delta_v = vec3_scalar_divide(viewport_v, image_height);
// 	viewport_upper_left = t_vec3_sub(camera.ray, t_vec3_sub(pixel00,
				// t_vec3_div(viewport_u, 2.0), t_vec3_div(viewport_v, 2.0)));

//     pixel00_loc = t_vec3_add(viewport_upper_left,
		// t_vec3_mul(t_vec3_add(pixel_delta_u, pixel_delta_v), 0.5));

// }
/*
void	image_Setup(void)
{
	double	aspect_ratio;
	int		image_width;
	int		image_height;
	double	viewport_height;
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
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_loc;

	camera_center = make_vec3(0, 0, 0);
	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	// Calculate the image height, and ensure that it's at least 1.
	image_height = (int)(image_width / aspect_ratio);
	// Viewport widths less than one are ok since they are real-valued.
	viewport_height = 2.0;
	viewport_width = viewport_height * aspect_ratio;
	viewport_u = make_vec3(viewport_width, 0, 0);
	viewport_v = make_vec3(0, -viewport_height, 0);
	pixel_delta_u = vec3_scalar_divide(viewport_u, image_width);
	pixel_delta_v = vec3_scalar_divide(viewport_v, image_height);
	viewport_upper_left = camera_center - make_vec3(0, 0, focal_length)
		- vec3_scalar_divide(viewport_u, 2.0) - vec3_scalar_divide(viewport_v,
			2.0);
	pixel00_loc = viewport_upper_left + (0.5 * vec3_add(pixel_delta_u,
				pixel_delta_v));
	for (j = 0; j < image_height; j++)
	{
		for (i = 0; i < image_width; i++)
		{
			pixel_center = pixel00_loc + vec3_scalar_multiply(pixel_delta_u, i)
				+ vec3_scalar_multiply(pixel_delta_v, j);
			ray_direction = vec3_sub(pixel_center, camera_center);
			r = make_ray(camera_center, ray_direction);
		}
	}
}*/
t_camera	camera_viewpoint(void)
{
	t_camera camera;
	double height;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	
	camera.ray.orig = make_vec3(0, 0, 0);
	camera.image_width = WINDOW_WIDTH;
	camera.aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	// Calculate the image height, and ensure that it's at least 1.
	camera.image_height = (int)(camera.image_width / camera.aspect_ratio);
	// camera.image_height = (camera.image_height < 1) ? 1 : camera.image_height;
	// Camera
	camera.focal_length = vec3_length(camera.ray.orig);
	camera.theta = camera.fov * M_PI / 180.0;
	height = tan(camera.theta / 2) / camera.aspect_ratio;
	camera.viewport_height = height * camera.focal_length;
	camera.viewport_width = camera.viewport_height * ((double)camera.image_width
			/ camera.image_height);
	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	viewport_u = make_vec3(camera.viewport_width, 0, 0);
	viewport_v = make_vec3(0, -camera.viewport_height, 0);
	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	camera.pixel_delta_u = vec3_scalar_divide(viewport_u, camera.image_width);
	camera.pixel_delta_v = vec3_scalar_divide(viewport_v, camera.image_height);
	// Calculate the location of the upper-left pixel.
	camera.viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera.ray.orig, make_vec3(0,
						0, camera.focal_length)), vec3_scalar_divide(viewport_u, 2)),
			vec3_scalar_divide(viewport_v, 2));
	camera.pixel00_loc = vec3_add(camera.viewport_upper_left, vec3_scalar_multiply(vec3_add(camera.pixel_delta_u, camera.pixel_delta_v), 0.5));
	return (camera);
}
// 	while (j < image_height)
// 	{
// 		// fprintf(stderr, "\rScanlines remaining: %d ", image_height - j);
// 		while (i < image_width)
// 		{
// 			t_vec3 pixel_center = vec3_add(pixel00_loc,
// 					vec3_add(vec3_mul(make_vec3(i, i, i), pixel_delta_u),
// 						vec3_mul(make_vec3(j, j, j), pixel_delta_v)));
// 			t_vec3 ray_direction = vec3_sub(pixel_center, camera_center);
// 			t_ray r = make_ray(camera_center, ray_direction);

// 			t_color pixel_color = ray_color(&r);
// 			write_color(stdout, pixel_color);
// 			i++;
// 		}
// 		j++;
// 	}
// }

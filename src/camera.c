/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:37:28 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/06 18:31:00 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	ray_color(const ray *r)
{
	return (make_color(0, 0, 0)); // Replace with actual ray tracing logic
}
void	image_Setup(void)
{
	double	aspect_ratio;
	int		image_width;
	int		image_height;
	double	viewport_height;
	double	viewport_width;

	aspect_ratio = 16.0 / 9.0;
	image_width = 400;
	// Calculate the image height, and ensure that it's at least 1.
	image_height = (int)(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;
	// Viewport widths less than one are ok since they are real-valued.
	viewport_height = 2.0;
	viewport_width = viewport_height * ((double)image_width / image_height);
}

// void	camera_viewpoint(void)
// {
// 	double aspect_ratio;
// 	int image_width;
// 	int image_height;
// 	double focal_length;
// 	double viewport_height;
// 	double viewport_width;
// 	int j;
// 	int i;

// 	aspect_ratio = 16.0 / 9.0;
// 	image_width = 400;
// 	// Calculate the image height and ensure it's at least 1
// 	image_height = (int)(image_width / aspect_ratio);
// 	image_height = (image_height < 1) ? 1 : image_height;

// 	// Camera

// 	focal_length = 1.0;
// 	viewport_height = 2.0;
// 	viewport_width = viewport_height * ((double)image_width / image_height);

// 	t_vec3 camera_center = make_vec3(0, 0, 0);

// 	// Calculate the vectors across the horizontal and down the vertical viewport edges.
// 	t_vec3 viewport_u = make_vec3(viewport_width, 0, 0);
// 	t_vec3 viewport_v = make_vec3(0, -viewport_height, 0);

// 	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
// 	t_vec3 pixel_delta_u = vec3_div(viewport_u, image_width);
// 	t_vec3 pixel_delta_v = vec3_div(viewport_v, image_height);

// 	// Calculate the location of the upper-left pixel.
// 	t_vec3 viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera_center,
// 					make_vec3(0, 0, focal_length)), vec3_div(viewport_u, 2)),
// 			vec3_div(viewport_v, 2));
// 	t_vec3 pixel00_loc = vec3_add(viewport_upper_left, vec3_mul(make_vec3(0.5,
// 					0.5, 0.5), vec3_add(pixel_delta_u, pixel_delta_v)));

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

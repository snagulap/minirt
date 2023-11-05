/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:48:39 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/26 22:49:23 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

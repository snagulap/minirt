/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:25:36 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/14 19:22:34 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_vec3	pixel00_loc;
	t_ray	r;
	t_color	pixel_color;
	t_vec3	cal;
	t_vec3	cal1;
	t_vec3	cal2;
	int		width;
	int		height;
	t_vec3	camera_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_loc;
	t_ray	r;
	t_color	pixel_color;
	int		color;
	t_vec3	ray_direction;
	int		width;
	int		height;
	t_vec3	camera_center;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_loc;
	t_ray	r;
	t_color	pixel_color;
	int		color;

	j = 0;
	i = 0;
	aspect_ratio = 16.0 / 9.0;
	image_width = 800;
	focal_length = 1.0;
	viewport_height = 2.0;
	image_height = 400; //(int)(image_width / aspect_ratio);
	printf("%d\n", image_height);
	if (image_height < 1)
		image_height = 1;
	viewport_width = viewport_height * ((double)image_width / image_height);
	printf("%f %f\n", viewport_height, viewport_width);
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
			pixel_color = rayColor(&r);
			color = ((int)(255.999 * pixel_color.e[0]) << 16) | ((int)(255.999
						* pixel_color.e[1]) << 8) | (int)(255.999
					* pixel_color.e[2]);
			mlx_pixel_put(mlx, window, i, j, color);
		}
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
}*/

// Now you have the basis vectors u, v, and w, along with pixel_delta_u, pixel_delta_v, and pixel00_loc
// You can use these vectors to calculate rays from the camera to each pixel in the image.

    // // Calculate the camera's coordinate axes
    // t_vec3 w = vec3_sub(camera.ray.orig, look_at);
	// // { camera_center.x - look_at.x, camera_center.y - look_at.y, camera_center.z - look_at.z });
    // t_vec3 u = vec3_normalize(vec3_cross(up, w));
	// // t_vec3 v = vec3_cross(w, u);

    // // Calculate the viewport size based on the field of view
    // double viewport_height_half = tan(0.5 * fov_radians) * focal_length;
    // double viewport_width_half = aspect_ratio * viewport_height_half;

    // // Calculate the vectors across the horizontal and down the vertical viewport edges
	// t_vec3 viewport_u = { 2.0 * viewport_width_half, 0, 0 };
    // t_vec3 viewport_v = { 0, 2.0 * viewport_height_half, 0 };

    // // Calculate the horizontal and vertical delta vectors from pixel to pixel
	// t_vec3 pixel_delta_u = { viewport_u.e[0] / image_width, viewport_u.e[1] / image_width, viewport_u.e[2] / image_width };
    // t_vec3 pixel_delta_v = { viewport_v.e[0] / image_height, viewport_v.e[1] / image_height, viewport_v.e[2] / image_height };

    // // Calculate the location of the upper left pixel
    // t_vec3 viewport_upper_left = {
    //     camera.ray.orig.e[0] - focal_length * w.e[0] - 0.5 * viewport_u.e[0] + 0.5 * viewport_v.e[0],
    //     camera.ray.orig.e[1] - focal_length * w.e[1] - 0.5 * viewport_u.e[1] + 0.5 * viewport_v.e[1],
    //     camera.ray.orig.e[2] - focal_length * w.e[2] - 0.5 * viewport_u.e[2] + 0.5 * viewport_v.e[2]
    // };
    // t_vec3 pixel00_loc = {
    //     viewport_upper_left.e[0] + 0.5 * pixel_delta_u.e[0] + 0.5 * pixel_delta_v.e[0],
    //     viewport_upper_left.e[1] + 0.5 * pixel_delta_u.e[1] + 0.5 * pixel_delta_v.e[1],
    //     viewport_upper_left.e[2] + 0.5 * pixel_delta_u.e[2] + 0.5 * pixel_delta_v.e[2]
    // };
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:37:28 by snagulap          #+#    #+#             */
/*   Updated: 2023/11/02 17:13:23 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	camera_viewpoint(void *mlx, void *window)
{
	t_camera	camera;
	int			img_col;
	t_ray		ray;
	double		fov_radians;
	double		focal_length;
	double		aspect_ratio;
	double		image_width;
	int			image_height;
	double		viewport_height_half;
	double		viewport_width_half;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
	t_vec3		viewport_upper_left;
	t_vec3		pixel00_loc;
	t_vec3		pixel_center;
	t_vec3		ray_direction;
	t_color		color;
	t_sphere sphere;
    sphere.center = make_vec3(0.0, 0.0, 20.6);
    sphere.radius = 12.6;
    sphere.rgb_colors = make_color_rgb(10, 0, 255);

    // Define a ray from the camera
    // t_ray ray;
    ray.orig = make_vec3(-50.0, 0, 20);
    ray.dir = make_vec3(0.0, 0.0, 1.0);
	// double height;
	// t_vec3	viewport_u;
	// t_vec3	viewport_v;
	int i, j;
	camera.fov = 70.0; // Set FOV to 180 degrees
	fov_radians = camera.fov * M_PI / 180.0;
	focal_length = 1.0;
	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	image_width = (double)WINDOW_WIDTH;
	image_height = (int)(image_width / aspect_ratio);
	if (image_height < 1)
		image_height = 1;
	// Camera Position and Orientation
	camera.ray.orig = (t_vec3){-50.0, 0, 20};
	t_vec3 look_at = (t_vec3){0.0, 0.0, 1.0}; //Assuming it's looking at (0,0,1)
	t_vec3 up = (t_vec3){0.0, 1.0, 0.0};      // Up vector
	// Calculate the camera's coordinate axes
	t_vec3 w = vec3_normalize(vec3_sub(camera.ray.orig, look_at));
		// Forward vector (camera -> look_at)
	t_vec3 u = vec3_normalize(vec3_cross(up, w));                 
		// Right vector (perpendicular to up and forward)
	t_vec3 v = vec3_cross(w, u);                                  
		// Up vector (perpendicular to forward and right)
	// Calculate the viewport size based on the field of view
	viewport_height_half = tan(0.5 * fov_radians) * focal_length;
	viewport_width_half = aspect_ratio * viewport_height_half;
	// Calculate the vectors across the horizontal and down the vertical viewport edges
	viewport_u = vec3_scalar_multiply(u, 2.0 * viewport_width_half);
	viewport_v = vec3_scalar_multiply(v, 2.0 * viewport_height_half);
	// Calculate the horizontal and vertical delta vectors from pixel to pixel
	pixel_delta_u = vec3_scalar_multiply(viewport_u, 1.0 / image_width);
	pixel_delta_v = vec3_scalar_multiply(viewport_u, 1.0 / image_height);
	// Calculate the location of the upper left pixel
	viewport_upper_left = vec3_sub(vec3_sub(camera.ray.orig,
				vec3_scalar_multiply(w, focal_length)),
			vec3_scalar_multiply(vec3_add(viewport_u, viewport_v), 0.5));
	pixel00_loc = vec3_add(viewport_upper_left,
			vec3_scalar_multiply(vec3_add(pixel_delta_u, pixel_delta_v), 0.5));
	for (j = 0; j < image_height; j++)
	{
		for (i = 0; i < image_width; i++)
		{
			pixel_center = vec3_add(pixel00_loc,
					vec3_add(vec3_scalar_multiply(pixel_delta_u, i),
						vec3_scalar_multiply(pixel_delta_v, j)));
			ray_direction = vec3_sub(pixel_center, camera.ray.orig);
			ray = make_ray(camera.ray.orig, ray_direction);
			color = rayColor(&ray, &sphere);//rayColor(&ray);
			img_col = ((int)(255.999 * color.red) << 16) | ((int)(255.999
						* color.green) << 8) | (int)(255.999 * color.blue);
			mlx_pixel_put(mlx, window, i, j, img_col);
		}
	}
}

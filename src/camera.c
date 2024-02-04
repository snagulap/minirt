/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:37:28 by snagulap          #+#    #+#             */
/*   Updated: 2024/02/04 15:22:14 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// int isShadowed(t_ray shadow_ray, t_sphere *spheres, int sphere_count, t_plane *planes, int plane_count)
// {

// 	planes = NULL;
// 	plane_count = 0;
//     // Iterate through spheres to check for intersection
//     for (int s = 0; s < sphere_count; s++)
//     {
//         double t;
//         if (hitSphere(&spheres[s], &shadow_ray, &t, NULL))
//         {
//             return 1; // Shadowed
//         }
//     }

//     // Iterate through planes to check for intersection
//     // for (int p = 0; p < plane_count; p++)
//     // {
//     //     double t;
//     //     if (hitPlane(&planes[p], &shadow_ray, &t, NULL))
//     //     {
//     //         return 1; // Shadowed
//     //     }
//     // }

//     return 0; // Not shadowed
// }


void	camera_viewpoint(void *mlx, void *window, t_camera *camera)
{
	int			img_col;
	t_ray		ray;
	double		fov_radians;
	double		focal_length;
	double		aspect_ratio;
	int		image_width;
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
	t_vec3		color;
	t_obj	object;
	// t_plane plane;
    object.cor = make_vec3(0.0, 0.0, 20.0);
    object.rad = 12.6;
    object.rgb = make_color(10, 0, 255);
    int i, j;
	camera->fov = 70.0; // Set FOV to 180 degrees
	fov_radians = camera->fov * M_PI / 180.0;
	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	image_width = (int)WINDOW_WIDTH;
	image_height = (int)(image_width / aspect_ratio);
	// if (image_height < 1)
	// 	image_height = 1;
	// Camera Position and Orientation
	camera->ray.orig = (t_vec3){-50.0, 0.0, 20.0};
	t_vec3 look_at = (t_vec3){0.0, 0.0, 1.0}; //Assuming it's looking at (0,0,1)
	t_vec3 up = (t_vec3){0.0, 1.0, 0.0};      // Up vector
	focal_length = 1;
	// Calculate the camera's coordinate axes
	t_vec3 w = vec3_normalize(vec3_sub(camera->ray.orig, look_at));
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
	pixel_delta_v = vec3_scalar_multiply(viewport_v, 1.0 / image_height);
	// Calculate the location of the upper left pixel
	viewport_upper_left = vec3_sub(vec3_sub(camera->ray.orig,
				vec3_scalar_multiply(w, focal_length)),
			vec3_scalar_multiply(vec3_add(viewport_u, viewport_v), 0.5));
	pixel00_loc = vec3_add(viewport_upper_left,
			vec3_scalar_multiply(vec3_add(pixel_delta_u, pixel_delta_v), 0.5));
	for (j = 0; j < image_height; j++)
	{
		for (i = 0; i < image_width; i++)
		{
	// printf("delta_u %.2f, %.2f, %.2f\n", pixel_delta_u.e[0], pixel_delta_u.e[1], pixel_delta_u.e[2]);
	// printf("delta_v %.2f, %.2f, %.2f\n", pixel_delta_v.e[0], pixel_delta_v.e[1], pixel_delta_v.e[2]);
			pixel_center = vec3_add(pixel00_loc,
					vec3_add(vec3_scalar_multiply(pixel_delta_u, i),
						vec3_scalar_multiply(pixel_delta_v, j)));
			ray_direction = vec3_sub(pixel_center, camera->ray.orig);
			ray = make_ray(camera->ray.orig, ray_direction);
			color = rayColor(&ray, &object);//rayColor(&ray);
			img_col = ((int)(255.999 * color.e[0]) << 16) | ((int)(255.999
						* color.e[1]) << 8) | (int)(255.999 * color.e[2]);

			// ray_direction = vec3_sub(pixel_center, camera.ray.orig);
			// ray = make_ray(camera.ray.orig, ray_direction);
			// color = rayColor(&ray, &sphere);//rayColor(&ray);
			// img_col = ((int)(255.999 * color.red) << 16) | ((int)(255.999
			// 			* color.green) << 8) | (int)(255.999 * color.blue);

			mlx_pixel_put(mlx, window, i, j, img_col);
		}
	}
}

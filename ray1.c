/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:25:36 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/07 13:26:13 by snagulap         ###   ########.fr       */
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

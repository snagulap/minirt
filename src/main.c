/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:14:55 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/06 13:29:31 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

#define RED_PIXEL 0xFF0000

typedef t_vec3	t_color;

t_vec3	pix_color(t_color pixel_color)
{
	t_vec3	v2;

	v2.e[0] = (int)(255.999 * pixel_color.e[0]);
	v2.e[1] = (int)(255.999 * pixel_color.e[1]);
	v2.e[2] = (int)(255.999 * pixel_color.e[2]);
	return (v2);
}

void	render(void *mlx, void *window)
{
	int		color;
	int		j;
	int		i;
	t_rgb	rgb;

	j = 0;
	while (j < WINDOW_HEIGHT)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			rgb.red = (double)i / (WINDOW_WIDTH - 1);
			rgb.green = (double)j / (WINDOW_HEIGHT - 1);
			rgb.blue = 0;
			rgb.red = (int)(255.999 * rgb.red);
			rgb.green = (int)(255.999 * rgb.green);
			rgb.blue = (int)(255.999 * rgb.blue);
			color = ((int)rgb.red << 16) | ((int)rgb.green << 8) | (int)rgb.blue;
			mlx_pixel_put(mlx, window, i, j, color);
			i++;
		}
		j++;
	}
}

void	render1(int image_width, int image_height)
{
	int		j;
	int		i;
	t_color pixel_color;
	t_vec3	color;

	j = 0;
	while (j < image_height)
	{
		fprintf(stderr, "\rScanlines remaining: %d ", image_height - j);
		i = 0;
		while (i < image_width)
		{
			pixel_color.e[0] = (double)i / (image_width - 1);
			pixel_color.e[1] = (double)j / (image_height - 1);
			pixel_color.e[2] = 0;
			color = pix_color(pixel_color);
			printf("%d %d %d\n", (int)color.e[0], (int)color.e[1],
				(int)color.e[2]);
			i++;
		}
		j++;
	}
}

// void render1(void *mlx, void *window)
// {
// 	for (int j = 0; j < image_height; ++j) {
//         fprintf(stderr, "\rScanlines remaining: %d ", image_height - j);
//         for (int i = 0; i < image_width; ++i) {
//             t_color pixel_color = {double(i) / (image_width - 1), double(j)
	// (image_height - 1), 0};
//             write_color(stdout, pixel_color);
//         }
//     }
// }

int	main(int argc, char **argv)
{
	t_rgb	*rgb;
	void	*mlx;
	void	*window;
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	sum;
	double	dot_product;
	t_vec3	cross_product;
	t_vec3	normalized;
	int		image_width;
	int		image_height;

	image_width = 256;
	image_height = 256;
	// t_minirt	*rt;
	// int			color;
	// t_color pixel_color = {0.5, 0.7, 1.0};
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
	// color = (rgb->blue << 16) | (rgb->green << 8) | rgb->red;
	render(mlx, window);
	render1(image_width, image_height);
	v1 = make_vec3(1.0, 2.0, 3.0);
	v2 = make_vec3(3.0, 2.0, 1.0);
	// printf("v1: %f %f %f\n", v1.e[0], v1.e[1], v1.e[2]);
	// printf("v2: %f %f %f\n", v2.e[0], v2.e[1], v2.e[2]);
	sum = vec3_add(v1, v2);
	// printf("Sum: %f %f %f\n", sum.e[0], sum.e[1], sum.e[2]);
	dot_product = vec3_dot(v1, v2);
	// printf("Dot Product: %f\n", dot_product);
	cross_product = vec3_cross(v1, v2);
	// printf("Cross Product: %f %f %f\n", cross_product.e[0], cross_product.e[1],
		// cross_product.e[2]);
	normalized = vec3_normalize(v1);
	// printf("Normalized v1: %f %f %f\n", normalized.e[0], normalized.e[1],
		// normalized.e[2]);
	mlx_loop(mlx);
	free(rgb);
	mlx_destroy_window(mlx, window);
	return (0);
}

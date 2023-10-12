// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_init_get_data.c                                 :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/08 16:09:00 by tkilling          #+#    #+#             */
// /*   Updated: 2023/10/12 14:56:48 by snagulap         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "miniRT.h"

// // int	ft_get_line_data(miniRT *data, char *str, int i);

// // int	ft_get_data(miniRT *data, int fd)
// // {
// // 	char	*str;
// // 	int		line;
// // 	int		i;

// // 	str = get_next_line(fd);
// // 	line = 1;
// // 	while (str)
// // 	{
// // 		i = 0;
// // 		while (i < 1000 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// // 			i++;
// // 		if (str[i] != '\0' && ft_get_line_data(data, str, i))
// // 		{
// // 			return (ft_line_error_message(line));
// // 		}
// // 		free(str);
// // 		str = get_next_line(fd);
// // 		line++;
// // 	}
// // 	return (0);
// // }

// // int	ft_get_A(miniRT *data, char *str, int i);
// // int	ft_get_C(miniRT *data, char *str, int i);
// // int	ft_get_L(miniRT *data, char *str, int i);
// // int	ft_get_sp(miniRT *data, char *str, int i);
// // int	ft_get_pl(miniRT *data, char *str, int i);
// // int	ft_get_cy(miniRT *data, char *str, int i);

// // int	ft_get_line_data(miniRT *data, char *str, int i)
// // {
// // 	if (str[i] == 'A' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
// // 	{
// // 		return (ft_get_A(data, str, i + 1));
// // 	}
// // 	else if (str[i] == 'C' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
// // 	{
// // 		return (ft_get_C(data, str, i + 1));
// // 	}
// // 	else if (str[i] == 'L' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
// // 	{
// // 		return (ft_get_L(data, str, i + 1));
// // 	}
// // 	else if (str[i] == 's' && str[i + 1] == 'p' && (str[i + 2] == ' ' || str[i
// // 			+ 2] == '\t'))
// // 	{
// // 		return (ft_get_sp(data, str, i + 2));
// // 	}
// // 	else if (str[i] == 'p' && str[i + 1] == 'l' && (str[i + 2] == ' ' || str[i
// // 			+ 2] == '\t'))
// // 	{
// // 		return (ft_get_pl(data, str, i + 2));
// // 	}
// // 	else if (str[i] == 'c' && str[i + 1] == 'y' && (str[i + 2] == ' ' || str[i
// // 			+ 2] == '\t'))
// // 	{
// // 		return (ft_get_cy(data, str, i + 2));
// // 	}
// // 	else
// // 		return (1);
// // 	return (0);
// // }
// // /*
// int	ft_get_A(miniRT *data, char *str, int i)
// {
// 	data->amb_lightning.ambient_lighting_ratio = ft_atodouble(str, &i);
// 	if (data->amb_lightning.ambient_lighting_ratio > 1.0
// 		|| data->amb_lightning.ambient_lighting_ratio < 0.0)
// 		return (1);
// 	data->amb_lightning.color.red = ft_atodouble(str, &i);
// 	data->amb_lightning.color.green = ft_atodouble(str, &i);
// 	data->amb_lightning.color.blue = ft_atodouble(str, &i);
// 	if (ft_check_color_range(&(data->amb_lightning.color)))
// 		return (1);
// 	return (0);
// }

// int	ft_get_C(miniRT *data, char *str, int i)
// {
// 	data->camera.coordinatess_of_the_view_point.x = ft_atodouble(str, &i);
// 	data->camera.coordinatess_of_the_view_point.y = ft_atodouble(str, &i);
// 	data->camera.coordinatess_of_the_view_point.z = ft_atodouble(str, &i);
// 	data->camera.normalized_orientation_vector.x = ft_atodouble(str, &i);
// 	data->camera.normalized_orientation_vector.y = ft_atodouble(str, &i);
// 	data->camera.normalized_orientation_vector.z = ft_atodouble(str, &i);
// 	if (ft_check_normalized_vector_range(&(data->camera.normalized_orientation_vector)))
// 		return (1);
// 	data->camera.horizontal_field_of_view_in_degrees = ft_atodouble(str, &i);
// 	if (data->camera.horizontal_field_of_view_in_degrees > 180
// 		|| data->camera.horizontal_field_of_view_in_degrees < 0)
// 		return (1);
// 	return (0);
// }

// int	ft_get_L(miniRT *data, char *str, int i)
// {
// 	data->lights.coordinates_of_the_light_point.x = ft_atodouble(str, &i);
// 	data->lights.coordinates_of_the_light_point.y = ft_atodouble(str, &i);
// 	data->lights.coordinates_of_the_light_point.z = ft_atodouble(str, &i);
// 	data->lights.light_brightness_ratio = ft_atodouble(str, &i);
// 	if (data->lights.light_brightness_ratio > 1.0
// 		|| data->lights.light_brightness_ratio < 0.0)
// 		return (1);
// 	data->lights.rgb_colors.red = ft_atodouble(str, &i);
// 	data->lights.rgb_colors.green = ft_atodouble(str, &i);
// 	data->lights.rgb_colors.blue = ft_atodouble(str, &i);
// 	if (ft_check_color_range(&(data->lights.rgb_colors)))
// 		return (1);
// 	return (0);
// }

// int	ft_get_sp(miniRT *data, char *str, int i)
// {
// 	(data->sphere_arr
// 			+ data->sphere_arr_size)->coordinates_of_the_sphere_center.x = ft_atodouble(str,
// 			&i);
// 	(data->sphere_arr
// 			+ data->sphere_arr_size)->coordinates_of_the_sphere_center.y = ft_atodouble(str,
// 			&i);
// 	(data->sphere_arr
// 			+ data->sphere_arr_size)->coordinates_of_the_sphere_center.z = ft_atodouble(str,
// 			&i);
// 	(data->sphere_arr
// 			+ data->sphere_arr_size)->sphere_diameter = ft_atodouble(str, &i);
// 	(data->sphere_arr
// 			+ data->sphere_arr_size)->rgb_colors.red = ft_atodouble(str, &i);
// 	(data->sphere_arr
// 			+ data->sphere_arr_size)->rgb_colors.green = ft_atodouble(str, &i);
// 	(data->sphere_arr
// 			+ data->sphere_arr_size)->rgb_colors.blue = ft_atodouble(str, &i);
// 	if (ft_check_color_range(&((data->sphere_arr
// 					+ data->sphere_arr_size)->rgb_colors)))
// 		return (1);
// 	(data->sphere_arr_size)++;
// 	return (0);
// }

// int	ft_get_pl(miniRT *data, char *str, int i)
// {
// 	(data->plane_arr
// 			+ data->plane_arr_size)->coordinates_of_a_point_in_the_plane.x = ft_atodouble(str,
// 			&i);
// 	(data->plane_arr
// 			+ data->plane_arr_size)->coordinates_of_a_point_in_the_plane.y = ft_atodouble(str,
// 			&i);
// 	(data->plane_arr
// 			+ data->plane_arr_size)->coordinates_of_a_point_in_the_plane.z = ft_atodouble(str,
// 			&i);
// 	(data->plane_arr
// 			+ data->plane_arr_size)->normalized_normal_vector.x = ft_atodouble(str,
// 			&i);
// 	(data->plane_arr
// 			+ data->plane_arr_size)->normalized_normal_vector.y = ft_atodouble(str,
// 			&i);
// 	(data->plane_arr
// 			+ data->plane_arr_size)->normalized_normal_vector.z = ft_atodouble(str,
// 			&i);
// 	if (ft_check_normalized_vector_range(&((data->plane_arr
// 					+ data->plane_arr_size)->normalized_normal_vector)))
// 		return (1);
// 	(data->plane_arr + data->plane_arr_size)->rgb_colors.red = ft_atodouble(str,
// 			&i);
// 	(data->plane_arr
// 			+ data->plane_arr_size)->rgb_colors.green = ft_atodouble(str, &i);
// 	(data->plane_arr
// 			+ data->plane_arr_size)->rgb_colors.blue = ft_atodouble(str, &i);
// 	if (ft_check_color_range(&((data->plane_arr
// 					+ data->plane_arr_size)->rgb_colors)))
// 		return (1);
// 	(data->plane_arr_size)++;
// 	return (0);
// }

// int	ft_get_cy(miniRT *data, char *str, int i)
// {
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->coordinates_of_center_of_the_cylinder.x = ft_atodouble(str,
// 			&i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->coordinates_of_center_of_the_cylinder.y = ft_atodouble(str,
// 			&i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->coordinates_of_center_of_the_cylinder.z = ft_atodouble(str,
// 			&i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->normalized_vector_of_axis_of_cylinder.x = ft_atodouble(str,
// 			&i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->normalized_vector_of_axis_of_cylinder.y = ft_atodouble(str,
// 			&i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->normalized_vector_of_axis_of_cylinder.z = ft_atodouble(str,
// 			&i);
// 	if (ft_check_normalized_vector_range(&((data->cylinder_arr
// 					+ data->cylinder_arr_size)->normalized_vector_of_axis_of_cylinder)))
// 		return (1);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->cylinder_diameter = ft_atodouble(str,
// 			&i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->cylinder_hight = ft_atodouble(str, &i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->rgb_colors.red = ft_atodouble(str, &i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->rgb_colors.green = ft_atodouble(str,
// 			&i);
// 	(data->cylinder_arr
// 			+ data->cylinder_arr_size)->rgb_colors.blue = ft_atodouble(str, &i);
// 	if (ft_check_color_range(&((data->cylinder_arr
// 					+ data->cylinder_arr_size)->rgb_colors)))
// 		return (1);
// 	(data->cylinder_arr_size)++;
// 	return (0);
// }
// */
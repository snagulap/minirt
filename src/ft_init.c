// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_init.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/04 10:27:52 by tkilling          #+#    #+#             */
// /*   Updated: 2023/10/12 14:54:45 by snagulap         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "miniRT.h"

// void	ft_check_input(miniRT *data, char *argv);
// int		ft_check_file(miniRT *data, int fd);
// void	ft_create_obj_arrays(miniRT *data);
// void	ft_fill_obj_arrays(miniRT *data, char *argv);
// int		ft_get_data(miniRT *data, int fd);

// void	ft_init(miniRT *data, char *argv)
// {
// 	data->nbr_amb_lightning = 0;
// 	data->nbr_camera = 0;
// 	data->light_arr_size = 0;
// 	data->sphere_arr_size = 0;
// 	data->plane_arr_size = 0;
// 	data->cylinder_arr_size = 0;
// 	ft_check_input(data, argv);
// 	ft_create_obj_arrays(data);
// 	ft_fill_obj_arrays(data, argv);
// }

// void	ft_check_input(miniRT *data, char *argv)
// {
// 	size_t	strlen;
// 	int		fd;

// 	strlen = 0;
// 	while (argv[strlen] != '\0')
// 		strlen++;
// 	if (strlen < 3 || argv[--strlen] != 't' || argv[--strlen] != 'r'
// 		|| argv[--strlen] != '.')
// 	{
// 		write(2, "Error\nusage: ./miniRT <filename with the .rt extension>\n",
// 			56);
// 		exit(1);
// 	}
// 	fd = open(argv, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error\n");
// 		exit(1);
// 	}
// 	if (ft_check_file(data, fd))
// 	{
// 		close(fd);
// 		exit(1);
// 	}
// 	close(fd);
// }
// /*
// void	ft_create_obj_arrays(miniRT *data)
// {
// 	data->sphere_arr = (sphere *)malloc(sizeof(sphere) * data->sphere_arr_size);
// 	data->sphere_arr_size = 0;
// 	if (data->sphere_arr == NULL)
// 	{
// 		perror("Error\n");
// 		exit(1);
// 	}
// 	data->plane_arr = (plane *)malloc(sizeof(plane) * data->plane_arr_size);
// 	data->plane_arr_size = 0;
// 	if (data->plane_arr == NULL)
// 	{
// 		perror("Error\n");
// 		free(data->sphere_arr);
// 		exit(1);
// 	}
// 	data->cylinder_arr = (cylinder *)malloc(sizeof(cylinder)
// 			* data->cylinder_arr_size);
// 	data->cylinder_arr_size = 0;
// 	if (data->cylinder_arr == NULL)
// 	{
// 		perror("Error\n");
// 		free(data->sphere_arr);
// 		free(data->plane_arr);
// 		exit(1);
// 	}
// }

// void	ft_fill_obj_arrays(miniRT *data, char *argv)
// {
// 	int	fd;

// 	fd = open(argv, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error\n");
// 		ft_clear(data);
// 		exit(1);
// 	}
// 	if (ft_get_data(data, fd))
// 	{
// 		close(fd);
// 		ft_clear(data);
// 		exit(1);
// 	}
// 	close(fd);
// }*/

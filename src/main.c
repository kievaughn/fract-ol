/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:10:00 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/20 14:42:03 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include <stdio.h>

void	error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

static void	initialize_mlx_window(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		error("Malloc failed");
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error("Malloc failed");
	}
}

static void	initialize_mlx_image(t_fractal *fractal)
{
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error("Malloc failed");
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}

void	initialize_fractal(t_fractal *fractal)
{
	initialize_mlx_window(fractal);
	initialize_mlx_image(fractal);
	setup_event_hooks(fractal);
	initialize_fractal_defaults(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		initialize_fractal(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Wrong command.\n", STDERR_FILENO);
		ft_putstr_fd("./fractol mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("or\n", STDERR_FILENO);
		ft_putstr_fd("./fractol julia <value1> <value2>\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kievaughn <kievaughn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:09:44 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/20 14:30:38 by kievaughn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_9)
		fractal->iterations_def += 10;
	else if (keysym == XK_8)
		fractal->iterations_def -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	ft_putstr_fd("Mouse clicked at ( ", 1);
	ft_putnbr_fd(x, 1);
	write(1, " , ", 3);
	ft_putnbr_fd(y, 1);
	write(1, " )\n", 3);
	if (button == Button4)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button5)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

void	setup_event_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

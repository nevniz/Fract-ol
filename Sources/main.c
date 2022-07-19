/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:39:56 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/09 17:36:17 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	init_struct(t_struct *t)
{
	t->i = -1;
	t->scl = 400;
	t->res.a = 0;
	t->res.b = 0;
	t->res.x = 0;
	t->res.y = 0;
	t->res.p = 0;
	t->color = 0;
	t->iter = 35;
	t->zoom.x = 0;
	t->zoom.y = 0;
	t->res.pc = 0;
	t->res.px = 0;
	t->res.py = 0;
	t->move.x = 0;
	t->move.y = 0;
	t->start.x = -1;
	t->start.y = -1;
	t->scrn.x = 1280;
	t->scrn.y = 720;
	t->jul.y = 0.5666;
	t->jul.x = -0.5666;
	t->mdl.x = t->scrn.x / 2;
	t->mdl.y = t->scrn.y / 2;
}

void	init_arg(t_struct *t)
{
	if (ft_strcmp(t->data.name, "Mandelbrot"))
		t->arg = 1;
	else if (ft_strcmp(t->data.name, "Julia"))
		t->arg = 2;
	else if (ft_strcmp(t->data.name, "Burning ship"))
		t->arg = 3;
	else
	{
		write(1, "Incorrect arguments.\n", 21);
		write(1, "Enter: ./fractal Mandelbrot or Julia or Burning ship.\n", 55);
		exit (0);
	}
	init_window(t);
}

int	main(int argc, char **argv)
{
	t_struct	t;

	if (argc == 2)
	{
		init_struct(&t);
		t.data.name = argv[1];
		init_arg(&t);
	}
	else
	{
		write(1, "Incorrect arguments.\n", 21);
		write(1, "Enter: ./fractal Mandelbrot or Julia or Burning ship.\n", 55);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebgoret <sebgoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 22:20:14 by sebgoret          #+#    #+#             */
/*   Updated: 2014/01/19 20:16:33 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <math.h>
# include <mlx.h>

/*
** Window
*/
# define WIDTH 640
# define HEIGHT 480
# define TITLE "WOLF_3D"

/*
** Move stuff
*/
# define FOV 60.0
# define SPEED 0.2
# define ANGLE_RAD (M_PI / 180)
# define TETA -(M_PI / 6)
# define ANGLE_ROT (M_PI / 2)
# define RAY_CASTING 0.01

/*
** Keys
*/
# define KEY_UP 65362
# define KEY_W 119
# define KEY_DOWN 65364
# define KEY_S 115
# define KEY_LEFT 65361
# define KEY_A 97
# define KEY_RIGHT 65363
# define KEY_D 100
# define ESC 65307
# define CTRL 65507

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ln_size;
	int				endian;
	int				color;
	float			pos_x;
	float			pos_y;
	float			angle;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

/*
 * Map stuff
 */
int		ft_get_map(int x, int y);
void	ft_draw_wall(t_env *e);
void	ft_move(t_env *e, int keycode);
void	ft_get_color(t_env *e);

/*
** Basic draw stuff
*/
void	ft_draw_background(t_env *e, int floor, int sky);
void	ft_put_pix_in_img(t_img *i, t_point *p);

/*
** Geometry stuff
*/
void	ft_draw_square(t_env *e, int x, int y);
void	ft_draw_circle(t_env *e, int r, int x, int y);

/*
** Hooks
*/
int		ft_key_hook(int keycode, t_env *e);
int		ft_mouse_hook(int keycode, int x, int y, t_env *e);
int		ft_expose_hook(t_env *e);

/*
** Keys stuff
*/

#endif /* !WOLF3D_H */

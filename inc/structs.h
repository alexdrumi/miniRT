/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "../libft/headers/libft.h"

typedef enum iiinum
{
	false,
	true
}	t_bool;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct p3
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_point3;

typedef struct v3
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_vector3;

typedef struct color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct canvas
{
	t_color	**pixels;
	int		width;
	int		height;
}				t_canvas;

typedef struct bounds
{
	t_point3	*min;
	t_point3	*max;
}				t_bounds;

typedef struct pattern
{
	t_color	*a;
	t_color	*b;
	double	**transformation_matrix;
}				t_pattern;

typedef struct ray
{
	t_point3	orig;
	t_vector3	dir;
	t_point3	point_at_parameter;
}	t_ray;

typedef struct mat
{
	t_color		color;
	t_pattern	pattern;
	double		reflective;
	double		ambient;
	double		specular;
	double		shininess;
	double		transparency;
	double		refract_index;
}				t_mat;

typedef struct is_shadowed
{
	t_vector3	light_point_vec;
	t_ray		shadow_ray;
	int			is_shadowed;
}				t_is_shadowed;

typedef struct lightings
{
	int			failed_malloc;
	t_color		effective_col;
	t_color		ambient_col;
	t_color		diffuse_col;
	t_color		specular_color;
	t_color		temp_color;
	t_color		total_light_col;
	t_vector3	light_vector;
	t_vector3	reflect_vector;
}				t_lightcalcs;

typedef struct colors
{
	t_color		surface;
	t_color		reflected_color;
	t_color		refracted_color;
	t_color		reflected_times_reflectance;
	t_color		refracted_times_remaining_reflectance;
	t_color		schlick_color;
	t_color		final_col;
	t_color		light_col;
}				t_color_res;

typedef struct shade_hit
{
	t_is_shadowed	shadowed;
	t_lightcalcs	light_calc;
}				t_shade_hit;

/* OBJECTS */
typedef struct ray_object
{
	t_mat				mat;
	t_point3			coord;
	t_vector3			normal;
	t_color				color;
	t_ray				local_ray;
	double				**transform_mtx;
	double				**inv_transform_mtx;
	double				**transpose_inv_mtx;
	double				**translate_mtx;
	double				**rotate_mtx;
	double				**scale_mtx;
	void				(*INTERSECT_FUNCTION)(struct ray_object *,
			t_ray *, void *);
	void				(*LOCAL_NORMAL_FUNCTION)(struct ray_object *,
			t_point3 *, void *, t_vector3 *);
	struct ray_object	*next;
	void				*object;
	int					can_receive_shadows;
	int					can_cast_shadows;
	int					amount_of_children;
	int					id;
	double				radius;
	double				minimum;
	double				maximum;
	int					closed;
}				t_ray_object;

typedef struct point_light
{
	t_point3			position;
	t_color				intensity;
	double				diffuse;
	struct point_light	*next;
}				t_pointlight;

typedef struct plane
{
	t_point3	coord;
	t_bounds	*bounds;
	t_color		color;
	t_mat		mat;
	double		**transform_matrix;
	double		r;
	double		g;
	double		b;
}				t_plane;

typedef struct sphere
{
	t_point3	center;
	t_bounds	*bounds;
	t_color		color;
	t_mat		mat;
	double		**transform_matrix;
	double		radius;
}				t_sphere;

typedef struct cylinder
{
	t_point3	coord;
	t_color		color;
	t_mat		*mat;
	double		**transform_matrix;
	double		minimum;
	double		maximum;
	double		radius;
	double		diameter;
	double		height;
	int			closed;
	t_bounds	*bounds;

}				t_cylinder;

/* INTERSECTIONS */
typedef struct intersection
{
	t_ray_object			*object_intersected;
	double					t_val;
	double					u;
	double					v;
	struct intersection		*next_intersection;
}	t_intersection;

typedef struct intersections
{
	t_intersection		*root;
	t_intersection		*curr;
	int					intersect_count;

}				t_intersections;

typedef struct comps
{
	double			t;
	int				is_inside;
	double			n1;
	double			n2;
	t_ray_object	*obj;
	t_ray			comps_ray;
	t_point3		point;
	t_point3		point_at_parameter;
	t_point3		over_p;
	t_point3		under_p;
	t_vector3		eyev;
	t_vector3		normal;
	t_vector3		reflectv;
	t_vector3		local_normal;
	t_point3		local_point;
	double			n_ratio;
	double			cos_t;
	double			cos_i;
	double			sin2_t;
	t_color			ambient_col;
}				t_comps;

/* MAIN STRUCTURES */
typedef struct camera
{
	t_vector3		orientation;
	t_point3		camera_coord;
	t_data			image_ptr;
	double			**transform_matrix;
	double			**inv_transf_matrix;
	double			fov;
	double			half_fov;
	double			pixel_size;
	double			aspect_ratio;
	double			half_width;
	double			half_height;
	int				h_size;
	int				v_size;
	struct camera	*current_cam;
	struct camera	*next;
}				t_camera;

typedef struct world
{
	t_list			*object_list;
	t_list			*light_list;
	t_shade_hit		shade_hit;
	t_color_res		final_col;
	t_color			ambient_col;
	t_comps			comps;
	t_ray			ray_through_pixel;
	double			ambient_factor;
	int				light_count;
	int				object_count;
}				t_world;

typedef struct rt
{
	t_vector3	camera_orientation;
	t_point3	camera_coord;
	t_color		ambient_col;
	t_world		world;
	t_camera	*current_cam;
	t_canvas	*canvas;
	t_list		*cam_list;
	void		*mlx;
	void		*win;
	double		max_possible_display_sizes[2];
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	double		field_of_view;
	int			res_width;
	int			res_height;
	int			amount_of_cameras;
	int			bitflags;
}				t_minirt;

#endif
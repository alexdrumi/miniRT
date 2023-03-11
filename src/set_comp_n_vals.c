/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_comp_n_vals.C                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/set_comp_n_vals.h"
#include "../inc/general_utils3.h"

static int	get_container_index(t_ray_object **container, t_ray_object *target,
				int size)
{
	int	i;

	i = 0;
	while (container[i] != NULL && i < size)
	{
		if (container[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

static void	set_container(int *containers_index,
				t_ray_object **container, t_intersection *current,
				t_intersections *list)
{
	int				found_index;
	t_ray_object	*temp;

	found_index = get_container_index(container, current->object_intersected,
			(*(containers_index + 1)) + 1);
	if (found_index != -1)
	{
		(*(containers_index)) = found_index;
		while ((*(containers_index)) < (*(containers_index + 1)) + 1
			&& (*(containers_index)) < list->intersect_count)
		{
			temp = container[(*(containers_index)) + 1];
			container[(*(containers_index))] = temp;
			(*(containers_index)) = (*(containers_index)) + 1;
		}
		(*(containers_index + 1)) = (*(containers_index + 1)) - 1;
	}
	else
	{
		(*(containers_index + 1)) = (*(containers_index + 1)) + 1;
		container[(*(containers_index + 1))] = current->object_intersected;
	}
}

static void	set_n1_or_n2(t_ray_object **container,
				int containers_index, int n1_or_n2)
{
	if (containers_index == -1)
		n1_or_n2 = 1;
	else
		n1_or_n2 = container[containers_index]->mat.refract_index;
}

static t_ray_object	**create_container(t_world *world, int intersect_count,
						int *i)
{
	t_ray_object	**container;

	(void)world;
	container = (t_ray_object **)malloc(intersect_count
			* sizeof(t_ray_object *));
	if (!container)
		print_malloc_error_and_exit();
	*i = 0;
	while (*i < intersect_count)
	{
		container[*i] = NULL;
		(*i)++;
	}
	return (container);
}

void	set_comp_n_vals(t_world *world, t_intersection *intersection,
			t_intersections *list, t_comps *comps)
{
	t_intersection	*current;
	t_ray_object	**container;
	int				i;
	static int		j_and_cont_i[2];

	j_and_cont_i[1] = -1;
	container = create_container(world, list->intersect_count, &i);
	current = list->root;
	if (current != NULL)
	{
		while (i < list->intersect_count)
		{
			if (current == intersection)
				set_n1_or_n2(container, j_and_cont_i[1], comps->n1);
			set_container(j_and_cont_i, container, current, list);
			if (current == intersection)
			{
				set_n1_or_n2(container, j_and_cont_i[1], comps->n2);
				break ;
			}
			current = current->next_intersection;
			i++;
		}
	}
	free_split_array_void((void **)container);
}

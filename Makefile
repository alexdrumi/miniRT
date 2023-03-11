
TARGET = miniRT

DEPD = deps/
OBJD = objs/
SRCD = src/
INCD = inc/

MLX_DIR		= 	./minilibx
LIBFT_DIR	=	./libft
LIBFT_A		=	./libft/libft.a

SRCS =	canvas.c change_object_space.c \
		color_at.c color_operations1.c coloring_functions.c \
		destroy1.c destroy2.c destroy4.c \
		ft_fatoi.c general_utils.c \
		general_utils2.c general_utils3.c get_next_line.c \
		init_functions1.c init_functions2.c init_functions3.c \
		init_functions4.c intersect_cylinder.c \
		intersect_plane.c intersect_sphere.c \
		intersect_utils.c intersections.c \
		inverse_matrix.c is_shadowed.c lighting.c linked_list.c \
		matrix_operations1.c matrix_operations2.c matrix_operations3.c \
		matrix_operations4.c matrix_operations5.c mlx_functions.c \
		normals.c object_normals.c parse1.c parse_utils.c \
		patterns.c pixel_operations.c point_operations1.c prepare_computations_utils.c \
		quarternion.c quicksort.c \
		render.c set_comp_n_vals.c shade_hit.c \
		store_ambient.c store_camera.c \
		store_cylinder.c store_lights.c store_plane.c \
		store_resolution.c store_sphere.c intersect_square.c \
		main.c vector_operations1.c vector_operations2.c \
		vector_operations3.c lighting2.c init_functions5.c quicksort2.c prepare_computations_main.c

OBJS = $(SRCS:%.c=$(OBJD)%.o)
DEPS = $(SRCS:%.c=$(DEPD)%.d)

vpath %.h $(INCD)
vpath %.c $(SRCD)
vpath %.o $(OBJD)

HFLAGS 	=	$(addprefix -I, $(INCD))
DEPFLAGS 	=	-MT $@ -MMD -MP -MF $(DEPD)$*.d
HEADER		=	inc
CC			=	gcc 
CFLAGS		=	-Wall -Wextra
LFLAGS		=	-L libft -lft
RM			=	rm -rf
MLX_F		=	libmlx.dylib -framework OpenGL -framework AppKit

all: $(OBJD) $(DEPD) $(TARGET) 

$(OBJD):
	@mkdir -p $(OBJD)

$(DEPD):
	@mkdir -p $(DEPD)

$(OBJD)%.o: %.c $(DEPD)%.d
	@$(CC) $(CFLAGS) $(HFLAGS) $(DEPFLAGS) -c $< -o $@

$(TARGET) : $(OBJS)
	@make -C $(MLX_DIR)
	@mv $(MLX_DIR)/libmlx.dylib .
	@make -s -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) $(MLX_F) -I $(HEADER) $^ -o $@

clean:
	@$(RM) $(OBJD)
	@$(RM) $(DEPD)
	@$(RM) libmlx.dylib
	@$(RM) libft/sources/*.o
	@$(RM) libft/libft.a

fclean: clean
	$(RM) $(TARGET)

re: fclean all	

.PHONY : all clean fclean re

$(DEPS) :
include $(wildcard $(DEPS))




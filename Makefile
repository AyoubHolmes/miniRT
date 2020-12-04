NAME = minirt.a
AR = ar rcs
FLAGS =

SRC = ./srcs/camera.c \
		./srcs/camera_lists.c \
		./srcs/equations.c \
		./srcs/equations_cylinder.c \
		./srcs/equations_triangle.c \
		./srcs/color_func.c \
		./srcs/executers.c \
		./srcs/geters.c \
		./srcs/handlers.c \
		./srcs/main.c \
		./srcs/ray.c \
		./srcs/rot_trs.c \
		./srcs/save.c \
		./srcs/shadow_handlers.c \
		./srcs/vector.c\
		./srcs/rotatevect.c\
		./srcs/operations.c \
		./srcs/key_press.c\
		./parsing/checkers.c \
		./parsing/checkers2.c \
		./parsing/data_checker_handler.c \
		./parsing/data_checkers.c \
		./parsing/data_checkers2.c \
		./parsing/data_initializer.c \
		./parsing/data_initializer2.c \
		./parsing/data_insertion_handler.c \
		./parsing/error_printer.c \
		./parsing/ft_lstfuncs.c \
		./parsing/ft_lstfuncs2.c \
		./parsing/ft_putchar_fd.c \
		./parsing/ft_putnbr_fd.c \
		./parsing/ft_putstr_fd.c \
		./parsing/ft_split.c \
		./parsing/ft_strncmp.c \
		./parsing/ft_white_spaces.c \
		./parsing/get_next_line.c \
		./parsing/get_next_line_utils.c \
		./parsing/parser_functions.c\
		./parsing/parser_functions2.c\
		./parsing/my_frees.c\
		./parsing/parser.c\



HEADERS = ./includes/
OBJECT = $(SRC:.c=.o)
MLX_MMS = ./minilibx_mms_20200219
MLX_OGL = ./minilibx_opengl_20191021
$(NAME): $(OBJECT)
	@make -sC $(MLX_MMS)
	@make -sC $(MLX_OGL)
	@$(AR) $(NAME) $(OBJECT)
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@cp ./minilibx_mms_20200219/libmlx.dylib .
	@gcc $(FLAGS)  -I /usr/local/include -L ./minilibx_opengl_20191021 libmlx.a libmlx.dylib -lmlx -framework OpenGl -framework AppKit  minirt.a -o miniRT
	@clear
%.o: %.c
	@gcc $(FLAGS) -I $(HEADERS)  -o $@ -c $<
all: $(NAME)
clean:
	@rm -f $(OBJECT)
	@make clean -sC $(MLX_MMS)
	@make clean -sC $(MLX_OGL)
	@rm -f libmlx.dylib
	@rm -f libmlx.a
	@rm -f miniRT
	
fclean: clean
	@rm -f $(NAME)
re: fclean $(NAME)
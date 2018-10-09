cmake_minimum_required(VERSION 3.12)
project(fdf C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER  clang)

include_directories(includes)
include_directories(libft/includes)
include_directories(libft/includes/ft_printf)
include_directories(libmlx_linux)
include_directories(/usr/X11/include)

link_directories(libft
        /home/user/minilibx11/minilibx
        /usr/X11/lib)

add_executable(fdf
        srcs/build_connections.c
        srcs/key_parser.c
        srcs/main.c
        srcs/read_file.c
        srcs/treatment.c)

target_link_libraries(fdf
        mlx
        libft.a
        m
        X11
        Xext)
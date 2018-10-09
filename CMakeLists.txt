cmake_minimum_required(VERSION 3.12)
project(fdf C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER  clang)

include_directories(includes)
include_directories(libft/includes)
include_directories(libft/includes/ft_printf)

link_directories(libft)

add_executable(fdf
        srcs/build_connections.c
        srcs/key_parser.c
        srcs/main.c
        srcs/read_file.c
        srcs/treatment.c
        srcs/trace_line.c)

if (UNIX AND LINUX)
    include_directories(libmlx_linux)
    include_directories(/usr/X11/include)

    link_directories(/home/user/minilibx11/minilibx
            /usr/X11/lib)
    target_link_libraries(fdf
            mlx
            libft.a
            m
            X11
            Xext)
endif(UNIX AND LINUX)
if (UNIX AND APPLE)
    include_directories(libmlx_macos)
    link_directories(libmlx_macos)
    target_link_libraries(fdf
            mlx
            libft.a
            m
            "-framework OpenGL"
            "-framework AppKit")
endif(UNIX AND APPLE)
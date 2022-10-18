#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct s_img
{
    void    *img;
    char    *address;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_img;

void    ft_close(void)
{
    system("leaks a.out");
    exit(0);   
}

void    fill_img(t_img *dst_img, t_img *src_img, int x, int y)
{
    int     i;
    int     j;
    char    *dst;
    char    *src;

    i = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            dst = dst_img->address + ((i + y) * dst_img->line_length
                + (j + x) * (dst_img->bits_per_pixel / 8));
            src = src_img->address + (i * src_img->line_length
                + j * (src_img->bits_per_pixel / 8));
            if (*(unsigned int *)src != 0xff000000)
                *(unsigned int *)dst = *(unsigned int *)src;
            ++j;
        }
        ++i;
    }
}

int main(void)
{
    void    *mlx;
    void    *win;
    t_img   img;
    t_img   tex;
    t_img   ground;
    int     w;
    int     h;
    char    *dst;
    char    *src;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 640, "TEST IMG");

    img.img = mlx_new_image(mlx, 640, 640);
    img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    tex.img = mlx_xpm_file_to_image(mlx, "assets/chest.xpm", &w, &h);
    tex.address = mlx_get_data_addr(tex.img, &tex.bits_per_pixel, &tex.line_length, &tex.endian);

    ground.img = mlx_xpm_file_to_image(mlx, "assets/grass.xpm", &w, &h);
    ground.address = mlx_get_data_addr(ground.img, &ground.bits_per_pixel, &ground.line_length, &ground.endian);

    int y = 0;
    while (y < 10)
    {
        int x = 0;
        while (x < 10)
        {
            fill_img(&img, &ground, x * 64, y * 64);
            ++x;
        }
        ++y;
    }
    fill_img(&img, &tex, 10, 10);

    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    mlx_hook(win, 17, 0, ft_close, NULL);
    mlx_loop(mlx);

    return 0;
}
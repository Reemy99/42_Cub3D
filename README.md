
# Cub3d
This project is about making 3D game in C language using mlx library
__________________________________________________________________________________________________________________

### calculate with radian
        M_PI = 3.1415 π
        1π   = 57.295 degree
        
    M_PI * 2 = 6.2831   π
    6.2831   = 359.999  degree (full circle)

_____________________________________________
    
    

### mlx_hook

Hooking into events It allows you to register to any of the below events with the call of hook function

> prototype

    void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)

we used it on *int main* function with calling the *RELEASE, PRESS and DESTROY* events

<img width="717" alt="events in mlx" src="https://github.com/realdahh/Cub3d/assets/111651235/356b4041-17c0-48be-90f3-764f5c161853">

_____________________________________________

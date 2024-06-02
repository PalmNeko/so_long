


# 利用イメージ
```c

int main() {

    mlxw_start(pre_setup, mlx_main_loop);
}


// get_window_count(mlx);
// destroy(mlx);
// add_win_hook(win, event, function);
// 
start_mxw(pre_setup, mlx_main_loop) {
    mlx = init_mlx();
    pre_setup(mlx);
    mlx_loop_hook(vars.mlx, mlx_main_loop, &mlx);
    mlx_loop(mlx.mlx);
    destroy(mlx);
}

pre_setup(mlx) {
    mlx->datas = create_so_long();
    idx = create_window(mlx, width, cols, title);
    img = load(file);
}

mlx_main_loop(mlx) {

    wind = get_window(mlx, idx);
    write_img(wind, img);
    flip_window(wind);
    clear_buf(wind);
}

update_so_long_window() {

}
```
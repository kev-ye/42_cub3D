# 42 project : Cub3d

## Index

* [Presentation](#Presentation)
* [How_to_run](#How_to_run)
* [Some_debug](#Some_debug)
* [Utils_docs](#Utils_docs)

## Presentation

This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

## How_to_run

    Program are tested in Macos and linux.

Mandadory part :

    make && ./cub3D map/map.cub

Bonus part :

    make bonus && ./cub3D_bonus map/map_bonus.cub

## Some_debug

    My program is not prefect because it have some "Still reachable" leaks in linux (found with valgrind).

    “still reachable” means your program is probably ok – it didn’t free some memory it could have. This is quite common and often reasonable. Don’t use –show-reachable=yes if you don’t want to see these reports.

Solution :

    Use the function "mlx_destroy_display(void *mlx_ptr)" to destroy your mlx pointer and free it.


## Utils_docs

[__Link_getting_started_mlx__](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)  
[__Link_lodev_raycasting__](https://lodev.org/cgtutor/raycasting.html)
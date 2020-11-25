/*
** EPITECH PROJECT, 2020
** display srpit
** File description:
** nomre
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int display_first_sprite(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/canard1.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfVector2f pos = {c, y};
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(window, my_sprite, NULL), h++;
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
    return (h);
}

int display_second_sprite(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/canard2.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfVector2f pos = {c, y};
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(window, my_sprite, NULL), h++;
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
    return (h);
}

int display_third_sprite(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/canard3.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfVector2f pos = {c, y};
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(window, my_sprite, NULL), h++;
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
    return (h);
}

int display_duck(sfRenderWindow *window, int c, int y, game_t *game)
{
    int h = game->h;
    int e = game->speed;

    if (h >= 0 && h <= 30 )
        h = display_first_sprite(window, c, y, h);
    if (h >= 31 && h <= 60)
        h = display_second_sprite(window, c, y, h);
    if (h >= 61 && h <= 90)
        h = display_third_sprite(window, c, y, h);
    if (h > 90)
        h = 0;
    if (e == 1 || e == 2 || e == 3)
        h = h + 1;
    if (e == 4 || e == 5 || e == 6)
        h = h + 2;
    return (h);
}

int display_crosshair(sfRenderWindow *window)
{
    sfTexture *crosshair = sfTexture_createFromFile("pic/crosshair.png", NULL);
    sfSprite *my_crosshair = sfSprite_create();
    sfSprite_setTexture(my_crosshair, crosshair, sfTrue);

    sfVector2f crosspos;
    crosspos.x = sfMouse_getPositionRenderWindow(window).x - 50;
    crosspos.y = sfMouse_getPositionRenderWindow(window).y - 50;
    sfMouse_getPositionRenderWindow(window);
    sfSprite_setPosition(my_crosshair, crosspos);
    sfRenderWindow_drawSprite(window, my_crosshair, NULL);
    sfTexture_destroy(crosshair);
    sfSprite_destroy(my_crosshair);
}
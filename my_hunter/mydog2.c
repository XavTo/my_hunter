/*
** EPITECH PROJECT, 2020
** my dog
** File description:
** animation
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

int display_4_dog(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/dog4.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfVector2f size = {2, 2};
    sfSprite_scale(my_sprite, size);
    sfVector2f pos = {c, y};
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(window, my_sprite, NULL), h++;
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
    return (h);
}

int display_5_dog(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/dog5.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfVector2f size = {2, 2};
    sfSprite_scale(my_sprite, size);
    sfVector2f pos = {c, y};
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(window, my_sprite, NULL), h++;
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
    return (h);
}

int display_6_dog(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/dog5.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfVector2f size = {2, 2};
    sfSprite_scale(my_sprite, size);
    sfVector2f pos = {c, y};
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(window, my_sprite, NULL);
    h++;
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
    return (h);
}

int dog_run(sfRenderWindow *window, int c, int y, int h)
{
    if (h <= 30)
        h = display_4_dog(window, 420, y, h);
    if (h >= 31 && h <= 60)
        h = display_5_dog(window, 420, y, h);
    if (h >= 61 && h <= 90)
        h = display_6_dog(window, 420, y, h);
    return (h);
}

int display_third_dog(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/dogfeel.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite, my_texture, sfTrue);
    sfVector2f size = {2, 2};
    sfSprite_scale(my_sprite, size);
    sfVector2f pos = {c, y};
    sfSprite_setPosition(my_sprite, pos);
    sfRenderWindow_drawSprite(window, my_sprite, NULL), h++;
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_sprite);
    return (h);
}
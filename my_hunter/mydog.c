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

int display_first_dog(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/dog1.png", NULL);
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

int display_second_dog(sfRenderWindow *window, int c, int y, int h)
{
    sfTexture *my_texture = sfTexture_createFromFile("pic/dog2.png", NULL);
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

int display_dog(sfRenderWindow *window, int c, int y, int h)
{
    if (h >= 0 && h <= 30)
        h = display_first_dog(window, c, y, h);
    if (h >= 31 && h <= 60)
        h = display_second_dog(window, c, y, h);
    if (h >= 61 && h <= 90)
        h = display_third_dog(window, c, y, h);
    if (h > 90)
        h = 0;
    return (h);
}

void my_dog_sprite(sfRenderWindow *window, sfEvent event, int c, int h)
{
    sfTexture *backgro = sfTexture_createFromFile("pic/back.png", NULL);
    sfMusic *music;
    sfSprite *my_spriteback = sfSprite_create();
    int y = 500;

    music = sfMusic_createFromFile("mus/dog.ogg"), sfMusic_setVolume(music, 5);
    sfSprite_setTexture(my_spriteback, backgro, sfTrue), sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spriteback, NULL);
        if (c <= 420) h = display_dog(window, c, y, h), c++;
        if (c > 420 && c < 422) h = 0;
        if (c > 420) h = dog_run(window, c, y, h), c++;
        if (c > 450 && c < 490) y = y - 1;
        if (c > 520) sfMusic_destroy(music), my_level1(window, 5);
        display_crosshair(window), sfRenderWindow_display(window);
    }
}

int my_dog_sprite2(sfRenderWindow *window, sfEvent event, int c, int h)
{
    sfTexture *backgro = sfTexture_createFromFile("pic/back2.png", NULL);
    sfMusic *music;
    sfSprite *my_spriteback = sfSprite_create();
    int y = 500;

    music = sfMusic_createFromFile("mus/dog.ogg"), sfMusic_setVolume(music, 5);
    sfSprite_setTexture(my_spriteback, backgro, sfTrue), sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spriteback, NULL);
        if (c <= 420) h = display_dog(window, c, y, h), c++;
        if (c > 420 && c < 422) h = 0;
        if (c > 420) h = dog_run(window, c, y, h), c++;
        if (c > 450 && c < 490) y = y - 1;
        if (c > 520) {sfMusic_destroy(music), my_level2(window, 0);
            return (-1);
        }
        display_crosshair(window), sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    return (0);
}
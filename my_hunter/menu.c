/*
** EPITECH PROJECT, 2020
** my_menu
** File description:
** 2 games
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

sfText *my_los(void)
{
    sfFont* finalfont = sfFont_createFromFile("font/Games.ttf");
    sfText* finres = sfText_create();
    sfVector2f fipos = {140, 0};

    sfText_setString(finres, "Game Over");
    sfText_setFont(finres, finalfont), sfText_setCharacterSize(finres, 100);
    sfText_setColor(finres, sfRed), sfText_setPosition(finres, fipos);
    return (finres);
}

sfText *my_vic(void)
{
    sfFont* finfont = sfFont_createFromFile("font/Games.ttf");
    sfText* finalres = sfText_create();
    sfVector2f fipos = {220, 160};

    sfText_setFont(finalres, finfont), sfText_setCharacterSize(finalres, 100);
    sfText_setColor(finalres, sfGreen), sfText_setPosition(finalres, fipos);
    return (finalres);
}

int ch_menu(sfRenderWindow *window, sfEvent event, sfMusic *music)
{
    if (event.mouseMove.y >= 130 && event.mouseMove.y <= 640) {
        if (event.mouseButton.y >= 350 && event.mouseButton.y <= 400) {
            sfMusic_destroy(music);
            my_dog_sprite(window, event, 0, 0);
            return (-1);
        }
    }
    if (event.mouseMove.y >= 120 && event.mouseMove.y <= 650) {
        if (event.mouseButton.y >= 420 && event.mouseButton.y <= 450) {
            sfMusic_destroy(music);
            my_dog_sprite2(window, event, 0, 0);
            return (-1);
        }
    }
    return (0);
}

int my_menu(sfRenderWindow *window, sfEvent event)
{
    sfTexture *back = sfTexture_createFromFile("pic/menu.png", NULL);
    sfMusic *music;
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {1.2, 1.2};

    music = sfMusic_createFromFile("mus/menu.ogg"), sfMusic_setLoop(music, 1);
    sfSprite_scale(my_spr, size), sfSprite_setTexture(my_spr, back, sfTrue);
    sfMusic_setVolume(music, 5), sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
                if (ch_menu(window, event, music) == -1) return (0);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spr, NULL);
        display_crosshair(window), sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
}

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_m = {800, 600, 32};

    window = sfRenderWindow_create(video_m, "Hunter", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 90);
    my_level1(window, 0);
    return (0);
}
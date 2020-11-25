/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** duck hunt
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

int check_e(sfRenderWindow *window, sfEvent event, fduck_t *duck1, game_t *game)
{
    int j = duck1->y;
    int a = 1;
    sfMusic* music;

    if (event.mouseMove.y >= (duck1->c - 10)
        && event.mouseMove.y <= (duck1->c + 100)) {
        if (event.mouseButton.y >= (duck1->y - 10)
            && event.mouseButton.y <= (duck1->y + 100)) {
            music = sfMusic_createFromFile("mus/hit.ogg");
            sfMusic_setVolume(music, 10), sfMusic_play(music);
            draw_hit_dck(window, duck1, game, j);
            draw_fall_duck(window, duck1, game), duck1->c = 0;
        }
        while (a != 0)
            a = sfMusic_getStatus(music);
    }
    return (duck1->c);
}

int my_win(sfRenderWindow *window, sfEvent event)
{
    sfMusic* music = sfMusic_createFromFile("mus/win.ogg");
    sfTexture *victory = sfTexture_createFromFile("pic/victory.jpg", NULL);
    sfSprite *my_win = sfSprite_create();
    sfText* final = my_vic();

    sfMusic_setVolume(music, 5), sfSprite_setTexture(my_win, victory, sfTrue);
    sfText_setString(final, "Victory"), sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
                sfMusic_destroy(music), my_menu(window, event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_win, NULL);
        sfRenderWindow_drawText(window, final, NULL);
        display_crosshair(window), sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
}

void my_lose(sfRenderWindow *window, sfEvent event)
{
    sfMusic* music = sfMusic_createFromFile("mus/lose.ogg");
    sfTexture *lose = sfTexture_createFromFile("pic/lose.jpg", NULL);
    sfSprite *my_lose = sfSprite_create();
    sfText* fin = my_los();

    sfMusic_setVolume(music, 15), sfMusic_play(music);
    sfSprite_setTexture(my_lose, lose, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
                sfMusic_destroy(music), my_menu(window, event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_lose, NULL);
        sfRenderWindow_drawText(window, fin, NULL);
        display_crosshair(window), sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
}

int display_target(sfRenderWindow *window, int result)
{
    int d = 250;
    int z = 0;
    sfTexture *emt = sfTexture_createFromFile("pic/target_empty.png", NULL);
    sfSprite *my_target_empty = sfSprite_create();
    sfSprite_setTexture(my_target_empty, emt, sfTrue);
    sfTexture *lifete = sfTexture_createFromFile("pic/target_fill.png", NULL);
    sfSprite *my_target_filled = sfSprite_create();
    sfSprite_setTexture(my_target_filled, lifete, sfTrue);

    while (z != result) {
        sfVector2f lifepos = {d, 0};
        sfSprite_setPosition(my_target_filled, lifepos), d = d + 30, z++;
        sfRenderWindow_drawSprite(window, my_target_filled, NULL);
    }
    while (z != 10) {
        sfVector2f empos = {d, 0};
        sfSprite_setPosition(my_target_empty, empos), d = d + 30, z++;
        sfRenderWindow_drawSprite(window, my_target_empty, NULL);
    }
    return (0);
}

int my_level1(sfRenderWindow *window, int dog)
{
    sfEvent event;
    sfTexture *background = sfTexture_createFromFile("pic/back.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    fduck_t duck1 = {0, 0};
    game_t game = {0, 0, 0, 3, 0, 0, dog};

    sfSprite_setTexture(my_spriteback, background, sfTrue);
    srand(time(NULL)), duck1.y = rand() % 500;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spriteback, NULL);
        split_2(&duck1, &game, window, event);
    }
}
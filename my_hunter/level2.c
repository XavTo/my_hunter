/*
** EPITECH PROJECT, 2020
** level2
** File description:
** continue
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

int display_final(sfRenderWindow *window, int result, int hs, sfSprite *back)
{
    char score[] = "Score : ";
    int i = 0;
    char *res = malloc(sizeof(char) * 3);
    char *high =  malloc(sizeof(char) * 3);
    sfEvent event;

    res = trans_char2(res, result);
    high = trans_char(high, result, &hs);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) my_level2(window, hs);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, back, NULL);
        display_mytext(window, high, res, score);
    }
    free(res), free (high);
}

int my_final_score(sfRenderWindow *window, sfEvent event, int r, int h)
{
    sfMusic* music = sfMusic_createFromFile("mus/lose.ogg");
    sfTexture *background = sfTexture_createFromFile("pic/victory.jpg", NULL);
    sfSprite *back = sfSprite_create();

    sfSprite_setTexture(back, background, sfTrue);
    sfMusic_setVolume(music, 15);
    sfMusic_play(music);
    sfRenderWindow_clear(window, sfBlack);
    h = display_final(window, r, h, back);
    display_crosshair(window);
    sfRenderWindow_display(window);
    sfMusic_destroy(music);
    return (0);
}

duck_t check_e3(sfRenderWindow *wind, sfEvent event, game_t *game, duck_t *duck)
{
    move_t move;
    int a = 1;
    move.j = duck->y2, move.p_c2 = &duck->c;
    move.p_y2 = &duck->y, move.h = game->h;
    move.save_c = (*move.p_c2), move.save_y = (*move.p_y2);
    sfMusic* music;
    if (event.mouseMove.y >= (duck->c2 - 10)
        && event.mouseMove.y <= (duck->c2 + 100)) {
        if (event.mouseButton.y >= (duck->y2 - 10)
            && event.mouseButton.y <= (duck->y2 + 100)) {
            music = sfMusic_createFromFile("mus/hit.ogg");
            sfMusic_setVolume(music, 10), sfMusic_play(music);
            draw_hit(wind, duck, game, &move);
            draw_fall(wind, duck, game, &move);
            duck->c = move.save_c, duck->y = move.save_y, duck->c2 = -50;
            if (duck->y2 > 550) duck->y2 = 400, duck->c2 = -50;
            if (duck->y > 550) duck->y = 400, duck->c = -50;
            sfMusic_destroy(music);
        }
    }
}

duck_t check_e2(sfRenderWindow *wind, sfEvent event, game_t *game, duck_t *duck)
{
    move_t move;
    int a = 1;
    move.j = duck->y, move.h = game->h;
    move.p_c2 = &duck->c2, move.p_y2 = &duck->y2;
    move.save_c = (*move.p_c2), move.save_y = (*move.p_y2);
    sfMusic *music;
    if (event.mouseMove.y >= (duck->c - 10)
        && event.mouseMove.y <= (duck->c + 100)) {
        if (event.mouseButton.y >= (duck->y - 10)
            && event.mouseButton.y <= (duck->y + 100)) {
            music = sfMusic_createFromFile("mus/hit.ogg");
            sfMusic_setVolume(music, 10), sfMusic_play(music);
            draw_hit2(wind, duck, game, &move);
            draw_f2(wind, duck, game, &move);
            duck->c2 = move.save_c, duck->y2 = move.save_y, duck->c = -50;
            if (duck->y2 > 550) duck->y2 = 400, duck->c2 = -50;
            if (duck->y > 550) duck->y = 400, duck->c = -50;
            sfMusic_destroy(music);
        }
    }
}

int my_level2(sfRenderWindow *window, int max)
{
    sfEvent event;
    sfTexture *background = sfTexture_createFromFile("pic/back2.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    game_t game = {0, 0, 0, 3, max, 0, 0};
    duck_t duck = {-50, 0, -200 , 0};

    sfSprite_setTexture(my_spriteback, background, sfTrue);
    srand(time(NULL)), duck.y = rand() % 500;
    srand(time(NULL) + 1), duck.y2 = rand() % 500;
    sfRenderWindow_setFramerateLimit(window, 90);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed)
                split3(&duck, &game, window, event);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spriteback, NULL);
        split4(&duck, &game, window, event);
    }
}
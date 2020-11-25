/*
** EPITECH PROJECT, 2020
** split main
** File description:
** whit p_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

void split_event(fduck_t *duck1, game_t *game, sfRenderWindow *wind, sfEvent ev)
{
    int check = 0;

    check = duck1->c;
    duck1->c = check_e(wind, ev, duck1, game);
    if (duck1->c != check) {
        game->result++;
        if (game->result % 3 == 0)
            game->speed++;
        srand(time(NULL));
        duck1->y = rand() % 520;
    }
    else {
        sfMusic *music = music = sfMusic_createFromFile("mus/life.ogg");
        sfMusic_setVolume(music, 15), sfMusic_play(music);
        game->life--;
    }
}

sfMusic *split_1(fduck_t *duck1, game_t *game, sfRenderWindow *wind, sfMusic *m)
{
    sfEvent event;

    duck1->c = duck1->c + 1 + game->speed;
    if (duck1->c > 835 && game->life > 0) {
        game->life--, duck1->c = 0, srand(time(NULL)), duck1->y = rand() % 500;
        sfMusic_destroy(m);
        m = sfMusic_createFromFile("mus/life.ogg");
        sfMusic_setVolume(m, 15), sfMusic_play(m);
    }
    if (duck1->c > 835 && game->life == 0 || game->life == 0)
        my_lose(wind, event);
    display_life(wind, game->life);
    display_target(wind, game->result);
    display_font(wind, game->result);
    game->h = display_duck(wind, duck1->c, duck1->y, game);
    return (m);
}

void split_2(fduck_t *duck1, game_t *game, sfRenderWindow *window, sfEvent eve)
{
    sfMusic *music;
    sfMusic *shoot = sfMusic_createFromFile("mus/shoot.ogg");

    while (sfRenderWindow_pollEvent(window, &eve)) {
        if (eve.type == sfEvtClosed) sfRenderWindow_close(window);
        if (eve.type == sfEvtMouseButtonPressed) {
            sfMusic_destroy(shoot);
            shoot = sfMusic_createFromFile("mus/shoot.ogg");
            sfMusic_setVolume(shoot, 20), sfMusic_play(shoot);
            split_event(duck1, game, window, eve), eve.type = 0;
        }
    }
    if (game->dog <= 0)
        my_menu(window, eve), game->dog = 5;
    music = split_1(duck1, game, window, music);
    display_crosshair(window), sfRenderWindow_display(window);
    if (game->result == 10)
        my_win(window, eve);
    sfMusic_destroy(shoot);
}

void split3(duck_t *duck, game_t *game, sfRenderWindow *window, sfEvent eve)
{
    int check = game->result;
    sfMusic *music = sfMusic_createFromFile("mus/shoot.ogg");
    sfMusic *life = sfMusic_createFromFile("mus/life.ogg");

    sfMusic_destroy(music), music = sfMusic_createFromFile("mus/shoot.ogg");
    sfMusic_setVolume(music, 10), sfMusic_play(music);
    check_e2(window, eve, game, duck), check_e3(window, eve, game, duck);
    sfRenderWindow_clear(window, sfBlack), check_hit(window, duck, game);
    if (game->result != check && duck->c == -50)
        srand(time(NULL)), duck->y = rand() % 500;
    if (game->result != check && duck->c2 == -50)
        srand(time(NULL)), duck->y2 = rand() % 500;
    if (game->result == check) {
        sfMusic_destroy(life), game->life--;
        life = sfMusic_createFromFile("mus/life.ogg");
        sfMusic_setVolume(life, 15), sfMusic_play(life);
    }
    sfMusic_destroy(music), eve.type = 0;
}

int split4(duck_t *duck, game_t *game, sfRenderWindow *window, sfEvent eve)
{
    sfMusic *life;

    check_y_tooclose(duck);
    duck->c = duck->c + 1 + game->speed, duck->c2 = duck->c2 + 1 + game->speed;
    if (duck->c2 > 825) {
        game->life--, duck->c2 = 0, srand(time(NULL)), duck->y2 = rand() % 520;
        life = sfMusic_createFromFile("mus/life.ogg");
        sfMusic_setVolume(life, 15), sfMusic_play(life);
    }
    if (duck->c > 825) {
        life = sfMusic_createFromFile("mus/life.ogg");
        sfMusic_setVolume(life, 15), sfMusic_play(life);
        game->life--, duck->c = 0, srand(time(NULL)), duck->y = rand() % 500;
    }
    if (game->life == 0) my_final_score(window, eve, game->result, game->hs);
    display_life(window, game->life), display_font(window, game->result);
    game->h = display_duck(window, duck->c, duck->y, game);
    game->sec = display_duck(window, duck->c2, duck->y2, game);
    display_crosshair(window), sfRenderWindow_display(window);
}
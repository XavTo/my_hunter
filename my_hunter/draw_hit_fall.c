/*
** EPITECH PROJECT, 2020
** draw hit and fall
** File description:
** both
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

move_t draw_hit(sfRenderWindow *wind, duck_t *duck, game_t *game, move_t *move)
{
    sfTexture *my_hit = sfTexture_createFromFile("pic/hit.png", NULL);
    sfTexture *background = sfTexture_createFromFile("pic/back2.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    sfSprite *my_sprite = sfSprite_create();

    sfSprite_setTexture(my_spriteback, background, sfTrue);
    sfSprite_setTexture(my_sprite, my_hit, sfTrue);
    while (duck->y2 != (move->j + 20 - game->speed)) {
        sfRenderWindow_drawSprite(wind, my_spriteback, NULL);
        sfVector2f pos = {duck->c2, duck->y2};
        sfSprite_setPosition(my_sprite, pos);
        sfRenderWindow_drawSprite(wind, my_sprite, NULL);
        duck->y2 = duck->y2 + 1;
        display_font(wind, game->result), display_life(wind, game->life);
        game->h = display_duck(wind, move->save_c, move->save_y, game);
        move->p_c2 = move->p_c2 + 1 + game->speed;
        move->save_c = move->save_c + 1 + game->speed;
        display_crosshair(wind), sfRenderWindow_display(wind);
    }
    sfTexture_destroy(my_hit), sfTexture_destroy(background), move->h = game->h;
}

move_t draw_fall(sfRenderWindow *wind, duck_t *duck, game_t *game, move_t *move)
{
    sfTexture *my_fall = sfTexture_createFromFile("pic/fall.png", NULL);
    sfTexture *back = sfTexture_createFromFile("pic/back2.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    sfSprite *my_spri2 = sfSprite_create();
    sfSprite_setTexture(my_spri2, my_fall, sfTrue);
    sfSprite_setTexture(my_spriteback, back, sfTrue);

    while (duck->y2 < 550) {
        sfRenderWindow_drawSprite(wind, my_spriteback, NULL);
        sfVector2f pos = {duck->c2, duck->y2};
        duck->y2 = duck->y2 + 7 + game->speed;
        sfSprite_setPosition(my_spri2, pos);
        sfRenderWindow_drawSprite(wind, my_spri2, NULL);
        display_font(wind, game->result), display_life(wind, game->life);
        game->h = display_duck(wind, move->save_c, move->save_y, game);
        move->p_c2 = move->p_c2 + 1 + game->speed;
        move->save_c = move->save_c + 1 + game->speed;
        display_crosshair(wind), sfRenderWindow_display(wind);
    }
    sfTexture_destroy(my_fall), sfTexture_destroy(back), move->h = game->h;
}

move_t draw_hit2(sfRenderWindow *wind, duck_t *duck, game_t *game, move_t *move)
{
    sfTexture *my_hit = sfTexture_createFromFile("pic/hit.png", NULL);
    sfTexture *background = sfTexture_createFromFile("pic/back2.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_spriteback, background, sfTrue);
    sfSprite_setTexture(my_sprite, my_hit, sfTrue);

    while (duck->y != (move->j + 20 - game->speed)) {
        sfRenderWindow_drawSprite(wind, my_spriteback, NULL);
        sfVector2f pos = {duck->c, duck->y};
        sfSprite_setPosition(my_sprite, pos);
        sfRenderWindow_drawSprite(wind, my_sprite, NULL), duck->y++;
        display_font(wind, game->result), display_life(wind, game->life);
        game->h = display_duck(wind, move->save_c, move->save_y, game);
        move->p_c2 = move->p_c2 + 1 + game->speed;
        move->save_c = move->save_c + 1 + game->speed;
        display_crosshair(wind), sfRenderWindow_display(wind);
    }
    sfTexture_destroy(my_hit), sfTexture_destroy(background), move->h = game->h;
}

move_t draw_f2(sfRenderWindow *window, duck_t *duck, game_t *game, move_t *move)
{
    sfTexture *my_fall = sfTexture_createFromFile("pic/fall.png", NULL);
    sfTexture *back = sfTexture_createFromFile("pic/back2.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    sfSprite *my_sprite2 = sfSprite_create();
    sfSprite_setTexture(my_sprite2, my_fall, sfTrue);
    sfSprite_setTexture(my_spriteback, back, sfTrue);

    while (duck->y < 550) {
        sfRenderWindow_drawSprite(window, my_spriteback, NULL);
        sfVector2f pos = {duck->c, duck->y};
        sfSprite_setPosition(my_sprite2, pos);
        duck->y = duck->y + 7 + game->speed;
        sfRenderWindow_drawSprite(window, my_sprite2, NULL);
        display_font(window, game->result), display_life(window, game->life);
        game->h = display_duck(window, move->save_c, move->save_y, game);
        move->p_c2 = move->p_c2 + 1 + game->speed;
        move->save_c = move->save_c + 1 + game->speed;
        display_crosshair(window), sfRenderWindow_display(window);
    }
    sfTexture_destroy(my_fall), sfTexture_destroy(back), move->h = game->h;
}

game_t check_hit(sfRenderWindow *window, duck_t *duck, game_t *game)
{
    sfMusic *music;

    if (duck->c == -50) {
        game->result++;
        if (game->speed < 5 && game->result % 3 == 0)
            game->speed = game->speed + 1;
    }
    if (duck->c2 == -50) {
        game->result++;
        if (game->speed < 5 && game->result % 3 == 0)
            game->speed = game->speed + 1;
    }
}
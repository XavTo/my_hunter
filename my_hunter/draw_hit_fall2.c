/*
** EPITECH PROJECT, 2020
** draw hit fall
** File description:
** 2
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

int display_life(sfRenderWindow *window, int life)
{
    int g = 530;
    int d = 20;

    sfTexture *lifete = sfTexture_createFromFile("pic/life.png", NULL);
    sfSprite *my_life = sfSprite_create();
    sfVector2f lifepos = {d, g};
    sfSprite_setTexture(my_life, lifete, sfTrue);
    sfSprite_setPosition(my_life, lifepos);

    while (life != 0) {
        sfRenderWindow_drawSprite(window, my_life, NULL), life--, d = d + 70;
        sfVector2f lifepos = {d, g};
        sfSprite_setPosition(my_life, lifepos);
    }
    sfTexture_destroy(lifete), sfSprite_destroy(my_life);
    return (0);
}

void draw_hit_dck(sfRenderWindow *window, fduck_t *duck1, game_t *game, int j)
{
    sfTexture *my_hit = sfTexture_createFromFile("pic/hit.png", NULL);
    sfTexture *background = sfTexture_createFromFile("pic/back.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    sfSprite *my_sprite = sfSprite_create();
    sfSprite_setTexture(my_spriteback, background, sfTrue);
    sfSprite_setTexture(my_sprite, my_hit, sfTrue);

    while (duck1->y != j + 20) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spriteback, NULL);
        sfVector2f pos = {duck1->c, duck1->y};
        sfSprite_setPosition(my_sprite, pos);
        sfRenderWindow_drawSprite(window, my_sprite, NULL), duck1->y++;
        display_font(window, game->result);
        display_life(window, game->life);
        display_target(window, game->result);
        display_crosshair(window), sfRenderWindow_display(window);
    }
    sfTexture_destroy(my_hit), sfTexture_destroy(background);
    sfSprite_destroy(my_sprite), sfSprite_destroy(my_spriteback);
}

void draw_fall_duck(sfRenderWindow *window, fduck_t *duck1, game_t *game)
{
    sfTexture *my_fall = sfTexture_createFromFile("pic/fall.png", NULL);
    sfTexture *background = sfTexture_createFromFile("pic/back.png", NULL);
    sfSprite *my_spriteback = sfSprite_create();
    sfSprite *my_sprite2 = sfSprite_create();
    sfSprite_setTexture(my_sprite2, my_fall, sfTrue);
    sfSprite_setTexture(my_spriteback, background, sfTrue);

    while (duck1->y < 550) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, my_spriteback, NULL);
        sfVector2f pos = {duck1->c, duck1->y};
        duck1->y = duck1->y + 7 + game->speed;
        sfSprite_setPosition(my_sprite2, pos);
        sfRenderWindow_drawSprite(window, my_sprite2, NULL);
        display_font(window, game->result);
        display_life(window, game->life), display_target(window, game->result);
        display_crosshair(window), sfRenderWindow_display(window);
    }
    sfTexture_destroy(my_fall), sfTexture_destroy(background);
    sfSprite_destroy(my_sprite2), sfSprite_destroy(my_spriteback);
}

int display_font(sfRenderWindow *window, int result)
{
    int i = 0;
    char *test = malloc(sizeof(char) * 3);
    sfFont* font = sfFont_createFromFile("font/Games.ttf");
    sfText* text = sfText_create();
    sfFont* fres = sfFont_createFromFile("font/Games.ttf");
    sfText* fres2 = sfText_create();
    sfVector2f tpos = {550, 530};
    sfVector2f rpos = {735, 530};

    test[i] = '0' + result, i++;
    if (result > 9) {
        i = 0, test[i] = '0' + result / 10, i++;
        test[i] = '0' + result % 10, i++;
    }
    test[i] = '\0', sfText_setString(text, "Score :");
    sfText_setPosition(fres2, rpos), sfText_setCharacterSize(fres2, 50);
    sfText_setCharacterSize(text, 50), sfText_setPosition(text, tpos);
    sfText_setString(fres2, test), sfText_setFont(fres2, fres);
    sfText_setFont(text, font), sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_drawText(window, fres2, NULL), free(test);
}

int check_y_tooclose(duck_t *duck)
{
    if (duck->y2 + 50 >= duck->y && duck->y2 - 50 <= duck->y
        && duck->y + 200 < 520) {
        if (duck->c2 > duck->c) duck->y = duck->y + 200;
        else duck->y2 = duck->y2 + 200;
    }
    if (duck->y2 + 50 >= duck->y && duck->y2 - 50 <= duck->y
        && duck->y - 200 > 10) {
        if (duck->c2 > duck->c) duck->y = duck->y - 200;
        else duck->y2 = duck->y2- 200;
    }
}
/*
** EPITECH PROJECT, 2020
** display font
** File description:
** norme
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "struct.h"

int display_crosshair(sfRenderWindow *window);

char *trans_char2(char *res, int result)
{
    int i = 0;

    res[i] = '0' + result, i++;
    if (result > 9) {
        i = 0;
        res[i] = '0' + result / 10, i++;
        res[i] = '0' + result % 10, i++;
    }
    res[i] = '\0';
    return (res);
}

char *trans_char(char *high, int result, int *hs)
{
    int i = 0;

    if (result > *hs)
        *hs = result;
    high[i] = '0' + *hs, i++;
    if (*hs > 9) {
        i = 0;
        high[i] = '0' + *hs / 10, i++;
        high[i] = '0' + *hs % 10, i++;
    }
    high[i] = '\0';
    return (high);
}

void display_mytext(sfRenderWindow *window, char *high, char *res, char *sco)
{
    sfFont* font = sfFont_createFromFile("font/Games.ttf");
    sfText* text = sfText_create();

    sfText_setString(text, sco), sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfVector2f tpos = {150, 200};
    sfText_setPosition(text, tpos);
    sfRenderWindow_drawText(window, text, NULL), sfText_setString(text, res);
    sfVector2f fpos = {530, 200};
    sfText_setPosition(text, fpos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setCharacterSize(text, 75);
    sfText_setString(text, "High Score : ");
    sfVector2f hspos = {100, 400};
    sfText_setPosition(text, hspos);
    sfRenderWindow_drawText(window, text, NULL), sfText_setString(text, high);
    sfVector2f hsrpos = {560, 400};
    sfText_setPosition(text, hsrpos);
    sfRenderWindow_drawText(window, text, NULL);
    display_crosshair(window), sfRenderWindow_display(window);
}
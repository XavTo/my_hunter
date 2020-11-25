/*
** EPITECH PROJECT, 2020
** struct
** File description:
** all
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int c;
    int y;
} fduck_t;

typedef struct {
    int h;
    int sec;
    int result;
    int life;
    int hs;
    int speed;
    int dog;
} game_t;

typedef struct {
    int c;
    int y;
    int c2;
    int y2;
} duck_t;

typedef struct {
    int h;
    int j;
    int *p_c2;
    int *p_y2;
    int save_c;
    int save_y;
} move_t;

void split_2(fduck_t *duck1, game_t *game, sfRenderWindow *window, sfEvent e);
int check_y_tooclose(duck_t *duck);
int display_duck(sfRenderWindow *window, int c, int y, game_t *game);
void draw_fall_duck(sfRenderWindow *window, fduck_t *duck1, game_t *game);
int my_menu(sfRenderWindow *window, sfEvent event);
void draw_hit_dck(sfRenderWindow *window, fduck_t *duck1, game_t *game, int j);
int display_life(sfRenderWindow *window, int life);
sfText *my_vic(void);
sfText *my_los(void);
sfMusic *split_1(fduck_t *duck1, game_t *game, sfRenderWindow *wind, sfMusic *);
int my_level2(sfRenderWindow *window, int hs);
void my_lose(sfRenderWindow *window, sfEvent event);
int display_target(sfRenderWindow *window, int result);
int display_crosshair(sfRenderWindow *window);
int display_font(sfRenderWindow *window, int result);
void my_dog_sprite(sfRenderWindow *window, sfEvent event, int c, int h);
int my_level1(sfRenderWindow *window, int dog);
int my_dog_sprite2(sfRenderWindow *window, sfEvent event, int c, int h);
int display_4_dog(sfRenderWindow *window, int c, int y, int h);
int display_5_dog(sfRenderWindow *window, int c, int y, int h);
int display_6_dog(sfRenderWindow *window, int c, int y, int h);
int dog_run(sfRenderWindow *window, int c, int y, int h);
int display_third_dog(sfRenderWindow *window, int c, int y, int h);
int my_win(sfRenderWindow *window, sfEvent event);
duck_t check_e3(sfRenderWindow *window, sfEvent event, game_t *game, duck_t *);
duck_t check_e2(sfRenderWindow *window, sfEvent event, game_t *game, duck_t *);
game_t check_hit(sfRenderWindow *window, duck_t *duck, game_t *game);
void my_lose(sfRenderWindow *window, sfEvent event);
int my_final_score(sfRenderWindow *window, sfEvent event, int r, int h);
int check_e(sfRenderWindow *window, sfEvent event, fduck_t *duck1, game_t *);
move_t draw_hit(sfRenderWindow *window, duck_t *duck, game_t *game, move_t *);
move_t draw_hit2(sfRenderWindow *window, duck_t *duck, game_t *game, move_t *);
move_t draw_fall(sfRenderWindow *window, duck_t *duck, game_t *game, move_t *);
move_t draw_f2(sfRenderWindow *window, duck_t *duck, game_t *game, move_t *);
void display_mytext(sfRenderWindow *window, char *high, char *res, char *sco);
char *trans_char(char *high, int result, int *hs);
char *trans_char2(char *res, int result);
int split4(duck_t *duck, game_t *game, sfRenderWindow *window, sfEvent eve);
void split3(duck_t *duck, game_t *game, sfRenderWindow *window, sfEvent eve);

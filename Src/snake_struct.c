#include <stdlib.h> 
#include "snake_struct.h"


void insert_first(int x, int y, SnakePoint ** head, SnakePoint ** tail) {
    SnakePoint *new_point = (SnakePoint*) malloc(sizeof(SnakePoint));
    new_point->position.x = x;
    new_point->position.y = y;
    new_point->next = NULL;
    new_point->prev = NULL;

    if (*tail == NULL) {
        *tail = new_point;
    }

    if (head != NULL) {
        new_point->prev = *head;
        (*head)->next = new_point;
        *head = new_point;
    }
    *head = new_point;
}


void remove_last(SnakePoint ** tail) {
    SnakePoint * before_last = NULL;

    if (*tail == NULL) {
        return;
    }

    before_last = (*tail)->next;
    if (before_last != NULL) {
        before_last->prev = NULL;
    }
    free(*tail);
    *tail = before_last;
}


void init_snake(SnakePoint ** head, SnakePoint ** tail, int len, int point_size) {
    int y,
        x = WIDTH / 2;

    if (len > HEIGHT) {
        return;
    }

    for (y=0; y < len * point_size; y += point_size) {
        insert_first(x, y, head, tail);
    }
}

void add_snake_pixel(SnakePoint ** head, SnakePoint ** tail, Direction direction, int point_size) {
    int new_x = (*head)->position.x, 
        new_y = (*head)->position.y,
        current_x = (*head)->position.x,
        current_y = (*head)->position.y;

    switch(direction) {
        case TOP:
            new_y = current_y > 0 ? current_y - point_size : HEIGHT - point_size;
            break;
        case RIGHT:
            new_x = current_x < (WIDTH - point_size) ? current_x + point_size : 0;
            break;
        case BOTTOM:
            new_y = current_y < (HEIGHT - point_size) ? current_y + point_size : 0;
            break;
        case LEFT:
            new_x = current_x > 0 ? current_x - point_size : WIDTH - point_size;
            break;
    }
    insert_first(new_x, new_y, head, tail);
}







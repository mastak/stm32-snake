#include "main.h"

#define WIDTH 230
#define HEIGHT 310


typedef enum Direction {
  TOP,
  RIGHT,
  BOTTOM,
  LEFT
} Direction;


typedef struct Point {
    int x;
    int y;
} Point;


typedef struct SnakePointT {
    Point position;
    struct SnakePointT * next;
    struct SnakePointT * prev;
} SnakePoint;


void insert_first(int x, int y, SnakePoint ** head, SnakePoint ** tail);

void remove_last(SnakePoint ** tail);

void init_snake(SnakePoint ** head, SnakePoint ** tail, int len, int point_size);

void add_snake_pixel(SnakePoint ** head, SnakePoint ** tail, Direction direction, int point_size);

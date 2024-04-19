#ifndef MAPDATA_H
#define MAPDATA_H

typedef struct {
    char** map;
    int map_row;
    int map_col;
    int playerRow;
    int playerCol;
    int snakeRow;
    int snakeCol;
    int foodRow;
    int foodCol;
} MapData;

/* Function to initialize MapData structure with default values */
MapData initializeMapData();

#endif /* MAPDATA_H */
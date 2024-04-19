#include <stdio.h>
#include <stdlib.h>
#include "mapData.h"

/* Function to initialize MapData structure with default values */
MapData initializeMapData() {
    MapData mapData;

    mapData.map = NULL;
    mapData.map_row = 0;
    mapData.map_col = 0;
    mapData.playerRow = 0;
    mapData.playerCol = 0;
    mapData.snakeRow = 0;
    mapData.snakeCol = 0;
    mapData.foodRow = 0;
    mapData.foodCol = 0;

    return mapData;
}



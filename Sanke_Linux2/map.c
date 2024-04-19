/* All Map Functions Are Stored Here */

#include <stdio.h>
#include <stdlib.h>
#include "mapData.h"
#include "random.h"
#include "map.h"

#define MAX_ROWS 40
#define MAX_COLS 40
#define MIN_ROWS 5
#define MIN_COLS 5

/* Function to allocate memory for the map */
char** allocateMapMemory(int rows, int cols) {
    char** map = (char**)malloc(rows * sizeof(char*));
    if (map == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        map[i] = (char*)malloc(cols * sizeof(char));
        if (map[i] == NULL) {
            /* Memory allocation failed, free previously allocated memory */
            for (int j = 0; j < i; j++) {
                free(map[j]);
            }
            free(map);
            return NULL;
        }
    }

    return map;
}

/* Create Map Data */
MapData CreateMap(int argc, char* argv[]) {
    MapData mapData = initializeMapData();

    if(argc != 3){ /* Check Number of Argument are correct*/
        printf("Usage: %s <map_row> <map_col>\n", argv[0]);
        return mapData;
    }

    /* Parse command line argument */
    int map_row = atoi(argv[1]);
    int map_col = atoi(argv[2]);

    /* Check map is in relevant size*/
    if(map_row > MAX_ROWS || map_row < MIN_ROWS || map_col > MAX_COLS || map_col < MIN_COLS ){
        printf("Map size should be between 5x5 and 40x40.\n");
        return mapData;
    }

    /* Allocate memory for the map */
    char** gameMap = allocateMapMemory(map_row,map_col);
    if(gameMap == NULL){
        printf("Memory Allocation Failed");
        return mapData;
    }

    printf("Map created successfully. Size: %dx%d\n", map_row, map_col);

    /* Store map, map_row, map_col, player position, snake and food position in mapData structure */
    mapData.map = gameMap;
    mapData.map_row = map_row;
    mapData.map_col = map_col;
    mapData.playerRow = 0;
    mapData.playerCol = 0;
    mapData.snakeRow = map_row - 1;
    mapData.snakeCol = map_col - 1;
    initRandom();
    mapData.foodRow = randomUCP(1, map_row-2);
    mapData.foodCol = randomUCP(1, map_col-2);


    return mapData;
}

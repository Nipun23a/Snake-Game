#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "mapData.h"
#include "game.h"
#include "terminal.h"
#include "newSleep.h"

int main(int argc, char *argv[]) {
    MapData mapData;
    char action;

    mapData = CreateMap(argc,argv);
    if(mapData.map == NULL){
        return 1;
    }
           
    while(1){
        system("clear");
        printPlayArea(mapData.map, mapData.map_row, mapData.map_col, &mapData.playerRow, &mapData.playerCol, &mapData.snakeRow, &mapData.snakeCol,&mapData.foodRow,&mapData.foodCol);

        if (mapData.playerRow == mapData.snakeRow && mapData.playerCol == mapData.snakeCol) {
            printf("Game over! You lost.\n");
            exit(0);
        } else if (mapData.playerRow == mapData.foodRow && mapData.playerCol == mapData.foodCol) {
            printf("You won! You collected the food.\n");
            exit(0);
        }
        /* Disable input buffering */
        disableBuffer();

        /* Get the player's input immediately */
        if (scanf(" %c", &action) != 1) {
            printf("Error\n");
            break;
        }

        /* Re-enable input buffering */
        enableBuffer();
        playerMovement(mapData.map, mapData.map_row, mapData.map_col, &mapData.playerRow, &mapData.playerCol, action);
        newSleep(0.5);  
        snakeMovement(mapData.map,mapData.map_row,mapData.map_col,&mapData.snakeRow,&mapData.snakeCol,&mapData.playerRow,&mapData.playerCol,&mapData.foodCol,&mapData.foodRow);
    }
}
#ifndef GAME_H
#define GAME_H

void printPlayArea(char** map, int rows, int cols, int* playerRow, int* playerCol, int* snakeRow, int* snakeCol, int* foodRow, int* foodCol);
void playerMovement(char** map, int rows, int cols, int* playerRow, int* playerCol,char playerDirection);
void snakeMovement(char** map,int rows,int cols,int* snakeRow,int* snakeCol,int* playerRow,int* playerCol,int* foodCol,int* foodRow);
#endif /* GAME_H */
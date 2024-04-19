/* Game Functions Are Stored Here */
#include <stdio.h>
#include <stdlib.h>
#include "other.h"
#include "random.h"

void printPlayArea(char** map, int rows, int cols, int* playerRow, int* playerCol, int* snakeRow, int* snakeCol, int* foodRow, int* foodCol) {
    /* Upper Border */
    printBorderPattern(cols);

    /* Play Area Content */
    for (int i = 0; i < rows; i++) {
        printf("*");
        for (int j = 0; j < cols; j++) {
            if (i == *playerRow && j == *playerCol) {
                printf("P");
            } else if (i == *snakeRow && j == *snakeCol) {
                printf("~");
            } else if (i == *foodRow && j == *foodCol) {
                printf("@");
            } else {
                map[i][j] = ' ';
                printf("%c", map[i][j]);
            }
        }
        printf("*\n");
    }

    /* Print Bottom Border */
    printBorderPattern(cols);

    printf("Press 'w' key to move up\n");
    printf("Press 's' key to move down\n");
    printf("Press 'a' key to move left\n");
    printf("Press 'd' key to move right\n");
}

void playerMovement(char** map, int rows, int cols, int* playerRow, int* playerCol,char playerDirection) {
    /* Remove the player's previous location */
    map[*playerRow][*playerCol] = ' ';

    /* Update the player's position */
    switch (playerDirection) {
        case 'w':
            if (*playerRow > 0) {
                (*playerRow)--;
            }
            break;
        case 's':
            if (*playerRow < rows - 1) {
                (*playerRow)++;
            }
            break;
        case 'a':
            if (*playerCol > 0) {
                (*playerCol)--;
            }
            break;
        case 'd':
            if (*playerCol < cols - 1) {
                (*playerCol)++;
            }
            break;
        default:
            printf("Wrong Move");    
    }
}

void snakeMovement(char** map, int rows, int cols, int* snakeRow, int* snakeCol, int* playerRow, int* playerCol, int* foodRow, int* foodCol) {
    /* Remove the snake's previous location */
    map[*snakeRow][*snakeCol] = ' ';

    /* Determine the snake's new position */
    int newRow = *snakeRow;
    int newCol = *snakeCol;
    int distanceRow = abs(*snakeRow - *playerRow);
    int distanceCol = abs(*snakeCol - *playerCol);
    
    // Define a boolean flag to check if a valid move is made
    int checkMove = 0;

    while (!checkMove) {
        if (distanceRow == 1 && distanceCol == 0) {
            if (*snakeRow > *playerRow) {
                newRow = *snakeRow - 1;
            } else {
                newRow = *snakeRow + 1;
            }
        } else if (distanceRow == 0 && distanceCol == 1) {
            if (*snakeCol > *playerCol) {
                newCol = *snakeCol - 1;
            } else {
                newCol = *snakeCol + 1;
            }
        } else if (distanceRow == 1 && distanceCol == 1) {
            if (*snakeRow > *playerRow && *snakeCol > *playerCol) {
                newRow = *snakeRow - 1;
                newCol = *snakeCol - 1;
            } else if (*snakeRow > *playerRow && *snakeCol < *playerCol) {
                newRow = *snakeRow - 1;
                newCol = *snakeCol + 1;
            } else if (*snakeRow < *playerRow && *snakeCol > *playerCol) {
                newRow = *snakeRow + 1;
                newCol = *snakeCol - 1;
            } else {
                newRow = *snakeRow + 1;
                newCol = *snakeCol + 1;
            }
        } else {
            /* Move the snake randomly if it's not adjacent to the player */
            int direction = randomUCP(0, 7);
            switch (direction) {
                case 0:
                    newRow = *snakeRow - 1;
                    newCol = *snakeCol;
                    break;
                case 1:
                    newRow = *snakeRow + 1;
                    newCol = *snakeCol;
                    break;
                case 2:
                    newRow = *snakeRow;
                    newCol = *snakeCol - 1;
                    break;
                case 3:
                    newRow = *snakeRow;
                    newCol = *snakeCol + 1;
                    break;
                case 4:
                    newRow = *snakeRow - 1;
                    newCol = *snakeCol - 1;
                    break;
                case 5:
                    newRow = *snakeRow - 1;
                    newCol = *snakeCol + 1;
                    break;
                case 6:
                    newRow = *snakeRow + 1;
                    newCol = *snakeCol - 1;
                    break;
                case 7:
                    newRow = *snakeRow + 1;
                    newCol = *snakeCol + 1;
                    break;
            }
        }

        /* Check if the new position is within the map boundaries and not the food position */
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && (newRow != *foodRow || newCol != *foodCol)) {
            checkMove = 1; // Set flag to indicate a valid move
            *snakeRow = newRow;
            *snakeCol = newCol;
            map[*snakeRow][*snakeCol] = '~';
        } else {
            /* Keep the snake in its previous position */
            map[*snakeRow][*snakeCol] = '~';
        }
    }
}



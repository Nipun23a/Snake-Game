#ifndef MAP_H
#define MAP_H
#include "mapData.h"

char** allocateMapMemory(int rows, int cols);
MapData CreateMap(int argc, char* argv[]);

#endif /* MAP_H */
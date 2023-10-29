#ifndef MAP_SONG_H
#define MAP_SONG_H

#include "../boolean.h"
#include "../../function.h"
#include "../listadt.h"

void CreateEmptyMapSong(MapSong *M);
void InsertSong(MapSong *M, Song s);
int FindSong(MapSong M, char songName[]);

#endif

#ifndef MAP_SONG_H
#define MAP_SONG_H

#include "../boolean.h"
#include "../../function.h"

#define NilMapSong 0
#define UndefinedMapSong -999
#define MaxSongs 100

typedef struct {
    int id;
    char songName[100];
    int albumID;   // ID album tempat lagu ini berasal
} Song;

typedef struct {
    Song songs[MaxSongs];
    int Neff;   // Jumlah lagu sebenarnya
} MapSong;

void CreateEmptyMapSong(MapSong *M);
void InsertSong(MapSong *M, Song s);
int FindSong(MapSong M, char songName[]);

#endif

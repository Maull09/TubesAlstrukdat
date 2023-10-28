#ifndef MAP_ALBUM_H
#define MAP_ALBUM_H

#include "../boolean.h"
#include "map_song.h"
#include "../../function.h"

#define NilMapAlbum 0
#define Undefined -999
#define MaxAlbums 100

typedef struct {
    int id;
    char albumName[255];
    int singerID;  // ID penyanyi yang memiliki album ini
} Album;

typedef struct {
    Album albums[MaxAlbums];
    int Neff;   // Jumlah album sebenarnya
} MapAlbum;

void CreateEmptyMapAlbum(MapAlbum *M);
void InsertAlbum(MapAlbum *M, Album a);
int FindAlbum(MapAlbum M, char albumName[]);

#endif

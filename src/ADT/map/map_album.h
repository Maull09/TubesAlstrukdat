#ifndef MAP_ALBUM_H
#define MAP_ALBUM_H

#include "../boolean.h"
#include "map_song.h"
#include "../../function.h"
#include "../listadt.h"

void CreateEmptyMapAlbum(MapAlbum *M);
void InsertAlbum(MapAlbum *M, Album a);
int FindAlbum(MapAlbum M, char albumName[]);

#endif

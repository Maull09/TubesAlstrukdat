#ifndef MAP_ALBUM_H
#define MAP_ALBUM_H

#include "../boolean.h"
#include "map_song.h"
#include "../../function.h"
#include "../listadt.h"


void CreateEmptyMapAlbum(MapAlbumSinger *M);
void CreateEmptyListMapAlbum(ListMapAlbum *LM);
void InsertListMapAlbum(ListMapAlbum *MA, MapAlbumSinger M);
void InsertAlbum(MapAlbumSinger *M, Album a);
boolean FindAlbum(MapAlbumSinger M, char albumName[]);
void DisplayMapAlbum(MapAlbumSinger M);
void DisplayListMapAlbum(ListMapAlbum LM);

#endif

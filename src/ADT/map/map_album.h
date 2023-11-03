#ifndef MAP_ALBUM_H
#define MAP_ALBUM_H

#include "../boolean.h"
#include "map_song.h"
#include "../../function.h"
#include "../listadt.h"


void CreateEmptyMapAlbum(MapAlbum *M);
void CreateEmptyListMapAlbum(ListMapAlbum *LM);
void InsertListMapAlbum(ListMapAlbum *MA, MapAlbum M);
void InsertAlbum(MapAlbum *M, Album a);
boolean FindAlbum(MapAlbum M, char albumName[]);
void DisplayMapAlbum(MapAlbum M);
void DisplayListMapAlbum(ListMapAlbum *LM, char singername[]);

#endif

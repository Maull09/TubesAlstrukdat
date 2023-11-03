#ifndef MAP_SONG_H
#define MAP_SONG_H

#include "../boolean.h"
#include "../../function.h"
#include "../listadt.h"


void CreateEmptyMapSong(MapSong *M);
void CreateEmptyListMapSong(ListMapSong *LM);
void InsertSong(MapSong *M, Song s);
void InsertListMapSong(ListMapSong *LM, MapSong M);
boolean FindSong(MapSong, char songName[]);
void DisplayMapSong(MapSong M);
void DisplayListMapSong_Name(ListMapSong *LM, char albumname[]);
void DisplayListMapSong(ListMapSong *LM);

#endif


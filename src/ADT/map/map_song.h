#ifndef MAP_SONG_H
#define MAP_SONG_H

#include "../boolean.h"
#include "../../function.h"
#include "../listadt.h"


void CreateEmptyMapSong(MapSongAlbum *M);
void CreateEmptyListMapSong(ListMapSong *LM);
void InsertSong(MapSongAlbum *M, Song s);
void InsertListMapSong(ListMapSong *LM, MapSongAlbum M);
boolean FindSong(MapSongAlbum M, char songName[]);
void DisplayMapSong(MapSongAlbum M);
void DisplayListMapSong(ListMapSong LM);

#endif
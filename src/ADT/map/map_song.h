#ifndef MAP_SONG_H
#define MAP_SONG_H

#include "../boolean.h"
#include "../../function.h"
#include "../listadt.h"
#include "../set/set.h"

void CreateEmptyMapSong(MapSong *M);
void CreateEmptyListMapSong(ListMapSong *LM);
void InsertSong(MapSong *M, Song s);
void InsertListMapSong(ListMapSong *LM, MapSong M);
boolean FindSongAlbumName(ListMapSong LM, char albumName[]);
void DisplayMapSong(MapSong M);
void DisplayListMapSong_Name(ListMapSong *LM, char albumname[]);
void DisplayListMapSong(ListMapSong *LM);
void FindSong_AlbumName(ListMapSong LM, char albumName[]);
void FindSong_IDsong(ListMapSong LM, char albumName[], int idx, Lagu *play);
void CreateLagu(Lagu *infolagu);
boolean valid_idsong(ListMapSong LM, int idx, char albumName[]);
#endif


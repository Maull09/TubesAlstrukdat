#ifndef CONSOLE_H
#define CONSOLE_H

// Deklarasi module dasar
#include <stdio.h>
#include <stdlib.h>

//ADT
#include "ADT/mesin_karakter/mesinkarakter.h"
#include "ADT/mesin_kata/mesinkata.h"
#include "ADT/mesin_input/mesininput.h"
#include "ADT/mesin_kalimat/mesinkalimat.h"
#include "ADT/queue/queue.h"
#include "ADT/set/set.h"
#include "ADT/stack/stack.h"
#include "ADT/linkedlist/linkedlist.h"
#include "ADT/arraystatis/arraySinger.h"
#include "ADT/map/map_album.h"
#include "ADT/map/map_song.h"
#include "ADT/arraydin/arrayplaylist.h"

// Fungsi
void menu();

void welcome();

void help(boolean sesi);

void delay(int number_of_seconds);

void invcommand();

void FUNCSTART();

void EndInput();

void Load(char * filename,ListSinger *DaftarPenyanyi, MapAlbum *SingerAlbum, MapSong *SongAlbum, ListMapAlbum *KumpulanAlbumSinger, ListMapSong *KumpulanLaguAlbum, SetSong *KumpulanLagu, QueueLagu *qLagu, StackSong *sLagu, ArrayPlaylists *arrPlaylist, boolean *adafile, Lagu *cSong);
void ListDefault(ListSinger *listpenyanyi, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong);
void PlaySong(ListSinger *listpenyanyi, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, Lagu *putar, QueueLagu *qLagu, StackSong *sLagu);
void QueueSong(ListSinger *listpenyanyi, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, QueueLagu *qSong);
void STATUS(Lagu *playing, QueueLagu *antrian, ArrayPlaylists *arrPlaylists);
void enhance(ListSinger *DaftarPenyanyi, ListMapAlbum *LMA, ListMapSong *LMS, ArrayPlaylists *arrplaylist, char namaplaylist[]);
boolean playlist_valid(ArrayPlaylists *arrPlaylist, char nameplaylist[]);
void PlayPlaylist(ArrayPlaylists *arrPlaylist, StackSong *sLagu, QueueLagu *qLagu, int idxarr);
void QueuePlaylist(ArrayPlaylists *arrPlaylist, QueueLagu *qLagu, int idxarr);
void PlaylistCreate(ArrayPlaylists *arrPlaylist, char playlistname[]);
void PlaylistDelete(ArrayPlaylists *arrPlaylist, int idxP);
void PlaylistRemove(ArrayPlaylists *arrPlaylist, int idxP, int idxL);
void playlistSwap(ArrayPlaylists *arrP, int idx, int idy, int idPlaylist);
void playlistAddAlbum(ArrayPlaylists *arr, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, ListSinger *listpenyanyi);
void playlistAddSong(ArrayPlaylists *arr, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, ListSinger *listpenyanyi);
int playlistContainingQueue(QueueLagu *q, ArrayPlaylists *arrPlaylists);


#endif
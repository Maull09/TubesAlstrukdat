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

void help();

void delay(int number_of_seconds);

void invcommand();

void FUNCSTART();

void EndInput();

void Load(char * filename,ListSinger *DaftarPenyanyi, MapAlbum *SingerAlbum, MapSong *SongAlbum, ListMapAlbum *KumpulanAlbumSinger, ListMapSong *KumpulanLaguAlbum, SetSong *KumpulanLagu, QueueLagu *qLagu, StackSong *sLagu, ArrayPlaylists *arrPlaylist, List *linkedPlaylist);
#endif
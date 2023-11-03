// File : arrayplaylist.h
#ifndef ARRAYPLAYLIST_H
#define ARRAYPLAYLIST_H

#include <stdlib.h>
#include "../linkedlist/linkedlist.h"
#include "../listadt.h"

/* ********** PROTOTYPE ********** */
/* *** Konstruktor/Kreator *** */
void CreateEmptyArrayPlaylists(ArrayPlaylists *arr);

/* *** Destruktor *** */
void DeallocateArrayPlaylists(ArrayPlaylists *arr);

/* *** Manajemen Kapasitas Array *** */
void ExpandArrayPlaylists(ArrayPlaylists *arr);  // Menggandakan kapasitas array playlists

/* *** Operasi-operasi Playlist *** */
void AddPlaylist(ArrayPlaylists *arr, Playlist p);
boolean FindPlaylist(ArrayPlaylists arr, int idx);
void DeletePlaylist(ArrayPlaylists *arr, int idx);
void DisplayPlaylist(ArrayPlaylists *arr);

#endif

// File : arrayplaylist.h
#ifndef ARRAYPLAYLIST_H
#define ARRAYPLAYLIST_H

#include "../boolean.h"
#include <stdlib.h>
#include "../../function.h"
#include "../linkedlist/linkedlist.h"
#include "../listadt.h"


/* ********** PROTOTYPE ********** */
/* *** Konstruktor/Kreator *** */
void CreateEmptyArrayPlaylists(ArrayPlaylists *arr);
void CreatePlaylist(Playlist *p, char name[], int id);

/* *** Destruktor *** */
void DeallocateArrayPlaylists(ArrayPlaylists *arr);

/* *** Manajemen Kapasitas Array *** */
void ExpandArrayPlaylists(ArrayPlaylists *arr);  // Menggandakan kapasitas array playlists

/* *** Operasi-operasi lain *** */
void AddPlaylist(ArrayPlaylists *arr, Playlist p);
int FindPlaylist(ArrayPlaylists arr, char name[]);

#endif

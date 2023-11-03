#include "arrayplaylist.h"
#include <stdio.h>
#include <string.h>

/* *** Konstruktor/Kreator *** */
void CreateEmptyArrayPlaylists(ArrayPlaylists *arr) {
    arr->playlists = (Playlist *) malloc(INIT_SIZE * sizeof(Playlist));
    arr->Neff = 0;
    arr->capacity = INIT_SIZE;
}

/* *** Destruktor *** */
void DeallocateArrayPlaylists(ArrayPlaylists *arr) {
    free(arr->playlists);
    arr->Neff = 0;
    arr->capacity = 0;
}

/* *** Manajemen Kapasitas Array *** */
void ExpandArrayPlaylists(ArrayPlaylists *arr) {
    int newCapacity = arr->capacity * 2;
    arr->playlists = (Playlist *) realloc(arr->playlists, newCapacity * sizeof(Playlist));
    arr->capacity = newCapacity;
}

/* *** Operasi-operasi Playlist *** */
void AddPlaylist(ArrayPlaylists *arr, Playlist p) {
    if (arr->Neff == arr->capacity) {
        ExpandArrayPlaylists(arr);
    }
    arr->playlists[arr->Neff] = p;
    arr->Neff++;
}

boolean FindPlaylist(ArrayPlaylists arr, int idx) {
    return (idx >= 0 && idx < arr.Neff);
}

void DeletePlaylist(ArrayPlaylists *arr, int idx) {
    if (FindPlaylist(*arr, idx)) {
        for (int i = idx; i < arr->Neff - 1; i++) {
            arr->playlists[i] = arr->playlists[i + 1];
        }
        arr->Neff--;
    }
}

void DisplayPlaylist(ArrayPlaylists arr) {
    for (int i = 0; i < arr.Neff; i++) {
        printf("Playlist Name: %s\n", arr.playlists[i].name);
        DisplaySongs(arr.playlists[i].laguplaylist);
    }
}

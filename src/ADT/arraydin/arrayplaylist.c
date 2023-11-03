#include "arrayplaylist.h"
#include <stdio.h>
#include <string.h>

/* *** Konstruktor/Kreator *** */
void CreateEmptyArrayPlaylists(ArrayPlaylists *arr) {
    arr->playlists = (Playlist*) malloc(INIT_SIZE * sizeof(Playlist));
    arr->Neff = 0;
    arr->capacity = INIT_SIZE;
}

/* *** Destruktor *** */
void DeallocateArrayPlaylists(ArrayPlaylists *arr) {
    free(arr->playlists);
}

/* *** Manajemen Kapasitas Array *** */
void ExpandArrayPlaylists(ArrayPlaylists *arr) {
    int newCapacity = arr->capacity * 2;
    arr->playlists = (Playlist*) realloc(arr->playlists, newCapacity * sizeof(Playlist));
    arr->capacity = newCapacity;
}

/* *** Operasi-operasi lain *** */
void AddPlaylist(ArrayPlaylists *arr, Playlist p) {
    if (arr->Neff == arr->capacity) {
        ExpandArrayPlaylists(arr);
    }
    arr->playlists[arr->Neff] = p;
    arr->Neff++;
}

boolean FindPlaylist(ArrayPlaylists arr, char name[]) {
    for (int i = 0; i < arr.Neff; i++) {
        if (StringSama(arr.playlists[i].name, name)) {
            return true;
        }
    }
    return false;
}

void DisplayPlaylist(ArrayPlaylists arrPlaylist) {
    printf("Daftar playlist yang kamu miliki:\n");
    for (int i = 0; i < arrPlaylist.Neff; i++) {
        printf("\t%d. %s\n",i+1, arrPlaylist.playlists[i].name);
    }
}

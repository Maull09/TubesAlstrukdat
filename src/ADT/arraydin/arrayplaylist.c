#include "arrayplaylist.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateEmptyArrayPlaylists(ArrayPlaylists *arr) {
    arr->playlists = NULL;
    arr->Neff = 0;
    arr->capacity = 0;
}

void CreatePlaylist(Playlist *p, char name[], int id) {
    SalinString(p->name, name);
    p->id = id;
    p->songs.First = NULL;  // Initializing empty linked list
}

/* *** Destruktor *** */
void DeallocateArrayPlaylists(ArrayPlaylists *arr) {
    for (int i = 0; i < arr->Neff; i++) {
        // function to deallocate linked list
        Dealokasi((&arr->playlists[i].songs.First));
    }
    free(arr->playlists);
    arr->playlists = NULL;
    arr->Neff = 0;
    arr->capacity = 0;
}

/* *** Manajemen Kapasitas Array *** */
void ExpandArrayPlaylists(ArrayPlaylists *arr) {
    arr->capacity = (arr->capacity == 0) ? 1 : arr->capacity * 2; 
    Playlist *newArr = realloc(arr->playlists, arr->capacity * sizeof(Playlist));
    
    if (newArr == NULL) {
        printf("Failed to expand the array!\n");
        exit(1);  // or handle memory allocation failure appropriately
    }
    
    arr->playlists = newArr;
}

/* *** Operasi-operasi lain *** */
void AddPlaylist(ArrayPlaylists *arr, Playlist p) {
    if (arr->Neff == arr->capacity) {
        ExpandArrayPlaylists(arr);
    }

    arr->playlists[arr->Neff] = p;
    arr->Neff++;
}

int FindPlaylist(ArrayPlaylists arr, char name[]) {
    for (int i = 0; i < arr.Neff; i++) {
        if (StringSama(arr.playlists[i].name, name)) {
            return i; 
        }
    }
    return -1;
}


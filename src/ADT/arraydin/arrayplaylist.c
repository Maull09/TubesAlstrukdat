#include "arrayplaylist.h"

void CreateEmptyArrayPlaylists(ArrayPlaylists *arr) {
    arr->playlists = (Playlist *)malloc(INIT_SIZE * sizeof(Playlist));
    arr->Neff = 0;
    arr->capacity = INIT_SIZE;
}

void CreatePlaylist(Playlist *p, char name[], int id) {
    SalinString(p->name, name);
    p->id = id;
}

void DeallocateArrayPlaylists(ArrayPlaylists *arr) {
    free(arr->playlists);
    arr->Neff = 0;
    arr->capacity = 0;
}

void ExpandArrayPlaylists(ArrayPlaylists *arr) {
    arr->capacity *= 2;
    arr->playlists = (Playlist *)realloc(arr->playlists, arr->capacity * sizeof(Playlist));
}

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
    return -1;  // Tidak ditemukan
}

#include "map_album.h"

void CreateEmptyMapAlbum(MapAlbum *M) {
    M->Neff = 0;
}

void InsertAlbum(MapAlbum *M, Album a) {
    if (M->Neff < MaxAlbums) {
        M->albums[M->Neff] = a;
        M->Neff++;
    }
}

int FindAlbum(MapAlbum M, char albumName[]) {
    for (int i = 0; i < M.Neff; i++) {
        if (StringSama(M.albums[i].albumName, albumName)) {
            return i;
        }
    }
    return Undefined;  // tidak ditemukan
}

#include "map_album.h"
#include <stdio.h>

void CreateEmptyMapAlbum(MapAlbumSinger *M) {
    M->Neff = 0;
}

void CreateEmptyListMapAlbum(ListMapAlbum *LM) {
    LM->Neff = 0;
}

void InsertListMapAlbum(ListMapAlbum *LM, MapAlbumSinger M) {
    if (LM->Neff < 100) {
        LM->MapAlbums[LM->Neff] = M;
        LM->Neff++;
    }
}

void InsertAlbum(MapAlbumSinger *M, Album a) {
    if (M->Neff < MaxAlbums) {
        M->albums[M->Neff] = a;
        M->Neff++;
    }
}

boolean FindAlbum(MapAlbumSinger M, char albumName[]) {
    for (int i = 0; i < M.Neff; i++) {
        if (StringSama(M.albums[i].albumName, albumName)) {
            return true;
        }
    }
    return false;
}

void DisplayMapAlbum(MapAlbumSinger M) {
    printf("Singer Name: %s\n", M.SingerName);
    for (int i = 0; i < M.Neff; i++) {
        printf("- %s\n", M.albums[i].albumName);
    }
}

void DisplayListMapAlbum(ListMapAlbum LM) {
    for (int i = 0; i < LM.Neff; i++) {
        printf("MapAlbumSinger #%d:\n", i + 1);
        DisplayMapAlbum(LM.MapAlbums[i]);
        printf("\n");
    }
}

#include "map_album.h"
#include <stdio.h>

void CreateEmptyMapAlbum(MapAlbum *M) {
    M->Neff = 0;
}

void CreateEmptyListMapAlbum(ListMapAlbum *LM) {
    LM->Neff = 0;
}

void InsertListMapAlbum(ListMapAlbum *LM, MapAlbum M) {
    if (LM->Neff < 100) {
        LM->MapAlbums[LM->Neff] = M;
        LM->Neff++;
    }
}

void InsertAlbum(MapAlbum *M, Album a) {
    if (M->Neff < MaxAlbums) {
        M->albums[M->Neff] = a;
        M->Neff++;
    }
}

boolean FindAlbum(MapAlbum M, char albumName[]) {
    for (int i = 0; i < M.Neff; i++) {
        if (StringSama(M.albums[i].albumName, albumName)) {
            return true;
        }
    }
    return false;
}

void DisplayMapAlbum(MapAlbum M) {
    printf("Daftar Album oleh %s : \n", M.SingerName);
    for (int i = 0; i < M.Neff; i++) {
        printf("\t%d. %s\n",i+1, M.albums[i].albumName);
    }
}

void DisplayListMapAlbum(ListMapAlbum *LM, char singername[]) {
    int i;
    for (int i = 0; i < LM->Neff; i++) {
        if (singername[i] == M.SingerName[i]){
            printf("MapAlbumSinger #%d:\n", i + 1);
            DisplayMapAlbum(LM->MapAlbums[i]);
            printf("\n");
        }
    }
    LM->MapAlbums[i]->SingerName;

    
}


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


boolean FindAlbumSingerName(ListMapAlbum LM, char singerName[]) {
    for (int i = 0; i < LM.Neff; i++) {
        if (StringSama(LM.MapAlbums[i].SingerName, singerName)) {
            return true;
        }
    }
    return false;
}

void FindAlbum_SingerName(ListMapAlbum LM, char singerName[]) {
    for (int i = 0; i < LM.Neff; i++) {
        if (StringSama(LM.MapAlbums[i].SingerName, singerName)) {
            DisplayMapAlbum(LM.MapAlbums[i]);
        }
    }
}


void DisplayMapAlbum(MapAlbum M) {
    printf("Daftar Album oleh %s : \n", M.SingerName);
    for (int i = 0; i < M.Neff; i++) {
        printf("\t%d. %s\n",i+1, M.albums[i].albumName);
    }
}

void DisplayListMapAlbum(ListMapAlbum *LM) {
    for (int i = 0; i < LM->Neff; i++) {
        printf("MapAlbumSinger #%d:\n", i + 1);
        DisplayMapAlbum(LM->MapAlbums[i]);
        printf("\n");
    }
}

void DisplayListMapAlbum_Name(ListMapAlbum *LM, char singername[]) {
    int i;
    for (int i = 0; i < LM->Neff; i++) {
        if(StringSama(LM->MapAlbums[i].SingerName, singername)){
            DisplayMapAlbum(LM->MapAlbums[i]);
        }
    }
}

int idAlbum(ListMapAlbum *LM, char album[]){
    boolean found = false;
    int idx = 0;
    while(idx < LM->Neff && !found){
        if(StringSama(LM->MapAlbums, album)){
            found = true;
        }
        idx++;
    }
    return idx;
}
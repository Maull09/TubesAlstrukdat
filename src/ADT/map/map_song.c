#include "map_song.h"
#include <stdio.h>

void CreateEmptyMapSong(MapSong *M) {
    M->albumName[0] = '\0'; 
    CreateEmptySet(&M->songs);
}

void CreateEmptyListMapSong(ListMapSong *LM) {
    LM->Neff = 0;
}

void InsertSong(MapSong *M, Song s) {
    if (M->songs.Neff< MaxSetSongs) {
        M->songs.songs[M->songs.Neff] = s;
        M->songs.Neff++;
    }
}

void InsertListMapSong(ListMapSong *LM, MapSong M) {
    if (LM->Neff < 100) {
        LM->MapSongs[LM->Neff] = M;
        LM->Neff++;
    }
}

boolean FindSongAlbumName(ListMapSong LM, char albumName[]) {
    for (int i = 0; i < LM.Neff; i++) {
        if (StringSama(LM.MapSongs[i].albumName, albumName)) {
            return true;
        }
    }
    return false;
}

void FindSong_AlbumName(ListMapSong LM, char albumName[]) {
    for (int i = 0; i < LM.Neff; i++) {
        if (StringSama(LM.MapSongs[i].albumName, albumName)) {
            DisplayMapSong(LM.MapSongs[i]);
        }
    }
}

void DisplayMapSong(MapSong M) {
    printf("Daftar Lagu di %s: \n", M.albumName);
    for (int i = 0; i < M.songs.Neff; i++) {
        printf("\t%d. %s\n",i+1, M.songs.songs[i].songName);
    }
}

void DisplayListMapSong(ListMapSong *LM) {
    for (int i = 0; i < LM->Neff; i++) {
        printf("MapSongAlbum #%d:\n", i + 1);
        DisplayMapSong(LM->MapSongs[i]);
        printf("\n");
    }
}

void DisplayListMapSong_Name(ListMapSong *LM, char albumname[]) {
    for (int i = 0; i < LM->Neff; i++) {
        if (StringSama(LM -> MapSongs[i].albumName, albumname)){
            DisplayMapSong(LM->MapSongs[i]);
        }
    }
}

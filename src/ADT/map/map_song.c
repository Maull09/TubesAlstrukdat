#include "map_song.h"
#include <stdio.h>

void CreateEmptyMapSong(MapSong *M) {
    M->Neff = 0;
}

void CreateEmptyListMapSong(ListMapSong *LM) {
    LM->Neff = 0;
}

// void InsertSong(MapSong *M, Song s) {
//     if (M->Neff < MaxSongs) {
//         M->songs.songs[]->songName = s;
//         M->Neff++;
//     }
// }

void InsertListMapSong(ListMapSong *LM, MapSong M) {
    if (LM->Neff < 100) {
        LM->MapSongs[LM->Neff] = M;
        LM->Neff++;
    }
}

boolean FindSong(MapSong M, char songName[]) {
    for (int i = 0; i < M.Neff; i++) {
        if (StringSama(M.songs.songs[i].songName, songName)) {
            return true;
        }
    }
    return false;
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

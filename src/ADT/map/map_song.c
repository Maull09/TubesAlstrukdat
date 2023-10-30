#include "map_song.h"
#include <stdio.h>

void CreateEmptyMapSong(MapSongAlbum *M) {
    M->Neff = 0;
}

void CreateEmptyListMapSong(ListMapSong *LM) {
    LM->Neff = 0;
}

void InsertSong(MapSongAlbum *M, Song s) {
    if (M->Neff < MaxSongs) {
        M->songs[M->Neff] = s;
        M->Neff++;
    }
}

void InsertListMapSong(ListMapSong *LM, MapSongAlbum M) {
    if (LM->Neff < 100) {
        LM->MapSongs[LM->Neff] = M;
        LM->Neff++;
    }
}

boolean FindSong(MapSongAlbum M, char songName[]) {
    for (int i = 0; i < M.Neff; i++) {
        if (StringSama(M.songs[i].songName, songName)) {
            return true;
        }
    }
    return false;
}

void DisplayMapSong(MapSongAlbum M) {
    printf("Album Name: %s\n", M.albumName);
    for (int i = 0; i < M.Neff; i++) {
        printf("- %s\n", M.songs[i].songName);
    }
}

void DisplayListMapSong(ListMapSong LM) {
    for (int i = 0; i < LM.Neff; i++) {
        printf("MapSongAlbum #%d:\n", i + 1);
        DisplayMapSong(LM.MapSongs[i]);
        printf("\n");
    }
}

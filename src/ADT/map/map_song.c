#include "map_song.h"

void CreateEmptyMapSong(MapSong *M) {
    M->Neff = 0;
}

void InsertSong(MapSong *M, Song s) {
    if (M->Neff < MaxSongs) {
        M->songs[M->Neff] = s;
        M->Neff++;
    }
}

int FindSong(MapSong M, char songName[]) {
    for (int i = 0; i < M.Neff; i++) {
        if (StringSama(M.songs[i].songName, songName)) {
            return i;
        }
    }
    return UndefinedMapSong;  // tidak ditemukan
}

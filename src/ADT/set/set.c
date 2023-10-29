#include "set.h"
#include <string.h>

// Menginisialisasi set lagu
void CreateEmptySet(SetSong *S) {
    S->Neff = 0;
}

// Menambahkan lagu ke dalam set (hanya jika lagu belum ada dalam set)
void AddSongToSet(SetSong *S, Song song) {
    if (!IsSongInSet(*S, song.songName)) {
        if (S->Neff < MaxSetSongs) {
            S->songs[S->Neff] = song;
            S->Neff++;
        }
    }
}

// Mengecek apakah lagu ada dalam set
boolean IsSongInSet(SetSong S, char *songName) {
    for (int i = 0; i < S.Neff; i++) {
        if (StringSama(S.songs[i].songName, songName)) {
            return true;
        }
    }
    return false;
}


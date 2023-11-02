#include "set.h"
#include <stdio.h>

// *** Konstruktor ***
void CreateEmptySet(SetSong *S) {
    S->Neff = 0;
}


// *** Penambahan Lagu ke Set ***
void AddSongToSet(SetSong *S, Song song) {
    if (S->Neff < MaxSetSongs) { 
        S->songs[S->Neff] = song;
        S->Neff++;
    }
}

// *** Pengecekan Lagu dalam Set ***
boolean IsSongInSet(SetSong S, char *songName) {
    for (int i = 0; i < S.Neff; i++) {
        if (StringSama(S.songs[i].songName, songName)) {
            return true;
        }
    }
    return false;
}

// *** Penambahan Set ke List ***
void AddSetSongToMapSong(MapSong *list, SetSong setsong) {
    if (list->Neff < 100) {
        list->songs = setsong;
        list->Neff++;
    }
}

// *** Menampilkan Isi dari SetSong ***
void DisplaySetSong(SetSong S) {
    for (int i = 0; i < S.Neff; i++) {
        printf("- %s\n", S.songs[i].songName);
    }
}




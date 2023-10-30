#include "set.h"
#include <stdio.h>

// *** Konstruktor ***
void CreateEmptySet(SetSong *S) {
    S->Neff = 0;
    SalinString(S->albumName, ""); 
}

void CreateEmptyListSet(ListofSetSong *S) {
    S->Songs->Neff = 0;
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
void AddSetSongToListSetSong(ListofSetSong *list, SetSong setsong) {
    if (list->Neff < 100) {
        list->Songs[list->Neff] = setsong;
        list->Neff++;
    }
}

// *** Menampilkan Isi dari SetSong ***
void DisplaySetSong(SetSong S) {
    printf("Album Name: %s\n", S.albumName);
    for (int i = 0; i < S.Neff; i++) {
        printf("- %s\n", S.songs[i].songName);
    }
}

// *** Menampilkan Isi dari ListofSetSong ***
void DisplayListOfSetSong(ListofSetSong list) {
    for (int i = 0; i < list.Neff; i++) {
        printf("Set #%d:\n", i + 1);
        DisplaySetSong(list.Songs[i]);
        printf("\n");
    }
}


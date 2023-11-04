#include "map_song.h"
#include <stdio.h>

void CreateLagu(Lagu *infolagu) {
    SalinString(infolagu->album, "\0"); 
    SalinString(infolagu->artist, "\0");  
    SalinString(infolagu->titlesong, "\0");  
}

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

void FindSong_IDsong(ListMapSong LM, char albumName[], int idx, Lagu *play) {
    for (int i = 0; i < LM.Neff; i++) {
        if (StringSama(LM.MapSongs[i].albumName, albumName)) {
            SalinString(play->titlesong, LM.MapSongs[i].songs.songs[idx-1].songName);
        }
    }
}

boolean valid_idsong(ListMapSong LM, int idx, char albumName[]){
    for (int i = 0; i < LM.Neff; i++) {
        if (StringSama(LM.MapSongs[i].albumName, albumName)) {
            return (idx >= 1 && idx < LM.MapSongs[i].songs.Neff);
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


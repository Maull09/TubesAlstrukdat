#include <stdio.h>
#include "playlist.h"




void playlistCreate(){
    ArrayPlaylists p;
    Playlist playlist;
    printf("Masukkan nama playlist yang ingin dibuat : ");
    char name[225];
    fgets(name, sizeof(name), stdin);
    char *lenName = name;
    while(*lenName == ' ' || *lenName == '\t'){
        lenName++;
    }
    size_t len = strlen(lenName);
    CreateEmptyPlaylists(&p);
    if (len >= 3){

        printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!", name);
        AddPlaylist(&p, playlist);
    }
    else{
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

void playlistAdd(ArrayPlaylists arrPlaylist){
    printf("Daftar Penyanyi :\n");
    DisplayPlaylist(arrPlaylist);
    
}
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

void playlistAdd(ArrayPlaylists arrPlaylist, ListSinger LS, MapAlbum M, int pilihan){
    displaySinger(LS);
    char name[225];
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    fscanf("%s", &name); // input masih diperbincangkan
    displaySinger(LS);
    if(pilihan == 1){
        if (!FindSinger(LS, name)){
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.", name);
        }
        else{

            DisplayMapAlbum(M);
            printf("Masukkan Judul Album yang dipilih : ");
            fscanf("%s", &name); // input masih diperbincanglan
            if(!FindAlbum){

            }
        }
    }
    else if(pilihan == 2){

    }
}

void playlistSwap(ArrayPlaylists *arrP, int idx, int idy, int idPlaylist){
    int max, ctr = 0;
    Lagu dummy, tempx, tempy;
    address x, y;
    if(idx > idy ){
        max = idx;
    }
    else{
        max = idy;
    }
    address p = First(arrP->playlists[idPlaylist-1].laguplaylist);
    
    while(ctr < max){
        if(ctr == idx){
            x = p;
            tempx = Info(x);
        }
        else if(ctr == idy){
            y = p;
            tempy = Info(y);
        }
        ctr++;
        p = Next(p);
    }
    Info(x) = tempy;
    Info(y) = tempx;

}

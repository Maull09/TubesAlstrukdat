#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    // Deklarasi
    boolean mulai = true;
    boolean sesi = false;

    //Bikin ADT
    //List Nama Penyanyi
    ListSinger DaftarPenyanyi;
    CreateEmptyListSinger(&DaftarPenyanyi);
    //List Playlist
    ArrayPlaylists DaftarPlaylist;
    CreateEmptyArrayPlaylists(&DaftarPlaylist);
    //Queue Lagu
    QueueLagu ToPlay;
    CreateQueue(&ToPlay);
    //History Lagu
    StackSong HistoryLagu;
    CreateEmptyStackSong(&HistoryLagu);
    //Set Kumpulan Lagu
    SetSong KumpulanLagu;
    CreateEmptySet(&KumpulanLagu);
    // Map Penyanyi Album
    MapAlbumSinger SingerAlbum;
    CreateEmptyMapAlbum(&SingerAlbum);
    //Map Album Lagu
    MapSongAlbum SongAlbum;
    CreateEmptyMapSong(&SongAlbum);
    // Linked List Playlist
    // List Playlist;
    // CreateEmptyLinkList(&Playlist);

    // display welcome
    welcome();
    delay(1);

    //display menu before login
    menu();

    while(mulai){
        printf(">> ");
        STARTINPUT();
        if(IsStringEqual(currentWord, "START")){ //Start 
            if (!sesi){
                printf("WayangWave Dimulai\n");
                FUNCSTART(&DaftarPenyanyi, &SingerAlbum, &SongAlbum);
                sesi = true;
            } else {
                printf("Sesi telah dimulai, Command tidak bisa dieksekusi!\n");
            }
        } else if (IsStringEqual(currentWord, "LOAD")){ //Load
            if (!sesi){
                printf("Load Game\n");
                sesi = true;
            } else {
                printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
            }
        }else if (IsStringEqual(currentWord, "LIST")){ //List
            ADVINPUT();
            if (IsStringEqual(currentWord, "DEFAULT")){ // List Default
                if (sesi){
                    printf("Liat Penyanyi\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){ // List Playlist
                if (sesi){
                    printf("Liat Playlist\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "PLAY")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "SONG")){
                if (sesi){
                    printf("Music Menyala\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                if (sesi){
                    printf("Play Playlist\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "QUEUE")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "SONG")){
                if (sesi){
                    printf("Menambahkan lagu ke QUEUE\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                if (sesi){
                    printf("Menambahkan playlist ke QUEUE\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "SWAP")){ // TAMBAHIN HANDLER BLANK
                ADVINPUT();
                int x = atoi(currentWord.TabWord);
                ADVINPUT();
                int y = atoi(currentWord.TabWord);
                if (sesi){
                    printf("Menukar lagu di QUEUE urutan %d dan %d \n", x, y);
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "REMOVE")){
                ADVINPUT();
                int id = atoi(currentWord.TabWord);
                if (sesi){
                    printf("Menghapus lagu ke %d dari queue\n", id);
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "CLEAR")){
                if (sesi){
                    printf("Mengkosongkan Queue\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            }else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "SONG")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "NEXT")){
                if (sesi){
                    printf("Lagu selanjutnya\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "PREVIOUS")){
                if (sesi){
                    printf("Lagu sebelumnya\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "PLAYLIST")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "CREATE")){
                if (sesi){
                    printf("Membuat Playlist Baru\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "ADD")){
                ADVINPUT();
                if(IsStringEqual(currentWord, "SONG")){
                    if (sesi){
                        printf("Lagu telah ditambahkan\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else if(IsStringEqual(currentWord, "ALBUM")){
                    if (sesi){
                        printf("Album telah ditambahkan\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else{
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "SWAP")){
                ADVINPUT();
                int id = atoi(currentWord.TabWord);
                ADVINPUT();
                int x = atoi(currentWord.TabWord);
                ADVINPUT();
                int y = atoi(currentWord.TabWord);
                if (sesi){
                    printf("Playlist %d tukar %d dan %d\n", id, x, y);
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "REMOVE")){
                ADVINPUT();
                int id = atoi(currentWord.TabWord);
                ADVINPUT();
                int n = atoi(currentWord.TabWord);
                if (sesi){
                    printf("Playlist %d hapus urutan %d\n", id, n);
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else if (IsStringEqual(currentWord, "DELETE")){
                if (sesi){
                    printf("Hapus Playlist\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "STATUS")){
            if (sesi){
                printf("Status\n");
            } else {
                printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
            }
        } else if (IsStringEqual(currentWord, "SAVE")){
            ADVINPUT();
            Word filename = currentWord;
            if (!sesi){
                printf("Simpan ke %s\n", filename.TabWord);
            } else {
                printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
            }
        } else if (IsStringEqual(currentWord, "HELP")){
            help();
        } else if (IsStringEqual(currentWord, "QUIT")){
            printf("Adios\n");
            mulai = false;
        } else {
            invcommand();
            while (currentChar != MARK){
                ADVINPUT();
            }
        }

    }

    return 0;
}
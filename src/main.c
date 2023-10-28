#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    // Deklarasi
    boolean mulai = true;

    //Bikin ADT
    //List Nama Penyanyi
    ListSinger DaftarPenyanyi;
    CreateEmptyListSinger(&DaftarPenyanyi);
    //List Playlist
    // ArrayDin DaftarPlaylist;
    // DaftarPlaylist = MakeArrayDin();
    //Queue Lagu
    // Queue ToPlay;
    // CreateQueue(&ToPlay);
    //History Lagu
    // Stack HistoryLagu;
    // CreateEmptyStack(&HistoryLagu);
    //Set Kumpulan Lagu
    // Set KumpulanLagu;
    // CreateEmptySet(&KumpulanLagu);
    // Map Penyanyi Album
    MapAlbum SingerAlbum;
    CreateEmptyMapAlbum(&SingerAlbum);
    //Map Album Lagu
    MapSong SongAlbum;
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
            printf("WayangWave Dimulai\n");
            FUNCSTART(&DaftarPenyanyi, &SingerAlbum, &SongAlbum);
        } else if (IsStringEqual(currentWord, "LOAD")){ //Load
            printf("Load File\n");
        }else if (IsStringEqual(currentWord, "LIST")){ //List
            ADVINPUT();
            if (IsStringEqual(currentWord, "DEFAULT")){ // List Default
                printf("Liat Penyanyi\n");
            } else if (IsStringEqual(currentWord, "PLAYLIST")){ // List Playlist
                printf("Liat Playlist\n");
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "PLAY")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "SONG")){
                printf("Music Menyala\n");
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                printf("Ulang Playlist\n");
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "QUEUE")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "SONG")){
                printf("Menambahkan lagu ke QUEUE\n");
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                printf("Menambahkan playlist ke QUEUE\n");
            } else if (IsStringEqual(currentWord, "SWAP")){ // TAMBAHIN HANDLER BLANK
                ADVINPUT();
                int x = atoi(currentWord.TabWord);
                ADVINPUT();
                int y = atoi(currentWord.TabWord);
                printf("Menukar lagu di QUEUE urutan %d dan %d \n", x, y);
            } else if (IsStringEqual(currentWord, "REMOVE")){
                ADVINPUT();
                int id = atoi(currentWord.TabWord);
                printf("Menghapus lagu ke %d dari queue\n", id);
            } else if (IsStringEqual(currentWord, "CLEAR")){
                printf("Mengkosongkan Queue\n");
            }else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "SONG")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "NEXT")){
                printf("Lagu selanjutnya\n");
            } else if (IsStringEqual(currentWord, "PREVIOUS")){
                printf("Lagu sebelumnya\n");
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "PLAYLIST")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "CREATE")){
                printf("Membuat Playlist Baru\n");
            } else if (IsStringEqual(currentWord, "ADD")){
                ADVINPUT();
                if(IsStringEqual(currentWord, "SONG")){
                    printf("Lagu telah ditambahkan\n");
                } else if(IsStringEqual(currentWord, "ALBUM")){
                    printf("Album telah ditambahkan\n");
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
                printf("Playlist %d tukar %d dan %d\n", id, x, y);
            } else if (IsStringEqual(currentWord, "REMOVE")){
                ADVINPUT();
                int id = atoi(currentWord.TabWord);
                ADVINPUT();
                int n = atoi(currentWord.TabWord);
                printf("Playlist %d hapus urutan %d\n", id, n);
            } else if (IsStringEqual(currentWord, "DELETE")){
                printf("Hapus Playlist\n");
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "STATUS")){
            printf("Status\n");
        } else if (IsStringEqual(currentWord, "SAVE")){
            ADVINPUT();
            Word filename = currentWord;
            printf("Simpan ke %s\n", filename.TabWord);
        } else if (IsStringEqual(currentWord, "HELP")){
            help();
        } else if (IsStringEqual(currentWord, "QUIT")){
            printf("Adios\n");
            mulai = false;
        } else {
            invcommand();
        }
    }

    return 0;
}
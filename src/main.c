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
    MapAlbum SingerAlbum;
    CreateEmptyMapAlbum(&SingerAlbum);
    //Map Album Lagu
    MapSong SongAlbum;
    CreateEmptyMapSong(&SongAlbum);
    // Linked List Playlist
    List Playlist;
    CreateEmpty(&Playlist);
    // List Map Album Lagu
    ListMapAlbum KumpulanAlbum;
    CreateEmptyListMapAlbum(&KumpulanAlbum);
    // List Map Song
    ListMapSong KumpulanLaguAlbum;
    CreateEmptyListMapSong(&KumpulanLaguAlbum);

    // display welcome
    welcome();
    delay(1);

    //display menu before login
    menu();

    while(mulai){
        printf(">> ");
        STARTINPUT();
        if(IsStringEqual(currentWord, "START")){ //Start 
            ADVINPUT();
            if (EndWord){
                if (!sesi){
                    printf("WayangWave Dimulai\n");
                    // FUNCSTART(&DaftarPenyanyi, &SingerAlbum, &SongAlbum);
                    char tempcurrentchar = currentChar;
                    FUNCSTART();
                    sesi = true;
                    currentChar = tempcurrentchar;
                } else {
                    printf("Sesi telah dimulai, Command tidak bisa dieksekusi!\n");
                }
            }else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "LOAD")){ //Load
            ADVINPUT();            
            if(name_valid(currentWord.TabWord)){
                Word filename = currentWord;
                ADVINPUT();
                
                if (EndWord){
                    if (!sesi){
                        sesi = true;
                        printf("Load Game\n");
                    } else {
                        printf("Sesi telah dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "LIST")){ //List
            ADVINPUT();
            if (IsStringEqual(currentWord, "DEFAULT")){ // List Default
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Liat Penyanyi\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){ // List Playlist
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Liat Playlist\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "PLAY")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "SONG")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Play Lagu\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Play Playlist\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "QUEUE")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "SONG")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Queue Song\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Queue Playlist\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "SWAP")){ 
                ADVINPUT();
                if(isNumber(currentWord.TabWord)){
                    int x = atoi(currentWord.TabWord);
                    ADVINPUT();
                    if(isNumber(currentWord.TabWord)){
                        int y = atoi(currentWord.TabWord);
                        ADVINPUT();
                        if (EndWord){
                            if (sesi){
                                printf("Queue swap %d %d\n", x,y);
                            } else {
                                printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                            }
                        } else {
                            invcommand();
                        }
                    } else {
                        invcommand();
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "REMOVE")){ 
                ADVINPUT();
                
                // Pengecekan apakah currentWord adalah angka
                if(isNumber(currentWord.TabWord)){
                    int id = atoi(currentWord.TabWord);
                    ADVINPUT();
                    
                    if (EndWord){
                        if (sesi){
                            printf("Queue remove %d\n", id);
                        } else {
                            printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                        }
                    } else {
                        invcommand();
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "CLEAR")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Queue start\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            }else {
                invcommand();
                
            }
        }else if (IsStringEqual(currentWord, "SONG")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "NEXT")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Song next\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "PREVIOUS")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Song prev\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else {
                invcommand();
            }
        }else if (IsStringEqual(currentWord, "PLAYLIST")){
            ADVINPUT();
            if (IsStringEqual(currentWord, "CREATE")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Playlist Create\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "ADD")){
                ADVINPUT();
                if(IsStringEqual(currentWord, "SONG")){
                    ADVINPUT();
                    if (EndWord){
                        if (sesi){
                            printf("Playlist Add Song\n");
                        } else {
                            printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                        }
                    } else {
                        invcommand();
                    }
                } else if(IsStringEqual(currentWord, "ALBUM")){
                    ADVINPUT();
                    if (EndWord){
                        if (sesi){
                            printf("Playlist Add Album\n");
                        } else {
                            printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                        }
                    } else {
                        invcommand();
                    }
                } else{
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "SWAP")){ 
                ADVINPUT();
                
                if(isNumber(currentWord.TabWord)){
                    int id = atoi(currentWord.TabWord);
                    ADVINPUT();

                    if(isNumber(currentWord.TabWord)){
                        int x = atoi(currentWord.TabWord);
                        ADVINPUT();
                        
                        if(isNumber(currentWord.TabWord)){
                            int y = atoi(currentWord.TabWord);
                            ADVINPUT();
                            
                            if (EndWord){
                                if (sesi){
                                    printf("Playlist %d swap %d %d\n", id, x, y);
                                } else {
                                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                                }
                            } else {
                                invcommand();
                            }
                        } else {
                            invcommand();
                        }
                    } else {
                        invcommand();
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "REMOVE")){ 
                ADVINPUT();
                
                if(isNumber(currentWord.TabWord)){
                    int id = atoi(currentWord.TabWord);
                    ADVINPUT();

                    if(isNumber(currentWord.TabWord)){
                        int n = atoi(currentWord.TabWord);
                        ADVINPUT();
                        
                        if (EndWord){
                            if (sesi){
                                printf("Playlist %d remove %d\n", id, n);
                            } else {
                                printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                            }
                        } else {
                            invcommand();
                        }
                    } else {
                        invcommand();
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "DELETE")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Delete Playlist\n");
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "STATUS")){
            ADVINPUT();
            if (EndWord){
                if (sesi){
                    printf("Liat Status\n");
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "SAVE")){ 
            ADVINPUT();
            
            if(name_valid(currentWord.TabWord)){
                Word filename = currentWord;
                ADVINPUT();
                
                if (EndWord){
                    if (sesi){
                        printf("Simpan ke %s\n", filename.TabWord);
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "HELP")){
            ADVINPUT();
            if (EndWord){
                help();
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "QUIT")){
            ADVINPUT();
            if (EndWord){
                printf("Adios\n");
                mulai = false;
            } else {
                invcommand();
            }
        } else {
            invcommand();
        }
        EndInput();
    }
    return 0;
}
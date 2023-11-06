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
    // List Map Album Lagu
    ListMapAlbum KumpulanAlbumSinger;
    CreateEmptyListMapAlbum(&KumpulanAlbumSinger);
    // List Map Song
    ListMapSong KumpulanLaguAlbum;
    CreateEmptyListMapSong(&KumpulanLaguAlbum);
    // Lagu
    Lagu Playnow;    
    CreateLagu(&Playnow);


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
                    char tempcurrentchar = currentChar;
                    FUNCSTART(&DaftarPenyanyi, &SingerAlbum, &SongAlbum, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &KumpulanLagu);
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
                char *namefile = (char *)malloc(256 * sizeof(char));
                SalinString(namefile, currentWord.TabWord);
                ADVINPUT();
                if (EndWord){
                    if (!sesi){
                        sesi = true;
                        char tempcurrentchar = currentChar;
                        Load(namefile, &DaftarPenyanyi, &SingerAlbum, &SongAlbum, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &KumpulanLagu, &ToPlay, &HistoryLagu, &DaftarPlaylist);
                        free(namefile);
                        currentChar = tempcurrentchar;
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
                        ListDefault(&DaftarPenyanyi, &KumpulanAlbumSinger, &KumpulanLaguAlbum);
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
                        DisplayPlaylist(&DaftarPlaylist);
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
                        PlaySong(&DaftarPenyanyi, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &Playnow, &ToPlay, &HistoryLagu);
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
                        DisplayPlaylist(&DaftarPlaylist);
                        printf("id : ");
                        STARTINPUT2();
                        int idxarr = atoi(currentWord.TabWord);
                        PlayPlaylist(&DaftarPlaylist, &HistoryLagu, &ToPlay, idxarr);
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
                        QueueSong(&DaftarPenyanyi, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &ToPlay);
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
                        DisplayPlaylist(&DaftarPlaylist);
                        printf("id : ");
                        STARTINPUT2();
                        int idxarr = atoi(currentWord.TabWord);
                        QueuePlaylist(&DaftarPlaylist, &ToPlay, idxarr);
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
                                QueueSwap(&ToPlay, x, y);
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
                            removeSong(&ToPlay, id);
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
                        clearQueue(&ToPlay);
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
                        if(!isEmptyQueue(ToPlay)){
                            dequeue(&ToPlay, &Playnow);
                            printf("Memutar lagu selanjutnya %s oleh %s\n", Playnow.titlesong, Playnow.artist);
                        } else {
                            printf("Queue kosong, memutar kembali lagu  %s oleh %s\n", Playnow.titlesong, Playnow.artist);
                        }
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
                        if (!IsEmptyStackSong){
                            PopStackSong(&HistoryLagu, &Playnow);
                            printf("Memutar lagu sebelumnya %s oleh %s\n", Playnow.titlesong, Playnow.artist);
                        } else {
                            printf("Riwayat lagu kosong, memutar kembali lagu %s oleh %s\n", Playnow.titlesong, Playnow.artist);
                        }
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
                        printf("Masukkan nama playlist yang ingin dibuat : ");
                        STARTINPUT2();
                        PlaylistCreate(&DaftarPlaylist, currentWord.TabWord);
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
                                if(isValidPlaylist(&DaftarPlaylist, id)){
                                    if(isValidSong(&DaftarPlaylist, n)){
                                        PrintInfo(DaftarPlaylist.playlists[id-1].laguplaylist);
                                        printf("\n");
                                        PlaylistRemove(&DaftarPlaylist, id, n);
                                        printf("Playlist %d remove %d\n", id, n);
                                        PrintInfo(DaftarPlaylist.playlists[id-1].laguplaylist);
                                    } else {

                                    }
                                } else{

                                }
                                //if valid idplaylist dan valid idlagu
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
                        DisplayPlaylist(&DaftarPlaylist);
                        printf("id : ");
                        STARTINPUT2();
                        int idxp = atoi(currentWord.TabWord); 
                        //
                        PlaylistDelete(&DaftarPlaylist, idxp);
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
                    STATUS(&Playnow, &ToPlay);
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
        } else if (IsStringEqual(currentWord, "ENHANCE")){
            ADVINPUT();
            if (EndWord){
                if (sesi){
                    DisplayPlaylist(&DaftarPlaylist);
                    if(DaftarPlaylist.Neff != 0){
                        printf("\n");
                        printf("Silahkan pilih playlist untuk di enhance : ");
                        STARTINPUT2();
                        if (playlist_valid(&DaftarPlaylist, currentWord.TabWord)){
                            enhance(&DaftarPenyanyi, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &DaftarPlaylist, currentWord.TabWord);
                        } else {
                            printf("Tidak ada playlist %s\n", currentWord.TabWord);
                        }
                    }
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else {
                invcommand();
            }
        }else {
            invcommand();
        }
        EndInput();
        printf("=============================================================================================\n");
    }
    return 0;
}
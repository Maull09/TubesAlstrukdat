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
                        printf("Daftar playlist yang kamu miliki:\n");
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
                            // DisplayPlaylist(&DaftarPlaylist);
                            if(DaftarPlaylist.Neff != 0){
                                printf("Masukkan ID Playlist : ");
                                STARTINPUT2();
                                int idxarr = atoi(currentWord.TabWord);
                                PlayPlaylist(&DaftarPlaylist, &HistoryLagu, &ToPlay, idxarr);
                                printf("Memutar playlist \"%s\".\n", DaftarPlaylist.playlists[idxarr-1].name);
                            } else {
                                printf("Kamu tidak memiliki playlist.\n");
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
                        // DisplayPlaylist(&DaftarPlaylist);
                        if(DaftarPlaylist.Neff != 0){
                            printf("Masukkan ID Playlist : ");
                            STARTINPUT2();
                            int idxarr = atoi(currentWord.TabWord);
                            if (isValidPlaylist(&DaftarPlaylist, idxarr) && (DaftarPlaylist.Neff != 0)){
                                QueuePlaylist(&DaftarPlaylist, &ToPlay, idxarr);
                            }
                            printf("Berhasil menambahkan playlist \"%s\" ke queue.\n");
                        } else{
                            printf("Kamu tidak memiliki playlist.\n");
                        }
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
                            if(!StringSama(Playnow.titlesong, "\0")){
                                PushStackSong(&HistoryLagu, Playnow);
                            }
                            dequeue(&ToPlay, &Playnow);
                            printf("Memutar lagu selanjutnya \"%s\" oleh \"%s\"\n", Playnow.titlesong, Playnow.artist);
                        } else {
                            printf("Queue kosong, memutar kembali lagu \"%s\" oleh \"%s\"\n", Playnow.titlesong, Playnow.artist);
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
                        if (!IsEmptyStackSong(HistoryLagu)){
                            if(!StringSama(Playnow.titlesong, "\0")){
                                enqueueFirst(&ToPlay, Playnow);
                            }
                            PopStackSong(&HistoryLagu, &Playnow);
                            printf("Memutar lagu sebelumnya \"%s\" oleh \"%s\"\n", Playnow.titlesong, Playnow.artist);
                        } else {
                            printf("Riwayat lagu kosong, memutar kembali lagu \"%s\" oleh \"%s\"\n", Playnow.titlesong, Playnow.artist);
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
                                    if(isValidPlaylist(&DaftarPlaylist, id)){
                                        if(isValidSong(DaftarPlaylist.playlists[id-1].laguplaylist, x)){
                                            if(isValidSong(DaftarPlaylist.playlists[id-1].laguplaylist, y)){
                                                playlistSwap(&DaftarPlaylist, x, y, id);
                                            } else {
                                                printf("Tidak ada lagu dengan urutan %d di playlist “%s”!", y , DaftarPlaylist.playlists[id-1].name);
                                            }
                                        } else {
                                            printf("Tidak ada lagu dengan urutan %d di playlist “%s”!", x , DaftarPlaylist.playlists[id-1].name);
                                        }
                                    } else{
                                        printf("Tidak ada playlist dengan ID %d.", id);
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
                                    if(isValidSong(DaftarPlaylist.playlists[id-1].laguplaylist, n)){
                                        PrintInfo(DaftarPlaylist.playlists[id-1].laguplaylist);
                                        printf("\n");
                                        PlaylistRemove(&DaftarPlaylist, id, n);
                                        printf("Playlist %d remove %d\n", id, n);
                                        PrintInfo(DaftarPlaylist.playlists[id-1].laguplaylist);
                                    } else {
                                        printf("Tidak ada lagu dengan urutan %d di playlist “%s”!", n, DaftarPlaylist.playlists[id-1].name);
                                    }
                                } else{
                                    printf("Tidak ada playlist dengan ID %d.", id);
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
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "DELETE")){
                ADVINPUT();
                if (EndWord){
                    if (sesi){
                        printf("Daftar Playlist Pengguna : \n");
                        DisplayPlaylist(&DaftarPlaylist);
                        printf("Masukkan ID Playlist yang dipilih : ");
                        STARTINPUT2();
                        int idxp = atoi(currentWord.TabWord); 
                        if(isValidPlaylist(&DaftarPlaylist, idxp)){
                            printf("Playlist ID %d dengan judul %s berhasil dihapus.\n", idxp, DaftarPlaylist.playlists[idxp-1].name);
                            PlaylistDelete(&DaftarPlaylist, idxp);
                        }
                        else{
                            printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", idxp);
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
                        char *saves= "./data/";
                        saves = concat(saves, filename.TabWord);
                        FILE *savefile = fopen(saves,"w");
                        int albumindex = 0, songindex = 0;
                        fprintf(savefile,"%d\n",DaftarPenyanyi.Neff);
                        for(int u=0;u<DaftarPenyanyi.Neff;u++){
                            fprintf(savefile,"%d %s\n",KumpulanAlbumSinger.MapAlbums[u].Neff,DaftarPenyanyi.singers[u].singerName);

                            for(int e=0; e<KumpulanAlbumSinger.MapAlbums[u].Neff;e++){
                                fprintf(savefile,"%d %s\n",KumpulanLaguAlbum.MapSongs[albumindex + e].songs.Neff,KumpulanLaguAlbum.MapSongs[albumindex + e].albumName);

                                for (int o=0; o<KumpulanLaguAlbum.MapSongs[albumindex + e].songs.Neff;o++){
                                    fprintf(savefile,"%s\n",KumpulanLaguAlbum.MapSongs[albumindex + e].songs.songs[o].songName);
                                }
                            }
                            albumindex += KumpulanAlbumSinger.MapAlbums[u].Neff;
                        }
                        //bagian queue
                        if(!isEmptyQueue(ToPlay)){
                            fprintf(savefile,"%d\n",lengthQueue(ToPlay));
                            for(int i=0;i<lengthQueue(ToPlay);i++){
                                fprintf(savefile,"%s;%s;%s\n",ToPlay.buffer[i].artist,ToPlay.buffer[i].album,ToPlay.buffer[i].titlesong);
                            }
                        } else {
                            fprintf(savefile,"0\n");
                        }
                        //bagian riwayat
                        if(!IsEmptyStackSong(HistoryLagu)){
                            fprintf(savefile,"%d\n",HistoryLagu.TOP);
                            for(int i = 0 ;i <= HistoryLagu.TOP-1;i++){
                                fprintf(savefile,"%s;%s;%s\n",HistoryLagu.Songs[i].artist,HistoryLagu.Songs[i].album,HistoryLagu.Songs[i].titlesong);
                            }
                        } else {
                            fprintf(savefile,"0\n");
                        }
                        // //bagian playlist
                        if (DaftarPlaylist.Neff != 0 ){
                            fprintf(savefile,"%d\n",DaftarPlaylist.Neff);
                            for (int i = 0; i < DaftarPlaylist.Neff; i++) {
                                fprintf(savefile, "%d %s", NbElmt(DaftarPlaylist.playlists[i].laguplaylist), DaftarPlaylist.playlists[i].name);
                                int jumlahLagu = NbElmt(DaftarPlaylist.playlists[i].laguplaylist);
                                address P = First(DaftarPlaylist.playlists[i].laguplaylist);
                                
                                if (jumlahLagu > 0) {
                                    fprintf(savefile, "\n"); // Baris baru hanya jika ada lagu dalam playlist
                                }
                                
                                while (P != Nil) {
                                    fprintf(savefile, "%s;%s;%s", artist(P), album(P), titlesong(P));
                                    P = Next(P);
                                    if (P != Nil) {
                                        fprintf(savefile, "\n"); // Baris baru setelah setiap lagu kecuali lagu terakhir
                                    }
                                }
                                
                                if (i < DaftarPlaylist.Neff - 1) {
                                    fprintf(savefile, "\n"); // Baris baru setelah setiap playlist kecuali playlist terakhir
                                }
                            } 
                        } else {
                            fprintf(savefile,"0");
                        }
                        fclose(savefile);
                        printf("Save file berhasil disimpan.\n");
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
#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    // Deklarasi
    boolean mulai = true;
    boolean sesi = false;
    boolean foundfile = false;
    boolean login = false;
    char *nameplaylist = (char *)malloc(256 * sizeof(char));
    // char *namefile = (char *)malloc(256 * sizeof(char));

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
    int idxuser;
    arrofuser users;
    CreateEmptyUsers(&users);


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
                if (!sesi && !login){
                    printf("WayangWave Dimulai\n");
                    char tempcurrentchar = currentChar;
                    FUNCSTART(&DaftarPenyanyi, &SingerAlbum, &SongAlbum, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &KumpulanLagu, &users);
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
                    if (!sesi && !login){
                        char tempcurrentchar = currentChar;
                        Load(namefile, &DaftarPenyanyi, &SingerAlbum, &SongAlbum, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &KumpulanLagu, &ToPlay, &HistoryLagu, &DaftarPlaylist, &foundfile, &Playnow, &users);
                        free(namefile);
                        currentChar = tempcurrentchar;
                        if(foundfile){
                            sesi = true;
                            printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                        }
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
                    if (sesi && login){
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
                    if (sesi && login){
                        printf("Daftar playlist yang kamu miliki:\n");
                        DisplayPlaylist(&users.user[idxuser].arrp);
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
                    if (sesi && login){
                        PlaySong(&DaftarPenyanyi, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &users.user[idxuser].currentsong, &users.user[idxuser].queue, &users.user[idxuser].history);
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                ADVINPUT();
                if (EndWord){
                    if (sesi && login){
                            // DisplayPlaylist(&DaftarPlaylist);
                            if(DaftarPlaylist.Neff != 0){
                                printf("\nMasukkan ID Playlist : ");
                                STARTINPUT2();
                                int idxarr = atoi(currentWord.TabWord);
                                if(FindPlaylist(users.user[idxuser].arrp, idxarr)){
                                    PlayPlaylist(&users.user[idxuser].arrp, &users.user[idxuser].history, &users.user[idxuser].queue, idxarr);
                                    dequeue(&users.user[idxuser].queue, &users.user[idxuser].currentsong);
                                    printf("\nMemutar playlist \"%s\".\n", users.user[idxuser].arrp.playlists[idxarr-1].name);
                                }
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
                    if (sesi && login){
                        QueueSong(&DaftarPenyanyi, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &users.user[idxuser].queue);
                    } else {
                        printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                    }
                } else {
                    invcommand();
                }
            } else if (IsStringEqual(currentWord, "PLAYLIST")){
                ADVINPUT();
                if (EndWord){
                    if (sesi && login){
                        // DisplayPlaylist(&DaftarPlaylist);
                        if(users.user[idxuser].arrp.Neff != 0){
                            printf("\nMasukkan ID Playlist : ");
                            STARTINPUT2();
                            int idxarr = atoi(currentWord.TabWord);
                            if (isValidPlaylist(&users.user[idxuser].arrp, idxarr) && (users.user[idxuser].arrp.Neff != 0)){
                                QueuePlaylist(&users.user[idxuser].arrp, &users.user[idxuser].queue, idxarr);
                            }
                            printf("\nBerhasil menambahkan playlist \"%s\" ke queue.\n");
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
                            if (sesi && login){
                                QueueSwap(&users.user[idxuser].queue, x, y);
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
                        if (sesi && login){
                            removeSong(&users.user[idxuser].queue, id);
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
                    if (sesi && login){
                        clearQueue(&users.user[idxuser].queue);
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
                    if (sesi && login){
                        if(!isEmptyQueue(users.user[idxuser].queue)){
                            if(!StringSama(users.user[idxuser].currentsong.titlesong, "\0")){
                                PushStackSong(&users.user[idxuser].history, users.user[idxuser].currentsong);
                            }
                            dequeue(&users.user[idxuser].queue, &users.user[idxuser].currentsong);
                            printf("Memutar lagu selanjutnya \"%s\" oleh \"%s\"\n", users.user[idxuser].currentsong.titlesong, users.user[idxuser].currentsong.artist);
                        } else if (isEmptyQueue(users.user[idxuser].queue) && !StringSama(users.user[idxuser].currentsong.titlesong, "\0")) {
                            printf("Queue kosong, memutar kembali lagu \"%s\" oleh \"%s\"\n", users.user[idxuser].currentsong.titlesong, users.user[idxuser].currentsong.artist);
                        } else if (isEmptyQueue(users.user[idxuser].queue) && StringSama(users.user[idxuser].currentsong.titlesong, "\0")){
                            printf("Queue Lagu Kosong dan Tidak ada lagu yang sedang diputar, Song Next gagal dijalankan\n");
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
                    if (sesi && login){
                        if (!IsEmptyStackSong(users.user[idxuser].history)){
                            if(!StringSama(users.user[idxuser].currentsong.titlesong, "\0")){
                                enqueueFirst(&users.user[idxuser].queue, users.user[idxuser].currentsong);
                            }
                            PopStackSong(&users.user[idxuser].history, &users.user[idxuser].currentsong);
                            printf("Memutar lagu sebelumnya \"%s\" oleh \"%s\"\n", users.user[idxuser].currentsong.titlesong, users.user[idxuser].currentsong.artist);
                        } else if (IsEmptyStackSong(users.user[idxuser].history) && !StringSama(users.user[idxuser].currentsong.titlesong, "\0")){
                            printf("Riwayat lagu kosong, memutar kembali lagu \"%s\" oleh \"%s\"\n", users.user[idxuser].currentsong.titlesong, users.user[idxuser].currentsong.artist);
                        } else if (IsEmptyStackSong(users.user[idxuser].history) && StringSama(users.user[idxuser].currentsong.titlesong, "\0")) {
                            printf("Riwayat Lagu kosong dan Tidak ada lagu yang sedang diputar, Song Previous gagal dijalankan\n");
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
                    if (sesi && login){
                        printf("Masukkan nama playlist yang ingin dibuat : ");
                        STARTINPUT2();
                        if(currentWord.TabWord[0] == BLANK && currentWord.TabWord[1] == BLANK && currentWord.TabWord[2] == BLANK && currentWord.Length == 3){
                            printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
                        } else {
                            PlaylistCreate(&users.user[idxuser].arrp, currentWord.TabWord);
                        }
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
                        if (sesi && login){
                            playlistAddSong(&users.user[idxuser].arrp, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &DaftarPenyanyi);
                        } else {
                            printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                        }
                    } else {
                        invcommand();
                    }
                } else if(IsStringEqual(currentWord, "ALBUM")){
                    ADVINPUT();
                    if (EndWord){
                        if (sesi && login){
                            playlistAddAlbum(&users.user[idxuser].arrp, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &DaftarPenyanyi);
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
                                if (sesi && login){
                                    if(isValidPlaylist(&users.user[idxuser].arrp, id)){
                                        if(isValidSong(users.user[idxuser].arrp.playlists[id-1].laguplaylist, x)){
                                            if(isValidSong(users.user[idxuser].arrp.playlists[id-1].laguplaylist, y)){
                                                playlistSwap(&users.user[idxuser].arrp, x, y, id);
                                            } else {
                                                printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n", y , users.user[idxuser].arrp.playlists[id-1].name);
                                            }
                                        } else {
                                            printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n", x , users.user[idxuser].arrp.playlists[id-1].name);
                                        }
                                    } else{
                                        printf("Tidak ada playlist dengan playlist ID %d.\n", id);
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
                            if (sesi && login){
                                if(isValidPlaylist(&users.user[idxuser].arrp, id)){
                                    if(isValidSong(users.user[idxuser].arrp.playlists[id-1].laguplaylist, n)){
                                        PlaylistRemove(&users.user[idxuser].arrp, id, n);
                                    } else {
                                        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n   ", n, users.user[idxuser].arrp.playlists[id-1].name);
                                    }
                                } else{
                                    printf("Tidak ada playlist dengan ID %d.\n", id);
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
                    if (sesi && login){
                        printf("Daftar Playlist Pengguna : \n");
                        DisplayPlaylist(&users.user[idxuser].arrp);
                        printf("Masukkan ID Playlist yang dipilih : ");
                        STARTINPUT2();
                        int idxp = atoi(currentWord.TabWord); 
                        if(isValidPlaylist(&users.user[idxuser].arrp, idxp)){
                            printf("Playlist ID %d dengan judul %s berhasil dihapus.\n", idxp, users.user[idxuser].arrp.playlists[idxp-1].name);
                            PlaylistDelete(&users.user[idxuser].arrp, idxp);
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
                if (sesi && login){
                    STATUS(&users.user[idxuser].currentsong, &users.user[idxuser].queue, &users.user[idxuser].arrp, &users.user[idxuser].history, users.user[idxuser].username);
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
                    if (sesi && login){
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

                        fprintf(savefile, "%d\n", users.neff);
                        for(int i = 0; i < users.neff; i++){
                            fprintf(savefile, "%s\n", users.user[i].username);
                        } 

                        for(int i = 0; i < users.neff; i++){
                            if(!(StringSama(users.user[idxuser].currentsong.artist, "\0") && StringSama(users.user[idxuser].currentsong.album, "\0") && StringSama(users.user[idxuser].currentsong.titlesong, "\0"))){
                                fprintf(savefile, "%s;%s;%s\n", users.user[idxuser].currentsong.artist, users.user[idxuser].currentsong.album, users.user[idxuser].currentsong.titlesong);
                            } 

                            //bagian queue
                            if(!isEmptyQueue(users.user[idxuser].queue)){
                                fprintf(savefile,"%d\n",lengthQueue(users.user[idxuser].queue));
                                for(int i=0;i<lengthQueue(users.user[idxuser].queue);i++){
                                    fprintf(savefile,"%s;%s;%s\n",users.user[idxuser].queue.buffer[i].artist,users.user[idxuser].queue.buffer[i].album,users.user[idxuser].queue.buffer[i].titlesong);
                                }
                            } else {
                                fprintf(savefile,"0\n");
                            }
                            //bagian riwayat
                            if(!IsEmptyStackSong(users.user[idxuser].history)){
                                fprintf(savefile,"%d\n",users.user[idxuser].history.TOP);
                                for(int i = 0 ;i <= users.user[idxuser].history.TOP-1;i++){
                                    fprintf(savefile,"%s;%s;%s\n",users.user[idxuser].history.Songs[i].artist,users.user[idxuser].history.Songs[i].album,users.user[idxuser].history.Songs[i].titlesong);
                                }
                            } else {
                                fprintf(savefile,"0\n");
                            }
                            // //bagian playlist
                            if (users.user[idxuser].arrp.Neff != 0 ){
                                fprintf(savefile,"%d\n",users.user[idxuser].arrp.Neff);
                                for (int i = 0; i < users.user[idxuser].arrp.Neff; i++) {
                                    fprintf(savefile, "%d %s", NbElmt(users.user[idxuser].arrp.playlists[i].laguplaylist), users.user[idxuser].arrp.playlists[i].name);
                                    int jumlahLagu = NbElmt(users.user[idxuser].arrp.playlists[i].laguplaylist);
                                    address P = First(users.user[idxuser].arrp.playlists[i].laguplaylist);
                                    
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
                                    
                                    if (i < users.user[idxuser].arrp.Neff - 1) {
                                        fprintf(savefile, "\n"); // Baris baru setelah setiap playlist kecuali playlist terakhir
                                    }
                                } 
                            } else {
                                fprintf(savefile,"0");
                            }
                            fclose(savefile);
                        } 
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
                help(sesi, login);
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "QUIT")){
            ADVINPUT();
            if (EndWord){
                printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
                STARTINPUT();
                if(!StringSama(currentWord.TabWord, "Y")){
                    printf("\nKamu keluar dari WayangWave.\n");
                    printf("Dadah ^_^\n");
                } else {
                    printf("\nSilahkan masukkan nama file untuk menyimpan sesi <filename.txt> : ");
                    STARTINPUT2();
                    char *savesname= "./data/";
                    savesname = concat(savesname, currentWord.TabWord);
                    FILE *savefile = fopen(savesname,"w");
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

                    fprintf(savefile, "%d\n", users.neff);
                    for(int i = 0; i < users.neff; i++){
                        fprintf(savefile, "%s\n", users.user[i].username);
                    } 

                    for(int i = 0; i < users.neff; i++){
                        if(!(StringSama(users.user[idxuser].currentsong.artist, "\0") && StringSama(users.user[idxuser].currentsong.album, "\0") && StringSama(users.user[idxuser].currentsong.titlesong, "\0"))){
                            fprintf(savefile, "%s;%s;%s\n", users.user[idxuser].currentsong.artist, users.user[idxuser].currentsong.album, users.user[idxuser].currentsong.titlesong);
                        } 

                        //bagian queue
                        if(!isEmptyQueue(users.user[idxuser].queue)){
                            fprintf(savefile,"%d\n",lengthQueue(users.user[idxuser].queue));
                            for(int i=0;i<lengthQueue(users.user[idxuser].queue);i++){
                                fprintf(savefile,"%s;%s;%s\n",users.user[idxuser].queue.buffer[i].artist,users.user[idxuser].queue.buffer[i].album,users.user[idxuser].queue.buffer[i].titlesong);
                            }
                        } else {
                            fprintf(savefile,"0\n");
                        }
                        //bagian riwayat
                        if(!IsEmptyStackSong(users.user[idxuser].history)){
                            fprintf(savefile,"%d\n",users.user[idxuser].history.TOP);
                            for(int i = 0 ;i <= users.user[idxuser].history.TOP-1;i++){
                                fprintf(savefile,"%s;%s;%s\n",users.user[idxuser].history.Songs[i].artist,users.user[idxuser].history.Songs[i].album,users.user[idxuser].history.Songs[i].titlesong);
                            }
                        } else {
                            fprintf(savefile,"0\n");
                        }
                        // //bagian playlist
                        if (users.user[idxuser].arrp.Neff != 0 ){
                            fprintf(savefile,"%d\n",users.user[idxuser].arrp.Neff);
                            for (int i = 0; i < users.user[idxuser].arrp.Neff; i++) {
                                fprintf(savefile, "%d %s", NbElmt(users.user[idxuser].arrp.playlists[i].laguplaylist), users.user[idxuser].arrp.playlists[i].name);
                                int jumlahLagu = NbElmt(users.user[idxuser].arrp.playlists[i].laguplaylist);
                                address P = First(users.user[idxuser].arrp.playlists[i].laguplaylist);
                                
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
                                
                                if (i < users.user[idxuser].arrp.Neff - 1) {
                                    fprintf(savefile, "\n"); // Baris baru setelah setiap playlist kecuali playlist terakhir
                                }
                            } 
                        } else {
                            fprintf(savefile,"0");
                        }
                        fclose(savefile);
                    } 
                    printf("Save file berhasil disimpan.\n");
                }
                mulai = false;
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "ENHANCE")){
            ADVINPUT();
            if (EndWord){
                if (sesi && login){
                    if(users.user[idxuser].arrp.Neff != 0){
                        printf("Daftar playlist yang kamu miliki:\n");
                        DisplayPlaylist(&users.user[idxuser].arrp);
                        if(users.user[idxuser].arrp.Neff != 0){
                            printf("\n");
                            printf("Silahkan pilih playlist untuk di enhance : ");
                            STARTINPUT2();
                            if (playlist_valid(&users.user[idxuser].arrp, currentWord.TabWord)){
                                enhance(&DaftarPenyanyi, &KumpulanAlbumSinger, &KumpulanLaguAlbum, &users.user[idxuser].arrp, currentWord.TabWord);
                            } else {
                                printf("Tidak ada playlist %s\n", currentWord.TabWord);
                            }
                        }
                    } else {
                        printf("Kamu tidak memiliki playlist.\n");
                    }
                } else {
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                }
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "LOGIN")){
            ADVINPUT();
            if (EndWord){
                if(!login && !sesi){
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                } else if(!login && sesi){
                    do {
                        printf("\nMasukkan username user WayangWave : ");
                        STARTINPUT();
                        if(FindIndexUser(&users, currentWord.TabWord)){
                            login = true;
                            idxuser = FindUserIndex(&users, currentWord.TabWord);
                            printf("\nBerhasil masuk. Selamat datang %s\n", currentWord.TabWord);
                        } else {
                            printf("\nTidak ada user dengan username \"%s\" \n", currentWord.TabWord);
                        } 
                    } while (!login);
                }else {
                    printf("Sesi telah dimulai, Command tidak bisa dieksekusi\n");
                }
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "LOGOUT")){
            ADVINPUT();
            if (EndWord){
                if(!sesi && !login){
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                } else {
                    idxuser = -1;
                    login = false;
                    printf("Berhasil keluar. Sampai jumpa lagi!\n");
                }
            } else {
                invcommand();
            }
        } else if (IsStringEqual(currentWord, "REGISTER")){
            ADVINPUT();
            if (EndWord){
                if(!sesi){
                    printf("Sesi belum dimulai, Command tidak bisa dieksekusi!\n");
                } else {
                    printf("\nMasukkan username user baru WayangWave : ");
                    STARTINPUT();
                    if(!FindIndexUser(&users, currentWord.TabWord)){
                        infouser dummyuser = CreateUser(currentWord.TabWord);
                        InsertUser(&users, dummyuser);
                        printf("\nAkun %s berhasil ditambahkan\n", currentWord.TabWord);
                    } else {
                        printf("\nUser dengan username\"%s\" telah ada\n", currentWord.TabWord);
                    } 
                }
            } else {
                invcommand();
            }
        }  else if (IsStringEqual(currentWord, "REMOVE")){ //List
            ADVINPUT();
            if (IsStringEqual(currentWord, "PLAYLIST")){ // List Default
                ADVINPUT();
                                
                if(isNumber(currentWord.TabWord)){
                    int id = atoi(currentWord.TabWord);
                    ADVINPUT();

                    if(isNumber(currentWord.TabWord)){
                        int n = atoi(currentWord.TabWord);
                        ADVINPUT();
                        
                        if (EndWord){
                            if (sesi && login){
                                if(isValidPlaylist(&DaftarPlaylist, id)){
                                    if(isValidSong(DaftarPlaylist.playlists[id-1].laguplaylist, n)){
                                        PlaylistRemove(&DaftarPlaylist, id, n);
                                    } else {
                                        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n   ", n, DaftarPlaylist.playlists[id-1].name);
                                    }
                                } else{
                                    printf("Tidak ada playlist dengan ID %d.\n", id);
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
            } 
        } else {
            invcommand();
        }
        EndInput();
        printf("========================================================================================================================================\n");
    }
    return 0;
}
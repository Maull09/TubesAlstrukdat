#include <stdio.h>
#include <time.h>
#include "console.h"

void welcome(){
    printf("Memuat WayangWave...\n");
    delay(2);
    char *welcomingtext = "./data/welcoming_text.txt";
    FILE *ff = NULL;
    ff = fopen(welcomingtext, "r");

    if (ff == NULL) {
        perror("Error opening file");
        return;
    }

    char baca_str[255];
    while(fgets(baca_str, sizeof(baca_str), ff) != NULL) {
        printf("%s",baca_str);
    }
    printf("\n");

    fclose(ff);
}

void menu(){
    printf("========================================================[ Main Menu WayangWave ]=========================================================\n\n");
    printf("1. START\n");
    printf("2. LOAD [filename.txt]\n");
    printf("3. HELP\n");
    printf("0. QUIT\n");
    printf("=========================================================================================================================================\n");
}

void help(boolean sesi, boolean login) {
    if ((!sesi) && (!login)) {
        printf("========================================================[ Menu Help WayangWave =========================================================\n\n");
        printf("1. START\t\t-> Untuk memulai aplikasi WayangWave.\n");
        printf("2. LOAD <filename>\t-> Untuk memulai aplikasi WayangWave berdasarkan file yang kamu simpan.\n");
        printf("3. HELP\t\t\t-> Menunjukkanmu list command command yang tersedia di WayangWave dan kegunaannya.\n");
        printf("4. QUIT\t\t\t-> Untuk keluar dari aplikasi WayangWave\n\n");
    }
    else if ((sesi) && (!login)) {
        printf("========================================================[ Menu Help WayangWave =========================================================\n\n");
        printf("1. LOGIN\t-> Untuk masuk ke akun WayangWave milikmu.\n");
        printf("2. REGISTER\t-> Untuk membuat akun baru di WayangWave.\n");
        printf("3. LOGOUT\t-> Untuk keluar dari akun WayangWave milikmu.\n");
        printf("4. HELP\t\t-> Menunjukkanmu list command command yang tersedia di WayangWave dan kegunaannya.\n");
        printf("5. QUIT\t\t-> Untuk keluar dari aplikasi WayangWave\n\n");
    }
    else if ((sesi) && (login)) {
        printf("========================================================[ Menu Help WayangWave ]========================================================\n\n");
        printf("1.  LIST DEFAULT\t\t-> Untuk melihat list penyanyi yang ada dan dapat memilih untuk melihat album dan lagu dari penyanyi yang dipilih.\n");
        printf("2.  LIST PLAYLIST\t\t-> Untuk menampilkan playlist yang ada di aplikasi WayangWave kamu.\n");
        printf("3.  PLAY SONG\t\t\t-> Untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu yang kamu inginkan.\n");
        printf("4.  PLAY PLAYLIST\t\t-> Untuk memainkan lagu berdasarkan id playlist yang kamu inginkan.\n");
        printf("5.  QUEUE SONG\t\t\t-> Untuk menambahkan lagu ke dalam queue.\n");
        printf("6.  QUEUE PLAYLIST\t\t-> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue.\n");
        printf("7.  QUEUE SWAP <x> <y>\t\t-> Untuk menukar lagu pada urutan ke x dan juga urutan ke y.\n");
        printf("8.  QUEUE REMOVE <id>\t\t-> Untuk menghapus lagu dari queue sesuai id lagu yang kamu inginkan.\n");
        printf("9.  QUEUE CLEAR\t\t\t-> Untuk mengosongkan queue\n");
        printf("10. SONG NEXT\t\t\t -> Untuk memutar lagu yang berada di dalam queue.\n");
        printf("11. SONG PREVIOUS\t\t -> Untuk memutar lagu yang terakhir kali diputar oleh kamu.\n");
        printf("12. PLAYLIST CREATE\t\t -> Untuk membuat playlist baru dan ditambahkan pada daftar playlistmu.\n");
        printf("13. PLAYLIST ADD\t\t -> Untuk menambahkan lagu pada suatu playlist yang telah ada sebelumnya pada daftar playlistmu.\n");
        printf("14. PLAYLIST SWAP <id> <x> <y>\t -> Untuk menukar lagu pada urutan ke x dan juga urutan ke y di playlist dengan urutan ke id.\n");
        printf("15. PLAYLIST REMOVE <id> <n>\t -> Untuk menghapus lagu dengan urutan n pada playlist dengan id yang kamu inginkan.\n");
        printf("16. PLAYLIST DELETE\t\t -> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna.\n");
        printf("17. STATUS\t\t\t -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar.\n");
        printf("18. SAVE <filename>\t\t -> Untuk menyimpan state WayangWave terbaru ke dalam file yang kamu inginkan.\n");
        printf("19. FOLLOW\t\t\t-> Untuk mengikuti akun orang lain yang kamu inginkan.\n");
        printf("20. UNFOLLOW\t\t\t-> Untuk berhenti mengikuti akun orang lain yang kamu inginkan.\n");
        printf("21. FOLLOWERS\t\t\t-> Untuk melihat daftar akun orang lain yang mengikuti akunmu.\n");
        printf("22. FOLLOWING\t\t\t-> Untuk melihat daftar akun orang lain yang kamu ikuti.\n");
        printf("23. LOGOUT\t\t\t-> Untuk keluar dari akun WayangWave milikmu.\n");
        printf("24. HELP\t\t\t -> Menunjukkanmu list command command yang tersedia di WayangWave dan kegunaannya.\n");
        printf("25. QUIT\t\t\t -> Untuk keluar dari aplikasi WayangWave.\n\n");
    }
}

void invcommand(){
    printf("Command tidak diketahui!\n");
    EndInput();
}

void EndInput(){
    while (currentChar != MARK){
        ADVINPUT();
    }
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void FUNCSTART(ListSinger *DaftarPenyanyi, MapAlbum *SingerAlbum, MapSong *SongAlbum, ListMapAlbum *KumpulanAlbumSinger, ListMapSong *KumpulanLaguAlbum, SetSong *KumpulanLagu, arrofuser *users) {
    STARTKALIMATFILE("./data/config.txt");
    int jumlahPenyanyi = atoi(CKalimat.TabKalimat);  // Convert ke integer
    DaftarPenyanyi->Neff = jumlahPenyanyi;


    for (int i = 0; i < DaftarPenyanyi->Neff; i++) {
        ADVKALIMATFILE2();  // Baca Jumlah Album
        int jumlahAlbum = atoi(CKalimat.TabKalimat);  // Convert ke integer
        SingerAlbum->Neff = jumlahAlbum;
        ADVKALIMATFILE();  // Baca nama penyanyi
        SalinString(DaftarPenyanyi->singers[i].singerName, CKalimat.TabKalimat);
        SalinString(SingerAlbum->SingerName, CKalimat.TabKalimat);


        for (int j = 0; j < jumlahAlbum; j++){
            ADVKALIMATFILE2();  // Baca jumlah lagu dalam album
            int jumlahLagu = atoi(CKalimat.TabKalimat);  // Convert ke integer
            KumpulanLagu->Neff = jumlahLagu;

            ADVKALIMATFILE(); // Baca Nama album
            SalinString(SingerAlbum->albums[j].albumName, CKalimat.TabKalimat);
            SalinString(SongAlbum->albumName, CKalimat.TabKalimat);

        
            for (int k = 0; k < jumlahLagu; k++) {
                ADVKALIMATFILE();  // Baca judul lagu
                SalinString(KumpulanLagu->songs[k].songName, CKalimat.TabKalimat);
            }
            
            AddSetSongToMapSong(SongAlbum, *KumpulanLagu);
            InsertListMapSong(KumpulanLaguAlbum, *SongAlbum);
        }
        InsertListMapAlbum(KumpulanAlbumSinger, *SingerAlbum);
    }

    ADVKALIMATFILE3();
    int jumlahuser = atoi(CKalimat.TabKalimat);

    for(int z = 0; z < jumlahuser; z++){
        ADVKALIMATFILE();
        infouser dummyuser = CreateUser(CKalimat.TabKalimat);
        InsertUser(users, dummyuser);
    }

    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
    // displaySinger(DaftarPenyanyi);
    // DisplayListMapAlbum(KumpulanAlbumSinger);
    // DisplayListMapSong(KumpulanLaguAlbum);

}


void Load(char *filename,ListSinger *DaftarPenyanyi, MapAlbum *SingerAlbum, MapSong *SongAlbum, ListMapAlbum *KumpulanAlbumSinger, ListMapSong *KumpulanLaguAlbum, SetSong *KumpulanLagu, QueueLagu *qLagu, StackSong *sLagu, ArrayPlaylists *arrPlaylist, boolean *adafile, Lagu *cSong, arrofuser *users, Graph *g){
    char* pathdata = "./data/";
    char* combinepath = concat(pathdata, filename);
    STARTKALIMATFILE2(combinepath);
    if (CKalimat.TabKalimat[0] == MARK2 && CKalimat.Length == 0){
        *adafile = false;
    } else {
        *adafile = true;
        int jumlahPenyanyi = atoi(CKalimat.TabKalimat);  // Convert ke integer
        DaftarPenyanyi->Neff = jumlahPenyanyi;


        for (int i = 0; i < DaftarPenyanyi->Neff; i++) {
            ADVKALIMATFILE2();  // Baca Jumlah Album
            int jumlahAlbum = atoi(CKalimat.TabKalimat);  // Convert ke integer
            SingerAlbum->Neff = jumlahAlbum;
            ADVKALIMATFILE();  // Baca nama penyanyi
            SalinString(DaftarPenyanyi->singers[i].singerName, CKalimat.TabKalimat);
            SalinString(SingerAlbum->SingerName, CKalimat.TabKalimat);

            int samesong = 0;
            for (int j = 0; j < jumlahAlbum; j++){
                ADVKALIMATFILE2();  // Baca jumlah lagu dalam album
                int jumlahLagu = atoi(CKalimat.TabKalimat);  // Convert ke integer
                KumpulanLagu->Neff = jumlahLagu;

                ADVKALIMATFILE(); // Baca Nama album
                SalinString(SingerAlbum->albums[j].albumName, CKalimat.TabKalimat);
                SalinString(SongAlbum->albumName, CKalimat.TabKalimat);

            
                int indeksLagu = 0; 
                for (int k = 0; k < jumlahLagu; k++) {
                    ADVKALIMATFILE();  // Baca judul lagu
                    if(!IsSongInSet(*KumpulanLagu, CKalimat.TabKalimat)){
                        SalinString(KumpulanLagu->songs[indeksLagu].songName, CKalimat.TabKalimat);
                        indeksLagu++;  
                    } else {
                        samesong++;  
                    }
                }
                KumpulanLagu->Neff = indeksLagu;  // Atur jumlah lagu yang sebenarnya di array
                AddSetSongToMapSong(SongAlbum, *KumpulanLagu);
                InsertListMapSong(KumpulanLaguAlbum, *SongAlbum);
            }
            InsertListMapAlbum(KumpulanAlbumSinger, *SingerAlbum);
        }

        ADVKALIMATFILE3();
        int jumlahuser = atoi(CKalimat.TabKalimat);

        for(int z = 0; z < jumlahuser; z++){
            ADVKALIMATFILE3();
            char dummynamauser[100];
            SalinString(dummynamauser, CKalimat.TabKalimat);
            infouser dummyuser = CreateUser(dummynamauser);
            InsertUser(users, dummyuser);
            insertNode(g, dummynamauser);
            ADVKALIMATFILE3();
            int jumlahfollowers = atoi(CKalimat.TabKalimat);
            ADVKALIMATFILE3();
            int jumlahfollowing = atoi(CKalimat.TabKalimat);
            if (jumlahfollowers > 0) {
                for (int i = 0; i < jumlahfollowers; i++) {
                    ADVKALIMATFILE();
                    char follower[100];
                    SalinString(follower, CKalimat.TabKalimat);
                    insertEdge(g, follower, dummynamauser);
                }
            }
            if (jumlahfollowing > 0) {
                for (int i = 0; i < jumlahfollowing; i++) {
                    ADVKALIMATFILE();
                    char following[100];
                    SalinString(following, CKalimat.TabKalimat);
                    insertEdge(g, dummynamauser, following);
                }
            }
        }

        for(int x = 0; x < jumlahuser; x++){
            ADVKALIMATFILE3();
            if(!StringSama(CKalimat.TabKalimat, "-")){
                SalinString(cSong->artist ,CKalimat.TabKalimat);
                ADVKALIMATFILE3();
                SalinString(cSong->album ,CKalimat.TabKalimat);
                ADVKALIMATFILE3();
                SalinString(cSong->titlesong ,CKalimat.TabKalimat);
            }

            users->user[x].currentsong = *cSong;

            ADVKALIMATFILE();
            int jumlahqueue = atoi(CKalimat.TabKalimat);

            if(jumlahqueue != 0){
                for(int l = 0; l < jumlahqueue; l++){
                    ElTypeQueue tempq;
                    ADVKALIMATFILE3();
                    SalinString(tempq.artist ,CKalimat.TabKalimat);
                    ADVKALIMATFILE3();
                    SalinString(tempq.album ,CKalimat.TabKalimat);
                    ADVKALIMATFILE3();
                    SalinString(tempq.titlesong ,CKalimat.TabKalimat);
                    enqueue(qLagu, tempq);
                }
            }

            users->user[x].queue = *qLagu;

            ADVKALIMATFILE();
            int jumlahriwayat = atoi(CKalimat.TabKalimat);
            if (jumlahriwayat != 0){
                sLagu->TOP = jumlahriwayat-1;
                for(int m = 0; m < jumlahriwayat; m++){
                    ADVKALIMATFILE3();
                    SalinString(sLagu->Songs[m].artist, CKalimat.TabKalimat);
                    ADVKALIMATFILE3();
                    SalinString(sLagu->Songs[m].album, CKalimat.TabKalimat);
                    ADVKALIMATFILE3();
                    SalinString(sLagu->Songs[m].titlesong, CKalimat.TabKalimat);
                }
            }

            users->user[x].history = *sLagu;

            ADVKALIMATFILE();
            int jumlahplaylist = atoi(CKalimat.TabKalimat);
            Playlist dummyplaylist;
            if (jumlahplaylist != 0){
                for(int n = 0; n < jumlahplaylist; n++){
                    CreateEmpty(&dummyplaylist.laguplaylist);

                    ADVKALIMATFILE2();
                    int jumlahlagu = atoi(CKalimat.TabKalimat);

                    ADVKALIMATFILE(); // Baca nama playlist 
                    SalinString(dummyplaylist.name, CKalimat.TabKalimat);
                    // printf("Nama Playlist %d : %s\n", n+1, CKalimat.TabKalimat);
                    
                    for(int o = 0; o < jumlahlagu; o++){
                        infotype dummylagu;
                        ADVKALIMATFILE3(); // baca nama artis
                        // printf("Nama Artis Lagu %d playlist %d : %s\n", o+1, n+1, CKalimat.TabKalimat);
                        SalinString(dummylagu.artist, CKalimat.TabKalimat);
                        
                        ADVKALIMATFILE3(); // baca nama album
                        // printf("Nama Album Lagu %d playlist %d : %s\n", o+1, n+1, CKalimat.TabKalimat);
                        SalinString(dummylagu.album, CKalimat.TabKalimat);
                        
                        ADVKALIMATFILE3(); // baca nama lagu
                        // printf("Nama Lagu %d playlist %d : %s\n", o+1, n+1, CKalimat.TabKalimat);
                        SalinString(dummylagu.titlesong, CKalimat.TabKalimat);
                        
                        InsVLast(&dummyplaylist.laguplaylist, dummylagu);
                    }
                    AddPlaylist(arrPlaylist, dummyplaylist);
                    // printf("%s", currentWord.TabWord);
                    // PrintInfo(arrPlaylist->playlists[n].laguplaylist);
                }
            }
            users->user[x].arrp = *arrPlaylist;
            CreateQueue(qLagu);
            CreateEmptyStackSong(sLagu);
            CreateEmptyArrayPlaylists(arrPlaylist);
            CreateLagu(cSong);
        }

        // printf("Penyanyi :\n");
        // displaySinger(DaftarPenyanyi);
        // printf("Singer Album : \n");
        // DisplayListMapAlbum(KumpulanAlbumSinger);
        // printf("Album Lagu : \n");
        // DisplayListMapSong(KumpulanLaguAlbum);
        // printf("queue\n");
        // displayQueue(*qLagu);
        // printf("stack\n");
        // displayStack(sLagu);
        // printf("Playlist\n");
        // DisplayPlaylist(arrPlaylist);
        // for(int kl = 0; kl < arrPlaylist->Neff; kl++){
        //     PrintInfo(arrPlaylist->playlists[kl].laguplaylist);
        // }
    }
}


void ListDefault(ListSinger *listpenyanyi, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong){
    printf("\n");
    displaySinger(listpenyanyi);
    printf("\n");

    char choice[1];
    char SelectedArtist[100];
    char SelectedAlbum[100];
    printf("Ingin melihat album yang ada?(Y/N): ");
    
    STARTINPUT();
    SalinString(choice, currentWord.TabWord);
    
    if (StringSama(choice, "Y") || StringSama(choice, "y")){
        printf("Pilih penyanyi untuk melihat album mereka : ");
        STARTINPUT2();
        SalinString(SelectedArtist, currentWord.TabWord);

        if(FindSinger(*listpenyanyi, SelectedArtist)){
            printf("\n");
            FindAlbum_SingerName(*arrmapalbum, SelectedArtist); 
            printf("\n");
            
            printf("Ingin melihat lagu yang ada?(Y/N) : ");    
            STARTINPUT();
            SalinString(choice, currentWord.TabWord);

            if (StringSama(choice, "Y") || StringSama(choice, "y")){
                printf("Pilih album untuk melihat lagu yang ada di album : ");
                STARTINPUT2();
                SalinString(SelectedAlbum, currentWord.TabWord);

                if (FindSongAlbumName(*arrmapsong, SelectedAlbum)){
                    printf("\n");
                    printf("Daftar Lagu di %s\n", SelectedAlbum);
                    FindSong_AlbumName(*arrmapsong, SelectedAlbum);

                } else {
                    printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedAlbum);
                }
            } else if (StringSama(choice, "N") || StringSama(choice, "n")){
                return;
            } else {
                printf("Input tidak valid, silahkan coba lagi.\n");
            }
        }else {
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedArtist);
        }  
    } else if (StringSama(choice, "N") || StringSama(choice, "n")){
        return;
    } else {
        printf("Input tidak valid, silahkan coba lagi.\n");
    }
}

void PlaySong(ListSinger *listpenyanyi, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, Lagu *putar, QueueLagu *qLagu, StackSong *sLagu){
    printf("\n");
    displaySinger(listpenyanyi);
    printf("\n");

    char SelectedArtist[100];
    char SelectedAlbum[100];
    
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTINPUT2();
    SalinString(SelectedArtist, currentWord.TabWord);

    if(FindSinger(*listpenyanyi, SelectedArtist)){
        printf("\n");
        FindAlbum_SingerName(*arrmapalbum, SelectedArtist); 
        printf("\n");
        printf("Masukkan Nama Album yang dipilih : ");
        STARTINPUT2();
        SalinString(SelectedAlbum, currentWord.TabWord);

        if (FindSongAlbumName(*arrmapsong, SelectedAlbum)){
            printf("\n");
            printf("Daftar Lagu Album %s oleh %s :  \n", SelectedAlbum, SelectedArtist);
            FindSong_AlbumName(*arrmapsong, SelectedAlbum);

            printf("\nMasukkan ID Lagu yang dipilih : ");
            STARTINPUT();

            if(!isNumber(currentWord.TabWord)){
                printf("Input tidak valid, silahkan coba lagi.\n");
                return;
            }

            int idlagu = atoi(currentWord.TabWord);
            if (valid_idsong(*arrmapsong, idlagu, SelectedAlbum)){
                FindSong_IDsong(*arrmapsong, SelectedAlbum, idlagu, putar);
                printf("\n");
                printf("Memutar lagu \"%s\" oleh \"%s\".\n",putar->titlesong ,SelectedArtist);
                SalinString(putar->artist, SelectedArtist);
                SalinString(putar->album, SelectedAlbum);
                CreateQueue(qLagu);
                clearStack(sLagu);
            } else {
                printf("Tidak ada lagu dengan id %d, silahkan coba lagi\n", idlagu);
            }
        } else {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedAlbum);
        }         
    }else {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedArtist);
    } 
}

void QueueSong(ListSinger *listpenyanyi, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, QueueLagu *qSong){
    Lagu Putar;
    printf("\n");
    displaySinger(listpenyanyi);

    char SelectedArtist[100];
    char SelectedAlbum[100];
    
    printf("\nMasukkan Nama Penyanyi: ");
    STARTINPUT2();
    SalinString(SelectedArtist, currentWord.TabWord);
    SalinString(Putar.artist, SelectedArtist);

    if(FindSinger(*listpenyanyi, SelectedArtist)){
        printf("\n");
        FindAlbum_SingerName(*arrmapalbum, SelectedArtist); 
        
        printf("\nMasukkan Nama Album yang dipilih : ");
        STARTINPUT2();
        SalinString(SelectedAlbum, currentWord.TabWord);
        SalinString(Putar.album, SelectedAlbum);

        if (FindSongAlbumName(*arrmapsong, SelectedAlbum)){
            printf("\nDaftar Lagu Album %s oleh %s\n", SelectedArtist, SelectedArtist);
            FindSong_AlbumName(*arrmapsong, SelectedAlbum);

            printf("\nMasukkan ID Lagu yang dipilih : ");
            STARTINPUT();
            int idlagu = atoi(currentWord.TabWord);
            if (valid_idsong(*arrmapsong, idlagu, SelectedAlbum)){
                FindSong_IDsong(*arrmapsong, SelectedAlbum, idlagu, &Putar);        
                enqueue(qSong ,Putar);
                printf("\nBerhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n",Putar.titlesong,SelectedArtist);
            } else {
                printf("Tidak ada lagu dengan id %d, silahkan coba lagi\n", idlagu);
            }
            
        } else {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedAlbum);
        }
    }else {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedArtist);
    }
}

int playlistContainingQueue(QueueLagu *q, ArrayPlaylists *arrPlaylists, Lagu *playing) {
    for (int i = 0; i < arrPlaylists->Neff; i++) {
        Playlist pl = arrPlaylists->playlists[i];
        int foundCount = 0;  

        for (int j = q->idxHead; j != q->idxTail+1; j = (j + 1) % CAPACITY) {
            boolean foundInPlaylist = false;
            
            address current = pl.laguplaylist.First;
            while (current != NULL) {
                if (StringSama(q->buffer[j].titlesong, current->info.titlesong) &&
                    StringSama(q->buffer[j].album, current->info.album) &&
                    StringSama(q->buffer[j].artist, current->info.artist)) {
                    foundInPlaylist = true;
                    break;
                }
                current = Next(current);
            }
            
            if (foundInPlaylist) {
                foundCount++;  
            }
        }

        if (foundCount == lengthQueue(*q)) {
            boolean isPlayingInPlaylist = false;
            address current = pl.laguplaylist.First;
            while (current != NULL) {
                if (StringSama(playing->titlesong, current->info.titlesong) &&
                    StringSama(playing->album, current->info.album) &&
                    StringSama(playing->artist, current->info.artist)) {
                    isPlayingInPlaylist = true;
                    break;
                }
                current = Next(current);
            }

            if (isPlayingInPlaylist) {
                return i; 
            }
        }
    }
    return -1;  
}

void STATUS(Lagu *playing, QueueLagu *antrian, ArrayPlaylists *arrPlaylists, StackSong *history, char user[], boolean playplaylist){

    printf("Username : %s\n", user);

    int index = playlistContainingQueue(antrian, arrPlaylists, playing);
    if (index != -1 && playplaylist) {
        printf("\nCurrent Playlist: %s\n", arrPlaylists->playlists[index].name);
    } 

    printf("\nNow Playing: \n");
    if (StringSama(playing->titlesong, "\0") && StringSama(playing->artist, "\0") && StringSama(playing->album, "\0")){
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    } else {
        printf("%s - %s - %s\n",playing->artist,playing->album,playing->titlesong);
    }
    
    printf("\nQueue:\n");
    if (isEmptyQueue(*antrian)){
        printf("Your queue is empty.\n");
    }
    else{
        displayQueue(antrian);
    }

    printf("\nHistori : \n");
    if(!IsEmptyStackSong(*history)){
        displayStack(history);
    } else {
        printf("Your history is empty.\n");
    }
}


void enhance(ListSinger *DaftarPenyanyi, ListMapAlbum *LMA, ListMapSong *LMS, ArrayPlaylists *arrplaylist, char namaplaylist[]){
    infotype dummylagu;
    int acak;
    acak = (rand() % 9) + 1;
    int iterate;
    int idxplaylist = IdPlaylist(arrplaylist, namaplaylist);
    printf("\nPlaylist \"%s\" sebelum dienhance : \n", arrplaylist->playlists[idxplaylist].name);
    PrintInfo(arrplaylist->playlists[idxplaylist].laguplaylist);
    printf("\nProses Enhance dimulai\n");
    delay(3);
    printf("\nPlaylist %s akan ditambahkan %d Lagu\n", namaplaylist, acak);

    for(iterate = 0; iterate < acak; iterate++){
        boolean isAdded = false;
        do {
            delay(3);
            // printf("\nMencari penyanyi...\n");
            // delay(3);
            int singerIdx = rand() % DaftarPenyanyi->Neff;
            SalinString(dummylagu.artist, DaftarPenyanyi->singers[singerIdx].singerName);
            // printf("\nArtis %s telah dipilih\n", dummylagu.artist);
            // printf("\nMencari album...\n");
            // delay(3);

            int albumIdx;
            for (int i = 0; i < LMA->Neff; i++) {
                if (StringSama(LMA->MapAlbums[i].SingerName, dummylagu.artist)) {
                    albumIdx = rand() % LMA->MapAlbums[i].Neff;
                    SalinString(dummylagu.album, LMA->MapAlbums[i].albums[albumIdx].albumName);           
                }
            }
            // printf("\nAlbum %s telah dipilih\n", dummylagu.album);
            // printf("\nMencari lagu...\n");
            // delay(3);

            int songIdx;
            for (int i = 0; i < LMS->Neff; i++) {
                if (StringSama(LMS->MapSongs[i].albumName, dummylagu.album)) {
                    songIdx = rand() % LMS->MapSongs[i].songs.Neff;
                    SalinString(dummylagu.titlesong, LMS->MapSongs[i].songs.songs[songIdx].songName);
                }
            }

            // printf("\nLagu %s telah dipilih\n", dummylagu.titlesong);
            printf("\nMenambahkan lagu %s dalam album %s oleh %s ke playlist %s", dummylagu.titlesong, dummylagu.album, dummylagu.artist, namaplaylist);
            delay(1);

            int i = 0;
            while(i < arrplaylist->Neff && !isAdded){
                if(StringSama(arrplaylist->playlists[i].name, namaplaylist)){
                    if(!Search(arrplaylist->playlists[i].laguplaylist, dummylagu)){
                        InsVLast(&arrplaylist->playlists[i].laguplaylist, dummylagu);
                        isAdded = true;
                    } else {
                        printf("\nLagu %s Album %s Oleh %s telah ada dalam playlist %s\n", dummylagu.titlesong, dummylagu.album, dummylagu.artist, namaplaylist);
                        printf("\nMengulang proses pemilihan...\n");
                    }
                }
                i++;
            }
        } while (!isAdded); 
    }
    printf("\n");
    printf("\nPlaylist \"%s\" setelah dienhance : \n", arrplaylist->playlists[idxplaylist].name);
    PrintInfo(arrplaylist->playlists[idxplaylist].laguplaylist);
}


boolean playlist_valid(ArrayPlaylists *arrPlaylist, char nameplaylist[]){
    for (int i = 0; i < arrPlaylist->Neff; i++){
        if(StringSama(arrPlaylist->playlists[i].name, nameplaylist)){
            return true;
        }
    }
    return false;
}

void PlayPlaylist(ArrayPlaylists *arrPlaylist, StackSong *sLagu, QueueLagu *qLagu, int idxarr){
    ElTypeQueue dummyq;
    Lagu dummyL;

    if(FindPlaylist(*arrPlaylist, idxarr)){
        clearStack(sLagu);
        while (!isEmptyQueue(*qLagu)){
            dequeue(qLagu, &dummyq);
            PushStackSong(sLagu, dummyq);
        }

        address P = First(arrPlaylist->playlists[idxarr-1].laguplaylist);
        while (P != Nil){
            SalinLagu(&dummyL, Info(P));
            enqueue(qLagu, dummyL);
            P = Next(P);
        }
    }
}

void QueuePlaylist(ArrayPlaylists *arrPlaylist, QueueLagu *qLagu, int idxarr){
    ElTypeQueue dummyq;
    Lagu dummyL;

    if(FindPlaylist(*arrPlaylist, idxarr)){
        address P = First(arrPlaylist->playlists[idxarr-1].laguplaylist);
        while (P != Nil){
            SalinLagu(&dummyL, Info(P));
            enqueue(qLagu, dummyL);
            P = Next(P);
        }
    }
}

void PlaylistCreate(ArrayPlaylists *arrPlaylist, char playlistname[]){
    Playlist dummyP;
    SalinString(dummyP.name, playlistname);
    CreateEmpty(&dummyP.laguplaylist);
    AddPlaylist(arrPlaylist, dummyP);
    printf("Playlist %s berhasil dibuat!\n", playlistname);
    printf("Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
}

void PlaylistDelete(ArrayPlaylists *arrPlaylist, int idxP){
    for (int i = idxP-1; i<arrPlaylist->Neff; i++){
        arrPlaylist->playlists[i] = arrPlaylist->playlists[i+1];
    }
    arrPlaylist->Neff -= 1;
}


void PlaylistRemove(ArrayPlaylists *arrPlaylist, int idxP, int idxL){
    int ctr = 0;
    boolean found = false;
    address p = First(arrPlaylist->playlists[idxP-1].laguplaylist);
    address prev = NULL;

    while(p != NULL && !found){
        if(ctr == idxL-1){
            if (prev == NULL) {
                DelFirst(&arrPlaylist->playlists[idxP-1].laguplaylist, &p);
                printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"!\n", titlesong(p), artist(p), arrPlaylist->playlists[idxP-1].name);
            } else {
                DelAfter(&arrPlaylist->playlists[idxP-1].laguplaylist, &p, prev);
                printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"!\n", titlesong(p), artist(p), arrPlaylist->playlists[idxP-1].name);
            }
            found = true;
        } else {
            ctr++;
            prev = p; 
            p = Next(p);
        }
    }
}

void playlistSwap(ArrayPlaylists *arrP, int idx, int idy, int idPlaylist) {
    if (idx <= 0 || idy <= 0) {
        printf("Indeks tidak valid.\n");
        return;
    }
    
    if(idx == idy){
        printf("Lagu yang ditukar adalah lagu dengan indeks yang sama\n");
        return;
    }


    int ctr = 0;
    Lagu tempx, tempy;
    address x = NULL, y = NULL;
    address p = First(arrP->playlists[idPlaylist-1].laguplaylist);
    
    while(p != NULL && (ctr < idx || ctr < idy)) {
        if(ctr == idx-1) {
            x = p;
            tempx = Info(x);
        } else if(ctr == idy-1) {
            y = p;
            tempy = Info(y);
        }
        ctr++;
        p = Next(p);
    }

    if (x != NULL && y != NULL) {
        Info(x) = tempy;
        Info(y) = tempx;
        printf("Berhasil menukar lagu dengan nama \"%s\" dengan \"%s\" di playlist \"%s\".\n", tempx.titlesong, tempy.titlesong, arrP->playlists[idPlaylist-1].name);
    } else {
        printf("Gagal menukar lagu: Indeks di luar batas.\n");
    }
}


void playlistAddSong(ArrayPlaylists *arr, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, ListSinger *listpenyanyi){
    Lagu Putar;
    displaySinger(listpenyanyi);
    printf("\n");

    char SelectedArtist[100];
    char SelectedAlbum[100];

    printf("Masukkan Nama Penyanyi yang dipilih : ");

    STARTINPUT2();
    SalinString(SelectedArtist, currentWord.TabWord);
    SalinString(Putar.artist, SelectedArtist);
    printf("\n");

    if(FindSinger(*listpenyanyi, SelectedArtist)){
        FindAlbum_SingerName(*arrmapalbum, SelectedArtist); 
        printf("\n");
        
        printf("Masukkan Judul Album yang dipilih : ");
        
        STARTINPUT2();
        SalinString(SelectedAlbum, currentWord.TabWord);
        SalinString(Putar.album, SelectedAlbum);
        printf("\n");

        if (FindSongAlbumName(*arrmapsong, SelectedAlbum)){
            printf("Daftar Lagu Album %s oleh %s : \n", Putar.album, Putar.artist);
            FindSong_AlbumName(*arrmapsong, SelectedAlbum);
            printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            STARTINPUT();

            if(!isNumber(currentWord.TabWord)){
                printf("Input tidak valid, silahkan coba lagi.\n");
                return;
            }

            int idlagu = atoi(currentWord.TabWord);
            printf("\n");

            if (valid_idsong(*arrmapsong, idlagu, SelectedAlbum)){
                FindSong_IDsong(*arrmapsong, SelectedAlbum, idlagu, &Putar);        

                printf("Daftar Playlist Pengguna : \n");
                DisplayPlaylist(arr);
                printf("\n");

                printf("Masukkan ID Playlist yang dipilih : ");
                STARTINPUT();
                printf("\n");

                if(!isNumber(currentWord.TabWord)){
                    printf("Input tidak valid, silahkan coba lagi.\n");
                    return;
                }

                int idplaylist = atoi(currentWord.TabWord);
                if(isValidPlaylist(arr, idplaylist)){
                    InsVLast(&arr->playlists[idplaylist-1].laguplaylist, Putar);
                    printf("Lagu dengan judul \"%s\" pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist \"%s\" \n.", Putar.titlesong ,SelectedAlbum, SelectedArtist, arr->playlists[idplaylist-1].name );
                }
                else{
                    printf("Playlist dengan id:%d tidak ada dalam daftar. Silakan coba lagi.\n", idplaylist);
                }
            } else {
                printf("Tidak ada lagu dengan id %d, silahkan coba lagi\n", idlagu);
            }
            
        } else {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedAlbum);
        }
            
    }else {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedArtist);
    }
        
}

void playlistAddAlbum(ArrayPlaylists *arr, ListMapAlbum *arrmapalbum, ListMapSong *arrmapsong, ListSinger *listpenyanyi){
    Lagu Putar;
    displaySinger(listpenyanyi);
    printf("\n");

    char SelectedArtist[100];
    char SelectedAlbum[100];
    
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTINPUT2();
    printf("\n");
    
    SalinString(SelectedArtist, currentWord.TabWord);
    SalinString(Putar.artist, SelectedArtist);

    if(FindSinger(*listpenyanyi, SelectedArtist)){
        FindAlbum_SingerName(*arrmapalbum, SelectedArtist); 
        printf("\n");
        
        printf("Masukkan Judul Album yang dipilih : ");
        STARTINPUT2();
        printf("\n");
        
        SalinString(SelectedAlbum, currentWord.TabWord);
        SalinString(Putar.album, SelectedAlbum);
        int idalbum;
        idalbum = idAlbum(arrmapsong, SelectedAlbum);
        if (FindSongAlbumName(*arrmapsong, SelectedAlbum)){
            printf("Daftar Playlist Pengguna : \n");
            DisplayPlaylist(arr);
            printf("\n");
            
            printf("Masukkan ID Playlist yang dipilih : ");
            STARTINPUT();
            printf("\n");
            
            if(!isNumber(currentWord.TabWord)){
                printf("Input tidak valid, silahkan coba lagi.\n");
                return;
            }

            int idplaylist = atoi(currentWord.TabWord);
            if(isValidPlaylist(arr, idplaylist)){
                for (int i = 0; i < arrmapsong->MapSongs[idalbum].songs.Neff; i++){
                    SalinString(Putar.titlesong, arrmapsong->MapSongs[idalbum].songs.songs[i].songName);
                    InsVLast(&arr->playlists[idplaylist-1].laguplaylist, Putar);
                }
                printf("Album dengan judul \"%s\" berhasil ditambahkan ke dalam pada playlist pengguna \"%s\".\n", SelectedAlbum,arr->playlists[idplaylist-1].name );
            } else {
                printf("Playlist dengan id:%d tidak ada dalam daftar. Silakan coba lagi.", idplaylist);
            }
        } else {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedAlbum);
        }
    }else {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", SelectedArtist);
    }
}



//==============================================================================================================/
// Implementasi fungsi
void CreateEmptyUsers(arrofuser *arr) {
    arr->neff = 0;
}

void InsertUser(arrofuser *arr, infouser user) {
    if (arr->neff < CAPACITY) {
        arr->user[arr->neff] = user;
        arr->neff++;
    } else {
        printf("Array of users is full.\n");
    }
}

infouser CreateUser(char username[]) {
    infouser user;
    SalinString(user.username, username);
    // Contoh:
    CreateQueue(&user.queue);
    CreateEmptyStackSong(&user.history);
    CreateEmptyArrayPlaylists(&user.arrp);
    CreateLagu(&user.currentsong);
    return user;
}

void DisplayUsers(const arrofuser *arr) {
    printf("User List:\n");
    for (int i = 0; i < arr->neff; i++) {
        printf("%d. %s\n", i + 1, arr->user[i].username);
    }
}

int FindUserIndex(arrofuser *users, char username[]) {
    for (int i = 0; i < users->neff; ++i) {
        if (StringSama(users->user[i].username, username)) {
            return i; // Username ditemukan pada index i
        }
    }
}

boolean FindIndexUser(arrofuser *users, char username[]) {
    for (int i = 0; i < users->neff; ++i) {
        if (StringSama(users->user[i].username, username)) {
            return true; // Username ditemukan pada index i
        }
    }
    return false;
}

// Follow User
void followUser(Graph *g, char followerUsername[], char followingUsername[]) {
    insertEdge(g, followerUsername, followingUsername);
}

// Unfollow User
void unfollowUser(Graph *g, char followerUsername[], char followingUsername[]) {
    adrNode P = searchNode(*g, followerUsername);
    if (P != NULL) {
        adrSuccNode Q = P->trail, prev = NULL;
        while (Q != NULL) {
            if (StringSama(Q->succ->username, followingUsername)) {
                if (prev == NULL) {
                    P->trail = Q->next;
                } else {
                    prev->next = Q->next;
                }
                deallocSuccNode(Q);
                break;
            }
            prev = Q;
            Q = Q->next;
        }
    }
}

// List Follower
void listFollower(Graph *g, char username[]) {
    boolean hasFollowers = false;
    int count = 1;
    printf("Daftar follower %s:\n", username);
    for (adrNode P = g->first; P != NULL; P = P->next) {
        for (adrSuccNode Q = P->trail; Q != NULL; Q = Q->next) {
            if (StringSama(Q->succ->username, username)) {
                printf("%d. %s\n",count, P->username);
                count++;
                hasFollowers = true;
            }
        }
    }
    if (!hasFollowers) {
        printf("Tidak memiliki follower.\n");
    }
}


// List Following
void listFollowing(Graph *g, char username[]) {
    adrNode P = searchNode(*g, username);
    printf("Daftar following %s:\n", username);
    int count = 1;
    if (P != NULL && P->trail != NULL) {
        for (adrSuccNode Q = P->trail; Q != NULL; Q = Q->next) {
            printf("%d. %s\n",count, Q->succ->username);
            count++;
        }
    } else {
        printf("%s tidak mengikuti siapapun.\n", username);
    }
}

boolean isFollower(Graph g, char followerUsername[], char followingUsername[]) {
    adrNode P = searchNode(g, followerUsername);
    if (P != NULL) {
        for (adrSuccNode Q = P->trail; Q != NULL; Q = Q->next) {
            if (StringSama(Q->succ->username, followingUsername)) {
                return true;
            }
        }
    }
    return false;
}

int jumlahFollowers(Graph g, char username[]) {
    int count = 0;
    for (adrNode P = g.first; P != NULL; P = P->next) {
        for (adrSuccNode Q = P->trail; Q != NULL; Q = Q->next) {
            if (StringSama(Q->succ->username, username)) {
                count++;
            }
        }
    }
    return count;
}

int jumlahFollowing(Graph g, char username[]) {
    adrNode P = searchNode(g, username);
    int count = 0;
    if (P != NULL) {
        for (adrSuccNode Q = P->trail; Q != NULL; Q = Q->next) {
            count++;
        }
    }
    return count;
}
#include <stdio.h>
#include <time.h>
#include "console.h"

void welcome(){
    printf("Memuat WayangWave...\n");
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
    printf("\n\n========== MAIN MENU WayangWave==========\n");
    printf("1. START\n");
    printf("2. LOAD [filename.txt]\n");
    printf("3. HELP\n");
    printf("0. QUIT\n");
    printf("=============================================\n");
}

void help() {
    printf("===================================================================================================\n");
    printf("| QUIT -> Memungkinkanmu keluar dari program.                                                     |\n");
    printf("| HELP -> Bantuan untuk kamu yang kebingungan dengan command-command yang tersedia!               |\n");
    printf("==================================================================================================\n");
}

void invcommand(){
    printf("Gada commandnya\n");
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

void FUNCSTART(ListSinger *DaftarPenyanyi, MapAlbum *SingerAlbum, MapSong *SongAlbum, ListMapAlbum *KumpulanAlbumSinger, ListMapSong *KumpulanLaguAlbum, SetSong *KumpulanLagu) {
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
            SongAlbum->Neff = 1;
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

    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
    // displaySinger(*DaftarPenyanyi);
    // DisplayListMapAlbum(KumpulanAlbumSinger);
    // DisplayListMapSong(KumpulanLaguAlbum);

}


void Load(char *filename,ListSinger *DaftarPenyanyi, MapAlbum *SingerAlbum, MapSong *SongAlbum, ListMapAlbum *KumpulanAlbumSinger, ListMapSong *KumpulanLaguAlbum, SetSong *KumpulanLagu, QueueLagu *qLagu, StackSong *sLagu, ArrayPlaylists *arrPlaylist){
    char* pathdata = "./data/";
    char* combinepath = concat(pathdata, filename);
    STARTKALIMATFILE(combinepath);
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
            SongAlbum->Neff = 1;
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

    ADVKALIMATFILE();
    int jumlahqueue = atoi(CKalimat.TabKalimat);

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

    ADVKALIMATFILE();
    int jumlahriwayat = atoi(CKalimat.TabKalimat);
    sLagu->TOP = jumlahriwayat;
    for(int m = 0; m < jumlahriwayat; m++){
        ADVKALIMATFILE3();
        SalinString(sLagu->Songs[m].artist, CKalimat.TabKalimat);
        ADVKALIMATFILE3();
        SalinString(sLagu->Songs[m].album, CKalimat.TabKalimat);
        ADVKALIMATFILE3();
        SalinString(sLagu->Songs[m].titlesong, CKalimat.TabKalimat);
    }

    ADVKALIMATFILE();
    int jumlahplaylist = atoi(CKalimat.TabKalimat);
    Playlist dummyplaylist;

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
    }

    // printf("Penyanyi :\n");
    // displaySinger(*DaftarPenyanyi);
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


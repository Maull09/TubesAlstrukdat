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
    printf("Gada commandnya bjir\n");
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

void FUNCSTART(ListSinger *DaftarPenyanyi, MapAlbum *SingerAlbum, MapSong *SongAlbum) {
    STARTKALIMATFILE("./data/config.txt");
    int jumlahPenyanyi = atoi(CKalimat.TabKalimat);  // Convert ke integer
    DaftarPenyanyi->Neff = jumlahPenyanyi;
    
    for (int i = 0; i < DaftarPenyanyi->Neff; i++) {
        ADVKALIMATFILE2();  // Baca Jumlah Album
        int jumlahAlbum = atoi(CKalimat.TabKalimat);  // Convert ke integer
        SingerAlbum->Neff = jumlahAlbum;
        ADVKALIMATFILE();  // Baca nama penyanyi
        SalinString(DaftarPenyanyi->singers[i].singerName, CKalimat.TabKalimat);
        DaftarPenyanyi->singers[i].id = i+1;

        for (int j = 0; j < jumlahAlbum; j++){
            ADVKALIMATFILE2();  // Baca jumlah lagu dalam album
            int jumlahLagu = atoi(CKalimat.TabKalimat);  // Convert ke integer
            SongAlbum->Neff = jumlahLagu;
            ADVKALIMATFILE(); // Baca Nama album
            SalinString(SingerAlbum->albums[j].albumName, CKalimat.TabKalimat);
            SingerAlbum->albums[j].id = j+1;
            SingerAlbum->albums[j].singerID = i+1;
        
            for (int k = 0; k < jumlahLagu; k++) {
                ADVKALIMATFILE();  // Baca judul lagu
                SalinString(SongAlbum->songs[k].songName, CKalimat.TabKalimat);
                SongAlbum->songs[k].id = k+1;
                SongAlbum->songs[k].albumID = j+1;

            }
        }
    }
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
}

// void FUNCSTART() {
//     STARTKALIMATFILE("./data/config.txt");
//     int jumlahPenyanyi = atoi(CKalimat.TabKalimat);  // Convert ke integer
//     printf("Jumlah Penyanyi = %d\n", jumlahPenyanyi);
    
//     for (int i = 1; i <= jumlahPenyanyi; i++) {
//         ADVKALIMATFILE2();  // Baca Jumlah Album
//         int jumlahAlbum = atoi(CKalimat.TabKalimat);  // Convert ke integer
//         ADVKALIMATFILE();  // Baca nama penyanyi
//         printf("Jumlah Album %s : %d\n", CKalimat.TabKalimat, jumlahAlbum);
        
//         for (int j = 1; j <= jumlahAlbum; j++){
//             ADVKALIMATFILE2();  // Baca jumlah lagu dalam album
//             int jumlahLagu = atoi(CKalimat.TabKalimat);  // Convert ke integer
//             ADVKALIMATFILE(); // Baca Nama album
//             printf("Jumlah lagu album %s : %d\n", CKalimat.TabKalimat, jumlahLagu);
        
//             for (int k = 1; k <= jumlahLagu; k++) {
//                 ADVKALIMATFILE();  // Baca judul lagu
//                 printf("Lagu %d penyanyi %d : %s\n", k, i, CKalimat.TabKalimat);
//             }
//         }
//     }
//     printf("Selesai FUNCSTART\n");
// }

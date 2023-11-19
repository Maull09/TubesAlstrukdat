#include <stdio.h>
#include "help.h"

void help() {
    boolean sesi;
    boolean login;
    if ((!sesi) && (!login)) {
        printf("========================================================[ Menu Help WayangWave =========================================================\n\n");
        printf("1. START\t\t\t-> Untuk memulai aplikasi WayangWave.\n");
        printf("2. LOAD <filename>\t-> Untuk memulai aplikasi WayangWave berdasarkan file yang kamu simpan.\n");
        printf("3. HELP\t\t\t-> Menunjukkanmu list command command yang tersedia di WayangWave dan kegunaannya.\n");
        printf("4. QUIT\t\t\t-> Untuk keluar dari aplikasi WayangWave\n\n");
        printf("========================================================================================================================================\n\n");
    }
    else if ((sesi) && (!login)) {
        printf("========================================================[ Menu Help WayangWave =========================================================\n\n");
        printf("1. LOGIN\t-> Untuk masuk ke akun WayangWave milikmu.\n");
        printf("2. REGISTER\t-> Untuk membuat akun baru di WayangWave.\n");
        printf("3. LOGOUT\t-> Untuk keluar dari akun WayangWave milikmu.\n");
        printf("4. HELP\t-> Menunjukkanmu list command command yang tersedia di WayangWave dan kegunaannya.\n");
        printf("5. QUIT\t-> Untuk keluar dari aplikasi WayangWave\n\n");
        printf("========================================================================================================================================\n\n");
    }
    else if ((sesi) && (login)) {
        printf("========================================================[ Menu Help WayangWave ]========================================================\n\n");
        printf("1.  LIST DEFAULT\t\t-> Untuk melihat list penyanyi yang ada dan dapat memilih untuk melihat album dan lagu dari penyanyi yang dipilih.\n");
        printf("2.  LIST PLAYLIST\t\t-> Untuk menampilkan playlist yang ada di aplikasi WayangWave kamu.\n");
        printf("3.  PLAY SONG\t\t\t-> Untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu yang kamu inginkan.\n");
        printf("4.  PLAY PLAYLIST\t\t-> Untuk memainkan lagu berdasarkan id playlist yang kamu inginkan.\n");
        printf("5.  QUEUE SONG\t\t\t-> Untuk menambahkan lagu ke dalam queue.\n");
        printf("6.  QUEUE PLAYLIST\t\t-> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue.\n");
        printf("7.  QUEUE SWAP <x> <y>\t-> Untuk menukar lagu pada urutan ke x dan juga urutan ke y.\n");
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
        printf("19. HELP\t\t\t -> Menunjukkanmu list command command yang tersedia di WayangWave dan kegunaannya.\n");
        printf("20. QUIT\t\t\t -> Untuk keluar dari aplikasi WayangWave.\n\n");
        printf("========================================================================================================================================\n\n");
    }
}
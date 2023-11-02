void FUNCSTART() {
    STARTKALIMATFILE("./data/config.txt");
    int jumlahPenyanyi = atoi(CKalimat.TabKalimat);  // Convert ke integer
    printf("Jumlah Penyanyi = %d\n", jumlahPenyanyi);
    
    for (int i = 1; i <= jumlahPenyanyi; i++) {
        ADVKALIMATFILE2();  // Baca Jumlah Album
        int jumlahAlbum = atoi(CKalimat.TabKalimat);  // Convert ke integer
        ADVKALIMATFILE();  // Baca nama penyanyi
        printf("Jumlah Album %s : %d\n", CKalimat.TabKalimat, jumlahAlbum);
        
        for (int j = 1; j <= jumlahAlbum; j++){
            ADVKALIMATFILE2();  // Baca jumlah lagu dalam album
            int jumlahLagu = atoi(CKalimat.TabKalimat);  // Convert ke integer
            ADVKALIMATFILE(); // Baca Nama album
            printf("Jumlah lagu album %s : %d\n", CKalimat.TabKalimat, jumlahLagu);
        
            for (int k = 1; k <= jumlahLagu; k++) {
                ADVKALIMATFILE();  // Baca judul lagu
                printf("Lagu %d penyanyi %d : %s\n", k, i, CKalimat.TabKalimat);
            }
        }
    }
    printf("Selesai FUNCSTART\n");
}
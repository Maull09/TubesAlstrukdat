#include <stdio.h>
#include <stdlib.h>

#include "mesinkarakter.h"

char currentChar;
boolean EOP;

FILE *config;
static FILE *pita;
static int retval;

void START()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
{
    pita = stdin;
    ADV2();
}


void STARTFILE (char filename[]) {
    config = fopen(filename, "r");
    if (config != NULL) {
        ADV();
    } else {
        printf("\nFile tidak ditemukan!\n");
        printf("---------------------------------------------\n");
        exit(0);
    }
}

void STARTFILE2 (char filename[]) {
    config = fopen(filename, "r");
    if (config != NULL) {
        ADV();
    } else {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
    currentChar = fgetc(config);
    while (currentChar == '\r') { // Lewati karakter '\r'
        currentChar = fgetc(config);
    }

    if (currentChar == EOF) {
        EOP = true;
        fclose(config);
    } else {
        EOP = false;
    }
}

void ADV2()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita, "%c", &currentChar);
    while (currentChar == '\r') { // Lewati karakter '\r'
        retval = fscanf(pita, "%c", &currentChar);
    }
}
char GetCC()
/* Mengirimkan currentChar */
{
    return currentChar;
}

boolean IsEOP()
/* Mengirimkan true jika currentChar = MARK */
{
    return (currentChar == EOF);
}
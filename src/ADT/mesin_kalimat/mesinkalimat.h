/* File: mesinKalimat.h */
/* Definisi Mesin Kalimat: Model Akuisisi Versi I */
// 1 Kalimat pada ADT ini adalah 1 game

#ifndef __MESINKALIMAT_H__
#define __MESINKALIMAT_H__

#include "../boolean.h"
#include "../mesin_karakater/mesinkarakter.h"
#include "../mesin_kata/mesinkata.h"

#define KMax 450
#define NEWLINE '\n'
#define BLANK ' '

typedef struct {
  char TabKalimat[KMax+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat CKalimat;

void SalinKalimatFile();
void SalinKalimatFile2();
void SalinKalimatFile ();

void STARTKALIMATFILE(char filename[]);

void ADVKALIMATFILE();
void ADVKALIMATFILE2();

void copyKalimat (Kalimat k1, Kalimat *k2);
void ResetKalimat();
void IgnoreNewline();

#endif
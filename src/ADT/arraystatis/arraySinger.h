#ifndef LIST_SINGER_H
#define LIST_SINGER_H

#include "../boolean.h"
#include "../../function.h"

#define IdxMin 1
#define IdxUndef -999
#define MaxSingers 100

typedef struct {
    int id;
    char singerName[255];
} Singer;

typedef struct {
    Singer singers[MaxSingers];
    int Neff;   // Jumlah penyanyi sebenarnya
} ListSinger;

void CreateEmptyListSinger(ListSinger *L);
void InsertSinger(ListSinger *L, Singer s);
int FindSinger(ListSinger L, char singerName[]);

#endif

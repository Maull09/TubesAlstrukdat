#ifndef LIST_SINGER_H
#define LIST_SINGER_H

#include "../listadt.h"
#include "../../function.h"

void CreateEmptyListSinger(ListSinger *L);
void InsertSinger(ListSinger *L, Singer s);
int FindSinger(ListSinger L, char singerName[]);

#endif

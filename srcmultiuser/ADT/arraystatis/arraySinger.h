#ifndef LIST_SINGER_H
#define LIST_SINGER_H

#include "../listadt.h"
#include "../../function.h"

void CreateEmptyListSinger(ListSinger *L);
void InsertSinger(ListSinger *L, Singer s);
boolean FindSinger(ListSinger L, char singerName[]);
void displaySinger(ListSinger *LS);
int idArtis(ListSinger *arrS, char artisname[]);
#endif

#include "arraySinger.h"
#include <stdio.h>

void CreateEmptyListSinger(ListSinger *L) {
    L->Neff = 0;
}

void InsertSinger(ListSinger *L, Singer s) {
    if (L->Neff < MaxSingers) {
        L->singers[L->Neff] = s;
        L->Neff++;
    }
}

int FindSinger(ListSinger L, char singerName[]) {
    for (int i = 0; i < L.Neff; i++) {
        if (StringSama(L.singers[i].singerName, singerName)) {
            return i;
        }
    }
    return IdxUndef;  // tidak ditemukan
}

void displaySinger(ListSinger LS){
    for(int i = 0; i<LS.Neff;i++){
        printf("Nama Artis : %s", LS.singers[i].singerName);
    }
}
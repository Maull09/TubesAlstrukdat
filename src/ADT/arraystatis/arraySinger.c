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

boolean FindSinger(ListSinger L, char singerName[]) {
    for (int i = 0; i < L.Neff; i++) {
        if (StringSama(L.singers[i].singerName, singerName)) {
            return true;
        }
    }
    return false; 
}

void displaySinger(ListSinger *LS){
    printf("Daftar Penyanyi : \n");
    for(int i = 0; i<LS->Neff;i++){
        printf("\t%d. %s\n",i+1, LS->singers[i].singerName);
    }
}

// find artis
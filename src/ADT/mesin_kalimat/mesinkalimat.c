#include <stdio.h>
#include "mesinkalimat.h"

boolean EndKalimat;
Kalimat CKalimat;

void IgnoreNewline()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == NEWLINE)
    {
        ADV();
    }
}

void SalinKalimatFile() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != MARK2))
    {
        CKalimat.TabKalimat[i] = currentChar;
        // printf("%c", currentChar);
        i+= 1;
        ADV();
    }
    CKalimat.Length = i;
}

void SalinKalimatFile2() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != MARK))
    {
        CKalimat.TabKalimat[i] = currentChar;
        i += 1;
        ADV();
    }
    CKalimat.Length = i;
}

void STARTKALIMATFILE(char filename[]) {
    STARTFILE(filename);
    IgnoreNewline();
    if (currentChar == MARK2 || currentChar == EOF) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile();
    }
}

void ADVKALIMATFILE(){
    IgnoreNewline();
    IgnoreBlanks();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile();
    }
}

void ADVKALIMATFILE2() {
    IgnoreNewline();
    if (currentChar == BLANK || currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile2();
    }
}

void copyKalimat (Kalimat k1, Kalimat *k2){
    k2->Length=k1.Length;
    for (int i=0;i<=k1.Length;i++){
        k2->TabKalimat[i] = k1.TabKalimat[i];
    }
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(CKalimat.TabKalimat); i++) {
        CKalimat.TabKalimat[i] = '\0';
        CKalimat.Length = 0;
    }
}


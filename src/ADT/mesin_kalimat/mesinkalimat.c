#include <stdio.h>
#include "mesinkalimat.h"

boolean EndKalimat;
Kalimat CKalimat;

void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

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

void IgnoreMark()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == MARK)
    {
        ADV();
    }
}

void SalinKalimatFile() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != EOF) && !feof(config) && (currentChar != MARK2))
    {
        CKalimat.TabKalimat[i] = currentChar;
        // printf("%c", currentChar);
        i+= 1;
        ADV();
    }
    CKalimat.Length = i;
}

void SalinKalimatFile2() {
    ResetKalimat();  
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != MARK))
    {
        CKalimat.TabKalimat[i] = currentChar;
        i += 1;
        ADV();
    }
    CKalimat.Length = i;
}

void SalinKalimatFile3() {
    ResetKalimat();  // Reset array
    IgnoreMark();
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != EOF) && !feof(config))
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
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile();
    }
}

void STARTKALIMATFILE2(char filename[]) {
    STARTFILE2(filename);
    IgnoreNewline();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile();
    }
}

void ADVKALIMATFILE(){
    IgnoreNewline();
    Ignoreblanks();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile();
    }
}

void ADVKALIMATFILE2() {
    IgnoreNewline();
    if (currentChar == BLANK) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile2();
    }
}

void ADVKALIMATFILE3() {
    IgnoreNewline();
    IgnoreMark();
    if (currentChar == MARK) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimatFile3();
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


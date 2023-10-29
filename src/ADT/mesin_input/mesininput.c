#include <stdio.h>
#include <stdlib.h>
#include "mesininput.h"

char currentChar;
boolean EOP;

boolean EndWord;
Word currentWord;

// void IgnoreBlanks()
// /* Mengabaikan satu atau beberapa BLANK
//    I.S. : currentChar sembarang
//    F.S. : currentChar ≠ BLANK atau currentChar = MARK */
// {
//     while (currentChar == BLANK)
//     {
//         ADV2();
//     }
// }

// void IgnoreNewLine()
// /* Mengabaikan satu atau beberapa BLANK
//    I.S. : currentChar sembarang
//    F.S. : currentChar ≠ BLANK atau currentChar = MARK */
// {
//     while (currentChar == NEWLINE)
//     {
//         ADV2();
//     }
// }

void STARTINPUT()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks();
    IgnoreNewLine();

    if (currentChar == MARK)
    {
        EndWord = true;
    } else
    {
        EndWord = false;
        ADVINPUT();
    }
}

void ADVINPUT()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == MARK)
    {
        EndWord = true;
    } else
    {
        CopyWordInput();
        IgnoreBlanks();
        IgnoreNewLine();
    }
}

void CopyWordInput()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (i < NMax))
    {
        currentWord.TabWord[i] = currentChar;
        i += 1;
        ADV2();
    }
    currentWord.Length = i;
}


#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK)
    {
        ADV2();
    }
}

void IgnoreNewLine()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == NEWLINE)
    {
        ADV2();
    }
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks();

    if (currentChar == MARK)
    {
        EndWord = true;
    } else
    {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD()
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
        CopyWord();
        IgnoreBlanks();
        IgnoreNewLine();
    }
}

void CopyWord()
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
        ADV();
    }

    currentWord.Length = i;
}

boolean IsStringEqual(Word word1, char *word2)
{
    boolean equal = true;
    if(word1.Length == panjangString(word2)){
        for (int i = 0; i < word1.Length; i++)
        {
            if (word2[i] != word1.TabWord[i])
            {

                return false;
            }
        }
    } else {
        equal = false;
    }

    return equal;
}

int panjangString(char* string)
{
    int length = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        length += 1;
    }

    return length;
}
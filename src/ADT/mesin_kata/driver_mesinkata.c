#include <stdio.h>
#include "mesinkata.h"

int main() {
    printf("Input dengan end titik :\n");

    STARTWORD();

    while (!EndWord) {
        printf("Read word: ");
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");

        ADVWORD(); // Advance to the next word
    }

    printf("End of input.\n");
    return 0;
}

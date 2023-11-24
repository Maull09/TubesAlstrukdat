#include <stdio.h>
#include "mesinkata.h"

int main() {
    printf("Input dengan end titik :\n");

    STARTWORD();

    while (!EndWord) {
        printf("Read word: ");
        printf("%s", currentWord.TabWord);
        printf("\n");

        ADVWORD(); // Advance to the next word
    }

    printf("End of input.\n");
    return 0;
}

#include <stdio.h>
#include "function.h"

int main() {
    // Test untuk SalinString
    char source[] = "Halo Dunia!";
    char destination[50]; // mengalokasikan memori yang cukup besar untuk tujuan

    SalinString(destination, source);

    printf("Source String: %s\n", source);
    printf("Destination String setelah disalin: %s\n\n", destination);

    // Test untuk StringSama
    char string1[] = "OpenAI";
    char string2[] = "OpenAI";
    char string3[] = "Open";

    if (StringSama(string1, string2)) {
        printf("String1 (%s) dan String2 (%s) adalah sama.\n", string1, string2);
    } else {
        printf("String1 (%s) dan String2 (%s) adalah berbeda.\n", string1, string2);
    }

    if (StringSama(string1, string3)) {
        printf("String1 (%s) dan String3 (%s) adalah sama.\n", string1, string3);
    } else {
        printf("String1 (%s) dan String3 (%s) adalah berbeda.\n", string1, string3);
    }

    return 0;
}

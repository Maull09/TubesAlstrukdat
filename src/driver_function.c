#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    // Test untuk SalinString
    char source[] = "Halo Dunia!";
    char destination[50]; // mengalokasikan memori yang cukup besar untuk tujuan

    SalinString(destination, source);

    printf("Source String: %s\n", source);
    printf("Destination String setelah disalin: %s\n\n", destination);

    // Test untuk StringSama
    char string1[] = "Maul";
    char string2[] = "Maul";
    char string3[] = "Maulana";

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

    char str1[] = "12345";
    char str2[] = "12a45";

    if(isNumber(str1)) {
        printf("%s is a number.\n", str1);
    } else {
        printf("%s is not a number.\n", str1);
    }

    if(isNumber(str2)) {
        printf("%s is a number.\n", str2);
    } else {
        printf("%s is not a number.\n", str2);
    }

    char* s1 = "Hello, ";
    char* s2 = "World!";
    char* combined = concat(s1, s2);
    if (combined != NULL) {
        printf("%s\n", combined);
        free(combined); // Jangan lupa membebaskan memori setelah selesai menggunakan
    }

    return 0;
}

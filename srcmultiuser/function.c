#include "function.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi Yang Dapat Dipakai

// Untuk menyalin string dari src ke dest
void SalinString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Penanda akhir string
}

//Untuk Membandingkan String 1 dan String 2
boolean StringSama(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return false; // jika ada karakter yang berbeda, maka string tidak sama
        }
        i++;
    }
    return s1[i] == s2[i]; // memeriksa apakah keduanya berakhir pada saat yang sama (keduanya adalah '\0')
}

boolean isNumber(char *str){
    if(str[0] == '\0') {
        return false;
    }

    for(int i = 0; str[i] != '\0'; i++){
        if(!is_digit(str[i])){
            return false;
        }
    }
    return true;
}

boolean is_digit(char c) {
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8'|| c == '9';
}

boolean name_valid(char *str) {
    if (str[0] == '\0') {
        return false;
    }

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    if (length < 4) {
        return false;
    }

    if (str[length - 4] == '.' && 
        str[length - 3] == 't' &&
        str[length - 2] == 'x' &&
        str[length - 1] == 't') {
        return true;
    }

    return false;
}

int stringLength(char* string)
{
    int length = 0;
    while (*string != '\0')
    {
        length++;
        string++;
    }
    return length;
}


char* concat(char *s1, char *s2) {
    char *result;
    char *temp;

    // Alokasikan memori
    result = (char *)malloc(stringLength(s1) + stringLength(s2) + 1); // +1 untuk karakter null-terminator
    if (result == NULL) {
        return NULL; // Alokasi gagal
    }

    temp = result;

    // Salin s1 ke result
    while (*s1) {
        *temp++ = *s1++;
    }

    // Salin s2 ke result
    while ((*temp++ = *s2++));

    return result;
}






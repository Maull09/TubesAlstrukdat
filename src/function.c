#include "function.h"
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
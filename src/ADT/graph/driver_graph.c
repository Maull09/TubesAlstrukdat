#include "graph.h"
#include <stdio.h>

// gcc graph.c driver_graph.c ../../function.c -o driver_graph

int main() {
    Graph g;
    CreateGraph(&g);

    // Menambahkan beberapa user
    insertNode(&g, "Alice");
    insertNode(&g, "Bob");
    insertNode(&g, "Charlie");

    // Menambahkan beberapa hubungan (following)
    insertEdge(&g, "Alice", "Bob");      // Alice mengikuti Bob
    insertEdge(&g, "Bob", "Charlie");    // Bob mengikuti Charlie
    insertEdge(&g, "Alice", "Charlie");  // Alice mengikuti Charlie

    // Menampilkan status pengguna dan siapa yang mereka ikuti
    for (adrNode P = g.first; P != NULL; P = P->next) {
        printf("%s mengikuti: ", P->username);
        for (adrSuccNode Q = P->trail; Q != NULL; Q = Q->next) {
            printf("%s ", Q->succ->username);
        }
        printf("\n");
    }

    // Menghapus pengguna
    deleteNode(&g, "Charlie");

    // Menampilkan status pengguna setelah penghapusan
    printf("\nSetelah menghapus Charlie:\n");
    for (adrNode P = g.first; P != NULL; P = P->next) {
        printf("%s mengikuti: ", P->username);
        for (adrSuccNode Q = P->trail; Q != NULL; Q = Q->next) {
            if(Q->succ->username != NULL){
                printf("%s ", Q->succ->username);
            }
        }
        printf("\n");
    }

    return 0;
}

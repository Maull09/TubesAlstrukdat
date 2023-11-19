#include "graph.h"

// Membuat graph baru
void CreateGraph(Graph *g) {
    g->first = NULL;
}

// Mengalokasikan memori untuk node baru
adrNode newGraphNode(char username[]) {
    adrNode P = (adrNode)malloc(sizeof(Node));
    if (P != NULL) {
        SalinString(P->username, username);
        P->nPred = 0;
        P->trail = NULL;
        P->next = NULL;
    }
    return P;
}

// Mengembalikan memori node ke sistem
void deallocGraphNode(adrNode P) {
    free(P);
}

// Mengalokasikan memori untuk successor node baru
adrSuccNode newSuccNode(adrNode pn) {
    adrSuccNode P = (adrSuccNode)malloc(sizeof(SuccNode));
    if (P != NULL) {
        P->succ = pn;
        P->next = NULL;
    }
    return P;
}

// Mengembalikan memori successor node ke sistem
void deallocSuccNode(adrSuccNode P) {
    free(P);
}

// Mencari node berdasarkan username
adrNode searchNode(Graph g, char username[]) {
    adrNode P = g.first;
    while (P != NULL && !StringSama(P->username, username)) {
        P = P->next;
    }
    return P;
}

// Mencari edge antara dua username
adrSuccNode searchEdge(Graph g, char precUsername[], char succUsername[]) {
    adrNode P = searchNode(g, precUsername);
    if (P != NULL) {
        adrSuccNode Q = P->trail;
        while (Q != NULL) {
            if (StringSama(Q->succ->username, succUsername)) {
                return Q;
            }
            Q = Q->next;
        }
    }
    return NULL;
}

// Menambahkan node baru ke graph
void insertNode(Graph *g, char username[]) {
    if (searchNode(*g, username) != NULL) {
        return;
    }

    adrNode P = newGraphNode(username);
    if (P != NULL) {
        P->next = g->first;
        g->first = P;
    }
}


// Menambahkan edge baru ke graph
void insertEdge(Graph *g, char precUsername[], char succUsername[]) {
    if (searchEdge(*g, precUsername, succUsername) != NULL) {
        return;
    }
    
    adrNode P = searchNode(*g, precUsername);
    adrNode Q = searchNode(*g, succUsername);

    if (P == NULL) {
        insertNode(g, precUsername);
        P = g->first;
    }
    if (Q == NULL) {
        insertNode(g, succUsername);
        Q = g->first;
    }

    adrSuccNode newEdge = newSuccNode(Q);
    if (newEdge != NULL) {
        newEdge->next = P->trail;
        P->trail = newEdge;
    }
}

// Menghapus node dari graph
void deleteNode(Graph *g, char username[]) {
    // Pertama, hapus semua edge yang menuju ke node yang akan dihapus
    for (adrNode P = g->first; P != NULL; P = P->next) {
        adrSuccNode Q = P->trail;
        adrSuccNode prev = NULL;
        while (Q != NULL) {
            if (StringSama(Q->succ->username, username)) {
                if (prev == NULL) {
                    P->trail = Q->next;
                } else {
                    prev->next = Q->next;
                }
                adrSuccNode temp = Q;
                Q = Q->next;
                deallocSuccNode(temp);
                continue;
            }
            prev = Q;
            Q = Q->next;
        }
    }

    // Kemudian, hapus node itu sendiri
    adrNode P = g->first;
    adrNode prev = NULL;
    while (P != NULL && !StringSama(P->username, username)) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        if (prev != NULL) {
            prev->next = P->next;
        } else {
            g->first = P->next;
        }

        adrSuccNode Q = P->trail;
        while (Q != NULL) {
            adrSuccNode temp = Q;
            Q = Q->next;
            deallocSuccNode(temp);
        }

        deallocGraphNode(P);
    }
}


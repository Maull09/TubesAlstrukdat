#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>

#include "../boolean.h"
#include "../../function.h"
#include "../listadt.h"

// Prototipe fungsi dan prosedur untuk ADT Graph
void CreateGraph(Graph *g);
adrNode newGraphNode(char username[]);
void deallocGraphNode(adrNode P);
adrSuccNode newSuccNode(adrNode pn);
void deallocSuccNode(adrSuccNode P);
adrNode searchNode(Graph g, char username[]);
adrSuccNode searchEdge(Graph g, char precUsername[], char succUsername[]);
void insertNode(Graph *g, char username[]);
void insertEdge(Graph *g, char precUsername[], char succUsername[]);
void deleteNode(Graph *g, char username[]);

#endif

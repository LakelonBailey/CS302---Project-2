// qsort.cpp

#include "volsort.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

// Compare based on number
int c_numcomp(const void *a, const void *b) {

    // Cast void pointers to nodes and return result
    const Node *aNode = *(const Node**)a;
    const Node *bNode = *(const Node**)b;
    return aNode->number - bNode->number;
}

// Compare based on string
int c_strcomp(const void *a, const void *b) {

    // Cast void pointers to nodes and return result
    const Node *aNode = *(const Node**)a;
    const Node *bNode = *(const Node**)b;
    if (aNode->string < bNode->string) return -1;
    if (aNode->string == bNode->string) return 0;
    return 1;
}

void qsort_sort(List &l, bool numeric) {

    // Copy values into basic array
    Node * nodes[l.size];
    Node * current = l.head;
    for (size_t i = 0; i < l.size; i++) {
        nodes[i] = current;
        current = current->next;
    }

    // Call qsort with proper comparison function
    if (numeric) {
        qsort(nodes, l.size, sizeof(Node *), c_numcomp);
    }
    else {
        qsort(nodes, l.size, sizeof(Node *), c_strcomp);
    }

    // Reset node relationships
    for (size_t i = 0; i < l.size - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[l.size - 1]->next = nullptr;
    l.head = nodes[0];
}


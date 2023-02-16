// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

void stl_sort(List &l, bool numeric) {

    // Copy items into basic array
    Node * nodes[l.size];
    Node * current = l.head;
    for (size_t i = 0; i < l.size; i++) {
        nodes[i] = current;
        current = current->next;
    }

    // Call stl sort, passing the proper comparison function
    if (numeric) {
        std::sort(nodes, nodes + l.size, node_number_compare);
    }
    else {
        std::sort(nodes, nodes + l.size, node_string_compare);
    }

    // Reset node relationships
    for (size_t i = 0; i < l.size - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[l.size - 1]->next = nullptr;
    l.head = nodes[0];
}


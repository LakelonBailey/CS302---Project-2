// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

// Recursively sort a singly-linked list using quick sort
Node *qsort(Node *head, bool numeric) {

    // Check for base case
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Choose first element as pivot
    Node* pivot = head;
    head = head->next;
    pivot->next = nullptr;

    // Partition and sort each partition
    Node* left = nullptr;
    Node* right = nullptr;
    partition(head, pivot, left, right, numeric);
    left = qsort(left, numeric);
    right = qsort(right, numeric);

    // Add pivot to left segment and then add both segments
    return concatenate(concatenate(left, pivot), right);
}

// Cut a list in half based on pivot value
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    while (head != nullptr) {
        Node* next = head->next;

        // Find result and add to corresponding list
        // head < pivot = add to left, else add to right
        int result = (
            numeric
            ? node_number_compare(head, pivot)
            : node_string_compare(head, pivot)
        );
        if (result) {
            head->next = left;
            left = head;
        } else {
            head->next = right;
            right = head;
        }
        head = next;
    }
}

// Add two lists together
Node *concatenate(Node *left, Node *right) {

    // Handle base case
    if (left == nullptr) {
        return right;
    }

    // Find end of left and set equal to right
    Node* curr = left;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = right;
    return left;
}

// Sort list
void quick_sort(List &l, bool numeric) {

    // Start recursive sorting
    l.head = qsort(l.head, numeric);
}


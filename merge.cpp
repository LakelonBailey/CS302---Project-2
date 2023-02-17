// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
    l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric) {

    // One element in list, skip
    if (head == nullptr || head->next == nullptr) {
        return head;
    }


    // Sort left and right segments then return merge
    Node * left;
    Node * right;
    split(head, left, right);
    left = msort(left, numeric);
    right = msort(right, numeric);
    return merge(left, right, numeric);
}

void split(Node *head, Node *&left, Node *&right) {

    // Split using slow/fast pointers
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    left = head;
    right = slow->next;
    slow->next = nullptr;
}

Node *merge(Node *left, Node *right, bool numeric) {
    Node* newHead = nullptr;
    Node* current = nullptr;
    while (left != nullptr && right != nullptr) {

        // Determine result
        int result = (
            numeric
            ? node_number_compare(left, right)
            : node_string_compare(left, right)
        );

        if (result) {

            // Add to left list
            if (newHead == nullptr) {
                newHead = left;
                current = left;
            } else {
                current->next = left;
                current = left;
            }
            left = left->next;
        }
        else {

            // Add to right list
            if (newHead == nullptr) {
                newHead = right;
                current = right;
            } else {
                current->next = right;
                current = right;
            }
            right = right->next;
        }
    }
    if (left != nullptr) {
        current->next = left;
    } else if (right != nullptr) {
        current->next = right;
    }

    return newHead;
}


#include "volsort.h"


List::List() {
    this->size = 0;
    this->head = nullptr;
}

List::~List() {
    dump_node(this->head);
}

void List::push_front(const std::string &s) {
  this->size += 1;

  // Create new node;
  Node * newNode = new Node();
  newNode->string = s;
  newNode->number = std::stoi(s);

  // Convert string to number
  if (this->head == nullptr) {
    this->head = newNode;
  }
  else {
    Node * previousHead = this->head;
    this->head = newNode;
    newNode->next = previousHead;
  }
}

void dump_node(Node *n) {
    if (n == nullptr) {
        return;
    }
    std::cout<<n->string<<'\n';
    Node* next = n->next;
    delete n;
    dump_node(next);
}

bool node_number_compare(const Node *a, const Node *b) {
    return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {
    return a->string < b->string;
}
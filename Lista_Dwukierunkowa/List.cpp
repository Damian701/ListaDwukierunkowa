#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    head = nullptr;
    tail = nullptr;
}

List::~List() {
   //pozniej
}

void List::addFront(int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


void List::addBack(int val) {
    Node* newNode = new Node(val);

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void List::display() {
    if (head == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    Node* current = head;
    cout << "Zawartosc listy: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
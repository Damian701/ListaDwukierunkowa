#include <iostream>
#include "List.h"
#include "NodeFactory.h"

using namespace std;

List::List() {
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    clear();
}

void List::addFront(int val) {
    Node* newNode = NodeFactory::createNode(val);

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
    Node* newNode = NodeFactory::createNode(val);

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

ListIterator List::getIterator() {
    return ListIterator(head);
}

void List::addAtIndex(int index, int val) {
    if (index <= 0) { addFront(val); return; }
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) current = current->next;
    if (current == nullptr) { addBack(val); }
    else {
        Node* newNode = NodeFactory::createNode(val);
        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev) current->prev->next = newNode;
        else head = newNode;
        current->prev = newNode;
    }
}
void List::removeFront() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
}
void List::removeBack() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
}
void List::removeAtIndex(int index) {
    if (!head) return;
    if (index == 0) { removeFront(); return; }
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) current = current->next;
    if (current) {
        if (current == tail) removeBack();
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }
}

void List::clear() {
    while (head != nullptr) removeFront();
}

void List::displayReverse() {
    if (!tail) return;
    Node* current = tail;
    cout << "Od tylu: ";
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}
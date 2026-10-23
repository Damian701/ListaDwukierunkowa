#pragma once

#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "ListIterator.h"

class List {
private:
    Node* head;
    Node* tail;

public:
    List();
    ~List();
    ListIterator getIterator();

    void addFront(int val);
    void addBack(int val);
    void display();
};



#endif

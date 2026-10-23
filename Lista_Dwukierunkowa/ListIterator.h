#pragma once
#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include "node.h"

class ListIterator {
private:
    Node* current;
public:
    ListIterator(Node* startNode);
    void next();
    void prev();
    void displayCurrent();
};
#endif

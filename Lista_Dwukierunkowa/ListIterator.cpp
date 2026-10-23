#include "ListIterator.h"
#include <iostream>
using namespace std;

ListIterator::ListIterator(Node* startNode) { current = startNode; }
void ListIterator::next() { if (current) current = current->next; }
void ListIterator::prev() { if (current) current = current->prev; }
void ListIterator::displayCurrent() {
    if (current) cout << current->data << endl;
    else cout << "Brak elementu" << endl;
}
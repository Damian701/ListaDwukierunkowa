#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List list;
    list.addBack(10);
    list.addBack(20);
    list.addFront(5);
    list.addAtIndex(1, 15);
    list.display(); // 5 15 10 20

    list.removeAtIndex(1);
    list.display(); // 5 10 20

    ListIterator it = list.getIterator();
    cout << "Iterator start: "; it.displayCurrent();
    it.next(); cout << "Iterator next: "; it.displayCurrent();

    return 0;
}

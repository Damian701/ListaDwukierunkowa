#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List list;
    list.addBack(10);
    list.addBack(20);
    list.addBack(25);
    list.addFront(5);
    list.addFront(30);
    list.addAtIndex(1, 15);
	list.display(); // 30 5 15 10 20 25

    list.removeAtIndex(1);
	list.display(); // 30 15 10 20 25
	list.displayReverse(); // 25 20 10 15 30
   

    ListIterator it = list.getIterator();
    cout << "Iterator start: "; it.displayCurrent();
    it.next(); cout << "Iterator next: "; it.displayCurrent();


    list.clear();
    list.display(); // Lista jest pusta.

    return 0;
}

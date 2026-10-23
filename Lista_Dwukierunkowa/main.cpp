#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List list;

    list.addFront(1);
    list.addFront(1);
    list.addBack(0);
    list.addBack(10);
    list.display();

    return 0;
}

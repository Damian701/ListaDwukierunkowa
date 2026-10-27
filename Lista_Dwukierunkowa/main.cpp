
#include <iostream>
#include "List.h"

using namespace std;

/**
 * @brief Funkcja główna programu.
 *
 * Demonstruje działanie listy, w tym dodawanie i usuwanie elementów,
 * wyświetlanie listy w obu kierunkach, obsługę iteratora
 * oraz czyszczenie listy.
 *
 * @return int Zwraca 0, jeśli program zakończy się poprawnie.
 */
int main() {
    /// Utworzenie obiektu listy.
    List list;

    /// Dodanie elementów na koniec listy.
    list.addBack(10);
    list.addBack(20);
    list.addBack(25);

    /// Dodanie elementów na początek listy.
    list.addFront(5);
    list.addFront(30);

    /// Wstawienie elementu 15 pod indeksem 1.
    list.addAtIndex(1, 15);

    /// Wyświetlenie listy: 30 5 15 10 20 25.
    list.display();

    /// Usunięcie elementu znajdującego się pod indeksem 1.
    list.removeAtIndex(1);

    /// Wyświetlenie listy po usunięciu elementu: 30 15 10 20 25.
    list.display();

    /// Wyświetlenie elementów listy w odwrotnej kolejności:
    /// 25 20 10 15 30.
    list.displayReverse();

    /// Pobranie iteratora umożliwiającego przechodzenie po liście.
    ListIterator it = list.getIterator();

    /// Wyświetlenie aktualnego elementu iteratora.
    cout << "Iterator start: ";
    it.displayCurrent();

    /// Przejście iteratora do następnego elementu i jego wyświetlenie.
    it.next();
    cout << "Iterator next: ";
    it.displayCurrent();

    /// Usunięcie wszystkich elementów listy.
    list.clear();

    /// Wyświetlenie komunikatu informującego o pustej liście.
    list.display();

    return 0;
}

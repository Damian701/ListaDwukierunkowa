
/**
 * @file ListIterator.cpp
 * @brief Implementacja iteratora listy dwukierunkowej.
 *
 * Plik zawiera implementacjê metod klasy ListIterator,
 * które umo¿liwiaj¹ poruszanie siê po liœcie w obu kierunkach
 * oraz wyœwietlanie wartoœci aktualnego elementu.
 */

#include "ListIterator.h"
#include <iostream>

using namespace std;

/**
 * @brief Konstruktor iteratora.
 *
 * Ustawia iterator na wêŸle przekazanym jako argument.
 *
 * @param startNode WskaŸnik na wêze³, od którego rozpoczyna siê
 *                  iteracja. Mo¿e mieæ wartoœæ nullptr.
 */
ListIterator::ListIterator(Node* startNode) {
    current = startNode;
}

/**
 * @brief Przesuwa iterator do nastêpnego elementu listy.
 *
 * Jeœli iterator wskazuje na istniej¹cy wêze³, zostaje
 * przesuniêty do nastêpnego wêz³a za pomoc¹ wskaŸnika next.
 * Jeœli current ma wartoœæ nullptr, metoda nie wykonuje
 * ¿adnej operacji.
 */
void ListIterator::next() {
    if (current)
        current = current->next;
}

/**
 * @brief Przesuwa iterator do poprzedniego elementu listy.
 *
 * Jeœli iterator wskazuje na istniej¹cy wêze³, zostaje
 * przesuniêty do poprzedniego wêz³a za pomoc¹ wskaŸnika prev.
 * Jeœli current ma wartoœæ nullptr, metoda nie wykonuje
 * ¿adnej operacji.
 */
void ListIterator::prev() {
    if (current)
        current = current->prev;
}

/**
 * @brief Wyœwietla wartoœæ aktualnego elementu listy.
 *
 * Jeœli iterator wskazuje na istniej¹cy wêze³, wyœwietla
 * przechowywan¹ w nim wartoœæ. W przeciwnym razie wyœwietla
 * komunikat informuj¹cy o braku elementu.
 */
void ListIterator::displayCurrent() {
    if (current)
        cout << current->data << endl;
    else
        cout << "Brak elementu" << endl;
}

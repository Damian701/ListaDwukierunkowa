
/**
 * @file ListIterator.h
 * @brief Deklaracja iteratora listy dwukierunkowej.
 *
 * Plik zawiera definicjê klasy ListIterator, która umo¿liwia
 * poruszanie siê po elementach listy dwukierunkowej
 * w przód i w ty³ oraz wyœwietlanie aktualnego elementu.
 */

#pragma once
#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "node.h"

 /**
  * @class ListIterator
  * @brief Iterator umo¿liwiaj¹cy przechodzenie po liœcie dwukierunkowej.
  *
  * Iterator przechowuje wskaŸnik na aktualny wêze³ listy
  * i udostêpnia metody pozwalaj¹ce zmieniaæ jego pozycjê
  * oraz wyœwietlaæ wartoœæ bie¿¹cego elementu.
  */
class ListIterator {
private:
    /**
     * @brief WskaŸnik na aktualny wêze³ listy.
     *
     * Wskazuje element, na którym aktualnie znajduje siê iterator.
     */
    Node* current;

public:
    /**
     * @brief Konstruktor iteratora.
     *
     * Inicjalizuje iterator, ustawiaj¹c go na wskazanym wêŸle.
     *
     * @param startNode WskaŸnik na wêze³, od którego rozpoczyna siê
     *                  iteracja.
     */
    ListIterator(Node* startNode);

    /**
     * @brief Przesuwa iterator do nastêpnego elementu listy.
     *
     * Przechodzi do wêz³a znajduj¹cego siê za aktualnym elementem.
     */
    void next();

    /**
     * @brief Przesuwa iterator do poprzedniego elementu listy.
     *
     * Przechodzi do wêz³a znajduj¹cego siê przed aktualnym elementem.
     */
    void prev();

    /**
     * @brief Wyœwietla wartoœæ aktualnego elementu listy.
     *
     * Sposób zachowania dla iteratora wskazuj¹cego nullptr
     * zale¿y od implementacji metody.
     */
    void displayCurrent();
};

#endif

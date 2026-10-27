
/**
 * @file List.h
 * @brief Deklaracja klasy dwukierunkowej listy.
 *
 * Plik zawiera deklaracjê klasy List, która umo¿liwia
 * przechowywanie elementów typu int w postaci listy
 * dwukierunkowej oraz wykonywanie operacji na jej elementach.
 */

#pragma once

#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "ListIterator.h"

 /**
  * @class List
  * @brief Implementuje dwukierunkow¹ listê elementów typu int.
  *
  * Lista umo¿liwia dodawanie, usuwanie i wyœwietlanie elementów,
  * pobieranie iteratora oraz usuwanie wszystkich elementów.
  * Ka¿dy wêze³ zawiera odwo³ania do poprzedniego i nastêpnego
  * elementu listy.
  */
class List {
private:
    /**
     * @brief WskaŸnik na pierwszy element listy.
     *
     * W przypadku pustej listy przyjmuje wartoœæ nullptr.
     */
    Node* head;

    /**
     * @brief WskaŸnik na ostatni element listy.
     *
     * W przypadku pustej listy przyjmuje wartoœæ nullptr.
     */
    Node* tail;

public:
    /**
     * @brief Konstruktor klasy List.
     *
     * Tworzy pust¹ listê i inicjalizuje wskaŸniki head oraz tail.
     */
    List();

    /**
     * @brief Destruktor klasy List.
     *
     * Zwalnia pamiêæ zajmowan¹ przez wszystkie wêz³y listy.
     */
    ~List();

    /**
     * @brief Zwraca iterator rozpoczynaj¹cy przechodzenie od pocz¹tku listy.
     *
     * @return ListIterator Iterator wskazuj¹cy na pierwszy element listy.
     */
    ListIterator getIterator();

    /**
     * @brief Dodaje element na pocz¹tku listy.
     *
     * @param val Wartoœæ ca³kowita dodawanego elementu.
     */
    void addFront(int val);

    /**
     * @brief Dodaje element na koñcu listy.
     *
     * @param val Wartoœæ ca³kowita dodawanego elementu.
     */
    void addBack(int val);

    /**
     * @brief Wyœwietla wszystkie elementy listy od pocz¹tku do koñca.
     *
     * Jeœli lista jest pusta, wyœwietla odpowiedni komunikat.
     */
    void display();

    /**
     * @brief Wstawia element pod wskazanym indeksem.
     *
     * Jeœli indeks jest mniejszy lub równy zero, element
     * zostaje dodany na pocz¹tku listy. Jeœli indeks wskazuje
     * pozycjê poza istniej¹cymi elementami, element zostaje
     * dodany na koñcu listy.
     *
     * @param index Indeks pozycji, na której ma zostaæ wstawiony element.
     * @param val Wartoœæ ca³kowita dodawanego elementu.
     */
    void addAtIndex(int index, int val);

    /**
     * @brief Usuwa pierwszy element listy.
     *
     * Jeœli lista jest pusta, metoda nie wykonuje ¿adnej operacji.
     */
    void removeFront();

    /**
     * @brief Usuwa ostatni element listy.
     *
     * Jeœli lista jest pusta, metoda nie wykonuje ¿adnej operacji.
     */
    void removeBack();

    /**
     * @brief Usuwa element znajduj¹cy siê pod wskazanym indeksem.
     *
     * Jeœli indeks wynosi zero, usuwa pierwszy element.
     * Jeœli indeks wskazuje ostatni element, usuwa ostatni wêze³.
     * Nie usuwa elementu, jeœli wskazany indeks nie istnieje.
     *
     * @param index Indeks elementu przeznaczonego do usuniêcia.
     */
    void removeAtIndex(int index);

    /**
     * @brief Usuwa wszystkie elementy listy.
     *
     * Po wykonaniu operacji lista jest pusta, a pamiêæ
     * zajmowana przez jej wêz³y zostaje zwolniona.
     */
    void clear();

    /**
     * @brief Wyœwietla elementy listy w odwrotnej kolejnoœci.
     *
     * Rozpoczyna od ostatniego elementu i przechodzi
     * w kierunku pocz¹tku listy.
     */
    void displayReverse();
};

#endif

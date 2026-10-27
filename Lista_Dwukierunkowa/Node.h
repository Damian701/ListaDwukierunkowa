
/**
 * @file Node.h
 * @brief Deklaracja wêz³a listy dwukierunkowej.
 *
 * Plik zawiera definicjê klasy Node, która reprezentuje
 * pojedynczy element listy dwukierunkowej.
 */

#pragma once

#ifndef NODE_H
#define NODE_H

 /**
  * @class Node
  * @brief Reprezentuje pojedynczy wêze³ listy dwukierunkowej.
  *
  * Wêze³ przechowuje wartoœæ typu int oraz wskaŸniki
  * na nastêpny i poprzedni wêze³ listy.
  */
class Node {
public:
    /**
     * @brief Wartoœæ przechowywana w wêŸle.
     */
    int data;

    /**
     * @brief WskaŸnik na nastêpny wêze³ listy.
     *
     * Wartoœæ nullptr oznacza, ¿e wêze³ jest ostatnim
     * elementem listy.
     */
    Node* next;

    /**
     * @brief WskaŸnik na poprzedni wêze³ listy.
     *
     * Wartoœæ nullptr oznacza, ¿e wêze³ jest pierwszym
     * elementem listy.
     */
    Node* prev;

    /**
     * @brief Konstruktor wêz³a.
     *
     * Inicjalizuje wêze³ podan¹ wartoœci¹ oraz ustawia
     * wskaŸniki next i prev na nullptr.
     *
     * @param val Wartoœæ ca³kowita przechowywana w wêŸle.
     */
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

#endif

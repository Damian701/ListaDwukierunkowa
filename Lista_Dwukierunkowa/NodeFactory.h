
/**
 * @file NodeFactory.h
 * @brief Deklaracja fabryki wêz³ów listy dwukierunkowej.
 *
 * Plik zawiera deklaracjê klasy NodeFactory, która udostêpnia
 * statyczn¹ metodê tworzenia nowych wêz³ów klasy Node.
 */

#pragma once
#ifndef NODEFACTORY_H
#define NODEFACTORY_H

#include "node.h"

 /**
  * @class NodeFactory
  * @brief Fabryka s³u¿¹ca do tworzenia wêz³ów listy.
  *
  * Klasa udostêpnia statyczn¹ metodê createNode(), która
  * tworzy nowy wêze³ i zwraca wskaŸnik na niego.
  */
class NodeFactory {
public:
    /**
     * @brief Tworzy nowy wêze³ listy.
     *
     * Alokuje pamiêæ dla nowego obiektu Node i inicjalizuje
     * go przekazan¹ wartoœci¹.
     *
     * @param val Wartoœæ ca³kowita przechowywana w wêŸle.
     * @return Node* WskaŸnik na utworzony wêze³.
     */
    static Node* createNode(int val);
};

#endif

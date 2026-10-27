
/**
 * @file NodeFactory.cpp
 * @brief Implementacja fabryki wêz³ów listy dwukierunkowej.
 *
 * Plik zawiera implementacjê metody tworz¹cej nowe wêz³y
 * klasy Node.
 */

#include "NodeFactory.h"

 /**
  * @brief Tworzy nowy wêze³ listy.
  *
  * Alokuje pamiêæ dla nowego obiektu klasy Node,
  * inicjalizowanego przekazan¹ wartoœci¹.
  *
  * @param val Wartoœæ ca³kowita, która zostanie zapisana w wêŸle.
  * @return Node* WskaŸnik na nowo utworzony wêze³.
  *
  * @note Pamiêæ jest alokowana za pomoc¹ operatora new.
  *       Za zwolnienie pamiêci odpowiada kod zarz¹dzaj¹cy list¹.
  */
Node* NodeFactory::createNode(int val) {
    return new Node(val);
}

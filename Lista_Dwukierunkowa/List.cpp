
#include <iostream>
#include "List.h"
#include "NodeFactory.h"

using namespace std;

/**
 * @brief Konstruktor klasy List.
 *
 * Inicjalizuje pust¹ listê dwukierunkow¹ poprzez ustawienie
 * wskaŸników head i tail na nullptr.
 */
List::List() {
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Destruktor klasy List.
 *
 * Zwalnia pamiêæ zajmowan¹ przez wszystkie wêz³y listy
 * poprzez wywo³anie metody clear().
 */
List::~List() {
    clear();
}

/**
 * @brief Dodaje nowy element na pocz¹tek listy.
 *
 * Tworzy nowy wêze³ za pomoc¹ NodeFactory.
 * Jeœli lista jest pusta, nowy wêze³ staje siê zarówno
 * pierwszym, jak i ostatnim elementem. W przeciwnym razie
 * zostaje po³¹czony z dotychczasowym pocz¹tkiem listy.
 *
 * @param val Wartoœæ ca³kowita dodawanego elementu.
 */
void List::addFront(int val) {
    Node* newNode = NodeFactory::createNode(val);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

/**
 * @brief Dodaje nowy element na koniec listy.
 *
 * Tworzy nowy wêze³ za pomoc¹ NodeFactory.
 * Jeœli lista jest pusta, nowy wêze³ staje siê zarówno
 * pocz¹tkiem, jak i koñcem listy. W przeciwnym razie
 * zostaje do³¹czony za ostatnim wêz³em.
 *
 * @param val Wartoœæ ca³kowita dodawanego elementu.
 */
void List::addBack(int val) {
    Node* newNode = NodeFactory::createNode(val);

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

/**
 * @brief Wyœwietla wszystkie elementy listy od pocz¹tku do koñca.
 *
 * Jeœli lista jest pusta, wyœwietla odpowiedni komunikat.
 * W przeciwnym razie przechodzi kolejno przez wêz³y,
 * rozpoczynaj¹c od wskaŸnika head, i wypisuje ich wartoœci.
 */
void List::display() {
    if (head == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    Node* current = head;
    cout << "Zawartosc listy: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

/**
 * @brief Tworzy iterator rozpoczynaj¹cy przechodzenie od pocz¹tku listy.
 *
 * Zwraca nowy obiekt iteratora zainicjalizowany wskaŸnikiem
 * na pierwszy wêze³ listy.
 *
 * @return ListIterator Iterator wskazuj¹cy na pocz¹tek listy.
 */
ListIterator List::getIterator() {
    return ListIterator(head);
}

/**
 * @brief Wstawia nowy element pod wskazanym indeksem.
 *
 * Jeœli indeks jest mniejszy lub równy zero, element zostaje
 * dodany na pocz¹tku listy. Jeœli wskazana pozycja wykracza
 * poza istniej¹ce elementy, element zostaje dodany na koñcu.
 * W przeciwnym razie nowy wêze³ zostaje wstawiony przed
 * elementem znajduj¹cym siê pod wskazanym indeksem.
 *
 * @param index Indeks pozycji, na której ma zostaæ wstawiony element.
 * @param val Wartoœæ ca³kowita nowego elementu.
 */
void List::addAtIndex(int index, int val) {
    if (index <= 0) {
        addFront(val);
        return;
    }

    Node* current = head;

    for (int i = 0; i < index && current != nullptr; ++i)
        current = current->next;

    if (current == nullptr) {
        addBack(val);
    }
    else {
        Node* newNode = NodeFactory::createNode(val);
        newNode->prev = current->prev;
        newNode->next = current;

        if (current->prev)
            current->prev->next = newNode;
        else
            head = newNode;

        current->prev = newNode;
    }
}

/**
 * @brief Usuwa pierwszy element listy.
 *
 * Jeœli lista nie jest pusta, usuwa pierwszy wêze³
 * i aktualizuje wskaŸnik head. W przypadku usuniêcia
 * ostatniego elementu ustawia równie¿ tail na nullptr.
 * Pamiêæ zajmowana przez usuniêty wêze³ zostaje zwolniona.
 */
void List::removeFront() {
    if (!head) return;

    Node* temp = head;
    head = head->next;

    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;

    delete temp;
}

/**
 * @brief Usuwa ostatni element listy.
 *
 * Jeœli lista nie jest pusta, usuwa ostatni wêze³
 * i aktualizuje wskaŸnik tail. Jeœli lista zawiera³a
 * tylko jeden element, wskaŸnik head równie¿ zostaje
 * ustawiony na nullptr. Pamiêæ wêz³a zostaje zwolniona.
 */
void List::removeBack() {
    if (!tail) return;

    Node* temp = tail;
    tail = tail->prev;

    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    delete temp;
}

/**
 * @brief Usuwa element listy znajduj¹cy siê pod wskazanym indeksem.
 *
 * Jeœli lista jest pusta lub indeks nie wskazuje istniej¹cego
 * elementu, metoda nie usuwa ¿adnego wêz³a. Element o indeksie
 * zero jest usuwany za pomoc¹ removeFront(), a ostatni element
 * za pomoc¹ removeBack(). W pozosta³ych przypadkach s¹siaduj¹ce
 * wêz³y zostaj¹ po³¹czone ze sob¹, a usuwany wêze³ zwolniony.
 *
 * @param index Indeks elementu przeznaczonego do usuniêcia.
 */
void List::removeAtIndex(int index) {
    if (!head) return;

    if (index == 0) {
        removeFront();
        return;
    }

    Node* current = head;

    for (int i = 0; i < index && current != nullptr; ++i)
        current = current->next;

    if (current) {
        if (current == tail)
            removeBack();
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }
}

/**
 * @brief Usuwa wszystkie elementy listy.
 *
 * Kolejno usuwa pierwszy wêze³ za pomoc¹ metody removeFront(),
 * a¿ lista stanie siê pusta. Po zakoñczeniu wskaŸniki head
 * i tail maj¹ wartoœæ nullptr.
 */
void List::clear() {
    while (head != nullptr)
        removeFront();
}

/**
 * @brief Wyœwietla elementy listy w odwrotnej kolejnoœci.
 *
 * Rozpoczyna od ostatniego wêz³a wskazywanego przez tail
 * i przechodzi w kierunku pocz¹tku listy, korzystaj¹c
 * ze wskaŸników prev. Jeœli lista jest pusta, metoda
 * koñczy dzia³anie bez wyœwietlania elementów.
 */
void List::displayReverse() {
    if (!tail) return;

    Node* current = tail;
    cout << "Od tylu: ";

    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }

    cout << endl;
}








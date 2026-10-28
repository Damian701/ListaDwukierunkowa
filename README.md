Lista Dwukierunkowa w C++ (Doubly Linked List)

Projekt realizowany w ramach zajęć z Zaawansowanego Programowania. Głównym celem projektu była implementacja w pełni funkcjonalnej, dynamicznej listy dwukierunkowej w języku C++ z wykorzystaniem dobrych praktyk programowania obiektowego, wzorców projektowych oraz narzędzi wersjonujących i dokumentujących.

🚀 Główne założenia projektu

Dynamiczna alokacja pamięci: Operacje na wskaźnikach i zarządzanie elementami listy (węzłami) na stercie.

Wzorce Projektowe:

Factory (Fabryka): Proces alokacji pamięci i tworzenia nowych węzłów (Node) został wyodrębniony do dedykowanej klasy NodeFactory.

Iterator: Zaimplementowano klasę ListIterator, która pozwala na bezpieczne i ustandaryzowane przechodzenie po liście (w przód i w tył) bez ingerencji w wewnętrzne wskaźniki struktury.

Modułowość: Każda klasa znajduje się w osobnym pliku nagłówkowym (.h) oraz pliku źródłowym (.cpp).

🛠️ Zaimplementowane funkcjonalności

Klasa List obsługuje następujące operacje:

Dodawanie elementów na początek, na koniec oraz pod wskazany indeks.

Usuwanie elementów z początku, z końca oraz spod wskazanego indeksu.

Wyświetlanie zawartości listy w przód oraz w odwrotnej kolejności (od tyłu).

Bezpieczne czyszczenie całej listy (dealokacja pamięci).

Pobieranie obiektu Iteratora do ręcznej nawigacji krok po kroku.

📁 Struktura plików

Node.h - Definicja pojedynczego węzła listy.

NodeFactory.h / NodeFactory.cpp - Klasa fabryki produkująca węzły.

ListIterator.h / ListIterator.cpp - Klasa iteratora do nawigacji po liście.

List.h / List.cpp - Główna klasa zarządzająca logiką listy dwukierunkowej.

main.cpp - Plik testowy sprawdzający wszystkie metody i scenariusze.

💻 Kompilacja i uruchomienie

Aby skompilować projekt przy użyciu kompilatora g++, otwórz terminal w folderze z projektem i wpisz:

g++ main.cpp List.cpp ListIterator.cpp NodeFactory.cpp -o program_listy


Następnie uruchom skompilowany plik:

Na systemach Linux/macOS:

./program_listy


Na systemie Windows:

program_listy.exe


📚 Narzędzia i Dokumentacja

Podczas tworzenia projektu aktywnie wykorzystywano system Git do kontroli wersji. Przetestowano zaawansowane scenariusze, takie jak:

Twarde resetowanie historii (cofanie i usuwanie commitów).

Praca w rozproszonych środowiskach (klonowanie, pobieranie i wysyłanie zmian z różnych lokalizacji roboczych).

Przywracanie usuniętych plików w celu naprawy błędów kompilacji.

Dokumentacja kodu została przygotowana przy użyciu narzędzia Doxygen z eksportem do formatu LaTeX (PDF), bazując na uczelnianym szablonie dokumentacji projektowej.

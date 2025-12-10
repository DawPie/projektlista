#include "Factory.h"
#include <iostream>
using namespace std;

int main() {
    // Tworzymy listę przez fabrykę
    DoublyLinkedList* list = ListFactory::createList();

    // Dodawanie elementów na początek
    list->push_front(3);
    list->push_front(2);
    list->push_front(1);
    cout << "Lista po push_front: ";
    list->print_forward();

    // Dodawanie na koniec
    list->push_back(4);
    list->push_back(5);
    cout << "Lista po push_back: ";
    list->print_forward();

    // Wstawienie pod indeks
    list->insert_at(2, 99);
    cout << "Lista po insert_at(2, 99): ";
    list->print_forward();

    // Usunięcie elementu pod indeks
    list->remove_at(3);
    cout << "Lista po remove_at(3): ";
    list->print_forward();

    // Iterator
    cout << "Iterator: [ ";
    ListIterator it = list->iterator();
    while (it.hasNext()) cout << it.next() << " ";
    cout << "]" << endl;

    // Sprzątanie
    delete list;
    return 0;
}


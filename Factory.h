#ifndef FACTORY_H
#define FACTORY_H
#include "DoublyLinkedList.h"

// Fabryka tworzenia listy dwukierunkowej
class ListFactory {
public:
    static DoublyLinkedList* createList() { return new DoublyLinkedList(); }
};

#endif

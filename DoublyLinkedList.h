#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>

// Iterator listy dwukierunkowej
class ListIterator {
private:
    Node* current; // aktualny wêze³ iteratora
public:
    ListIterator(Node* start); // konstruktor, start od wêz³a start
    bool hasNext();             // sprawdza, czy jest nastêpny element
    int next();                 // zwraca wartoœæ aktualnego i przesuwa siê do nastêpnego
};

// Klasa listy dwukierunkowej
class DoublyLinkedList {
private:
    Node* head; // pocz¹tek listy
    Node* tail; // koniec listy
public:
    DoublyLinkedList();  // konstruktor
    ~DoublyLinkedList(); // destruktor

    // Dodawanie elementów
    void push_front(int value);       // na pocz¹tek
    void push_back(int value);        // na koniec
    bool insert_at(int index, int value); // wstaw pod indeks

    // Usuwanie elementów
    bool pop_front();                 // usuñ z pocz¹tku
    bool pop_back();                  // usuñ z koñca
    bool remove_at(int index);        // usuñ pod indeks

    // Wyœwietlanie listy
    void print_forward();             // od pocz¹tku
    void print_backward();            // od koñca

    void clear();                     // czyœæ ca³¹ listê

    ListIterator iterator();          // zwraca iterator od pocz¹tku
};

#endif


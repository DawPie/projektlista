#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

// ---------------- Iterator ----------------
ListIterator::ListIterator(Node* start) : current(start) {}  // start iteratora
bool ListIterator::hasNext() { return current != nullptr; }   // sprawdza, czy jest następny
int ListIterator::next() {                                     // zwraca wartość i idzie dalej
    int v = current->value;
    current = current->next;
    return v;
}

// ---------------- DoublyLinkedList ----------------
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}  // konstruktor pustej listy
DoublyLinkedList::~DoublyLinkedList() { clear(); }                     // destruktor czyści listę

// Dodawanie elementów
void DoublyLinkedList::push_front(int value) {
    Node* n = new Node(value);            // utwórz nowy węzeł
    if (!head) head = tail = n;            // jeśli lista pusta, head i tail to nowy węzeł
    else { n->next = head; head->prev = n; head = n; } // inaczej dodaj przed head
}

void DoublyLinkedList::push_back(int value) {
    Node* n = new Node(value);
    if (!tail) head = tail = n;            // jeśli lista pusta
    else { tail->next = n; n->prev = tail; tail = n; } // dodaj po tail
}

bool DoublyLinkedList::insert_at(int index, int value) {
    if (index < 0) return false;
    if (index == 0) { push_front(value); return true; }  // jeśli index 0 → push_front
    Node* t = head; int i = 0;
    while (t && i < index - 1) { t = t->next; i++; }         // znajdź węzeł przed index
    if (!t) return false;                             // index poza zakresem
    if (t == tail) { push_back(value); return true; }    // jeśli na końcu → push_back
    Node* n = new Node(value);                       // nowy węzeł w środku
    n->next = t->next; n->prev = t;
    t->next->prev = n; t->next = n;
    return true;
}

// Usuwanie elementów
bool DoublyLinkedList::pop_front() {
    if (!head) return false;       // lista pusta
    Node* old = head;
    head = head->next;
    if (!head) tail = nullptr;       // jeśli lista była jednoelementowa
    else head->prev = nullptr;
    delete old;
    return true;
}

bool DoublyLinkedList::pop_back() {
    if (!tail) return false;
    Node* old = tail;
    tail = tail->prev;
    if (!tail) head = nullptr;       // lista pusta
    else tail->next = nullptr;
    delete old;
    return true;
}

bool DoublyLinkedList::remove_at(int index) {
    if (index < 0) return false;
    if (index == 0) return pop_front();   // usuń pierwszy
    Node* t = head; int i = 0;
    while (t && i < index) { t = t->next; i++; }
    if (!t) return false;
    if (t == tail) return pop_back();    // usuń ostatni
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
    return true;
}

// Wyświetlanie
void DoublyLinkedList::print_forward() {
    Node* t = head;
    cout << "[ ";
    while (t) { cout << t->value << " "; t = t->next; }
    cout << "]" << endl;
}

void DoublyLinkedList::print_backward() {
    Node* t = tail;
    cout << "[ ";
    while (t) { cout << t->value << " "; t = t->prev; }
    cout << "]" << endl;
}

// Czyści listę
void DoublyLinkedList::clear() { while (head) pop_front(); }

// Zwraca iterator od początku
ListIterator DoublyLinkedList::iterator() { return ListIterator(head); }

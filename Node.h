#ifndef NODE_H
#define NODE_H

// Struktura pojedynczego wêz³a listy dwukierunkowej
struct Node {
    int value;      // wartoœæ przechowywana w wêŸle
    Node* next;     // wskaŸnik na nastêpny element
    Node* prev;     // wskaŸnik na poprzedni element

    // Konstruktor wêz³a
    Node(int v) : value(v), next(nullptr), prev(nullptr) {}
};

#endif


#ifndef HEAP_H
#define HEAP_H

#include <iostream>
 
template <typename T>
class Heap
{ 
private:
    T* values;
    int numberOfElemets;
    int capacity;
public:
    Heap(int capacity) {
        // TODO BONUS
    }
    ~Heap() {
        // TODO BONUS
    }

    int parent(int poz) {
        // TODO BONUS
        return -1;
    }
 
    int leftSubtree(int poz) {
        // TODO BONUS
        return -1;
    }
 
    int rightSubtree(int poz) {
        // TODO BONUS
        return -1;
    }
 
    void pushUp(int poz) {
        // TODO BONUS
    }
 
    void pushDown(int poz) {
        // TODO BONUS
    }
 
    void insert(T x) {
        // TODO BONUS
    }
 
    T peek() {
        // TODO BONUS
        return T();
    }
 
    T extractMin() {
        // TODO BONUS
        return T();
    }
};

#endif // HEAP_H

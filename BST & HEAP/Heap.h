#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <utility>

template <typename T>
class Heap { // MAX-HEAP
private:
    T* values;
    int numberOfElements;
    int capacity;

public:
    // Constructor
    Heap()
    {
        this->values = new T[1];
        this->numberOfElements = 0;
        this->capacity = 1;
    }

    // Destructor
    ~Heap()
    {
        delete[] this->values;
    }

    // Return the position of the parent
    int parent(int poz)
    {
        return (poz - 1) / 2;
    }

    // Return the position of the left child
    int leftSubtree(int poz)
    {
        return 2 * poz + 1;
    }

    // Return the position of the right child
    int rightSubtree(int poz)
    {
        return 2 * poz + 2;
    }

    // Double the size of the heap
    void doubleSizeHeap()
    {
        this->capacity <<= 2;
        T* new_memory = new T[this->capacity];
        for(int i = 0; i < this->numberOfElements; ++i) 
            new_memory[i] = values[i];
        
        delete[] this->values;
        this->values = new_memory;
    }

    void insert(T x)
    {
        // Insert in the heap on the last position
        this->values[this->numberOfElements++] = x;

        // Move up to keep the maxheap priority
        int my_position = this->numberOfElements - 1;
        while (parent(my_position) >= 0 && this->values[parent(my_position)] < this->values[my_position]) {
            int my_new_position = parent(my_position);
            std::swap(this->values[parent(my_position)], this->values[my_position]);
            my_position = my_new_position;
        }

        // Resize if capacity is reached
        if (this->numberOfElements == this->capacity) {
            doubleSizeHeap();
        }
    }

    // Get the maximum element in the heap ( the root )
    T peek()
    {
        return this->values[0];
    }

    // Simple compare function
    bool compare_fct(T a, T b)
    {
        if (a > b)
            return false;
        return true;
    }
    // Get the minimum element in the heap
    T extractMin()
    {
        T min = this->values[0];
        for (int i = 0; i < this->numberOfElements; ++i) {
            if (min > this->values[i])
                min = this->values[i];
        }

        return min;
    }

    // Halve the size of the heap
    void halveSizeHeap()
    {
        this->capacity >>= 2;
        this->values = (T*)realloc(this->values, this->capacity * sizeof(T));
    }

    // Remove element from heap
    void pop()
    {
        // Swap the root with the last element
        std::swap(this->values[0], this->values[this->numberOfElements - 1]);
        this->numberOfElements--;

        // Pushdown
        int my_position = 0;

        // Push down until we can no longer push down
        while (true) {
            int left_child = leftSubtree(my_position);
            int right_child = rightSubtree(my_position);

            // If we have both childs
            if (left_child < this->numberOfElements && right_child < this->numberOfElements) {
                if (values[left_child] >= values[right_child]) {
                    std::swap(values[left_child], values[my_position]);
                    my_position = left_child;
                    continue;
                }
                else {
                    std::swap(values[right_child], values[my_position]);
                    my_position = right_child;
                    continue;
                }
            }

            // If we have only one child
            // Left
            else if (left_child < this->numberOfElements && right_child >= this->numberOfElements) {
                std::swap(values[left_child], values[my_position]);
                my_position = left_child;
                continue;
                // Right
            }
            else if (left_child >= this->numberOfElements && right_child < this->numberOfElements) {
                std::swap(values[right_child], values[my_position]);
                my_position = right_child;
                continue;
            }

            else
                break;
        }
    }

    // Display the heap vector
    void print_heap()
    {
        std::cout << "Heap elements: ";
        for (int i = 0; i < this->numberOfElements; ++i)
            std::cout << this->values[i] << " ";
        std::cout << "\n";
    }
};

#endif // HEAP_H

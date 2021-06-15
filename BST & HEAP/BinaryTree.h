#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <typename T>
class BinaryTree
{
private:
    T *pData;

    BinaryTree<T> *leftNode;
    BinaryTree<T> *rightNode;

public:
    BinaryTree() {
        pData = nullptr;
        leftNode = nullptr;
        rightNode = nullptr;
    }

    ~BinaryTree() {
        if (pData) {
            delete pData;
        }

        if (leftNode) {
            delete leftNode;
        }

        if (rightNode) {
            delete rightNode;
        }
    }

    bool hasData() {
        return pData != nullptr;
    }

    void setData(T data) {
        if (!pData) {
            pData = new T;
        }

        *pData = data;
    }

    T getData() {
        return *pData;
    }

    void setLeftSubtree(BinaryTree<T> *node) {
        if (leftNode) {
            delete leftNode;
        }

        leftNode = node;
    }

    BinaryTree<T> *getLeftSubtree() {
        return leftNode;
    }

    void setRightSubtree(BinaryTree<T> *node) {
        if (rightNode) {
            delete rightNode;
        }

        rightNode = node;
    }

    BinaryTree<T> *getRightSubtree() {
            return rightNode;
    }

    void insertLeft(T data) {
        if (!leftNode) {
            leftNode = new BinaryTree<T>();
        }

        leftNode->setData(data);
    }

    void insertRight(T data) {
        if (!rightNode) {
            rightNode = new BinaryTree<T>();
        }

        rightNode->setData(data);
    }

    /* TODO 5
     *
     * First test on:
                  1
                /   \
               2     3
              / \     \
             4   5     7
            / \
           10  8
        Should return false
     * Second test on:
                  7
               /     \
             3         15
            /  \      /    \
          1     4    9      18
        Should return true
     */
    static bool isBST(BinaryTree* root) {
        // TODO 5
        return false;
    }
};


#endif // __BINARY_TREE_H

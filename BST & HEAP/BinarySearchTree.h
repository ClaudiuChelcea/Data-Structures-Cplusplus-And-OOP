#ifndef __BINARY_SEARCH_TREE__H
#define __BINARY_SEARCH_TREE__H

#include <iostream> 
#include <vector>

template <typename T>
class BinarySearchTree
{
private:
    BinarySearchTree<T> *leftNode;
    BinarySearchTree<T> *rightNode;
    BinarySearchTree<T> *root;
    T *pData;

public:
    // Node constructor
    BinarySearchTree()
    {
        this->leftNode = nullptr;
        this->rightNode = nullptr;
        this->root = nullptr;
        this->pData = nullptr;

    }

    // Node destructor
    ~BinarySearchTree() {}
    
    // Check if the data of the node is allocated
    bool isEmpty() {
        return (pData == nullptr);
    }
    
    // Return a node with the wanted value
    BinarySearchTree<T>* create_node(int x)
    {
        BinarySearchTree<T>* my_node = new BinarySearchTree<T>();
        my_node->pData = new T();
        *(my_node->pData) = x;
        return my_node;
    }
 
    // Insert a key iteratively in BST tree
    void insertKey(T x)
    {
        if(!root) {
            root = create_node(x);
        }
        else { // Search the needed position
            BinarySearchTree<T>* start = root;
            bool created_node = false;

            // Exit loop when adding a node
            while(created_node == false) {

                // Pick left or right
                // If we have a neighbour on the left, go there
                // Otherwise create it and leave the loop
                if(x <= *(start->pData)) {
                    if(start->leftNode) {
                        start = start->leftNode;
                    } else {
                        start->leftNode = create_node(x);
                        created_node = true;
                    }
                } else if(x > *(start->pData)) {
                    if(start->rightNode) {
                        start = start->rightNode;
                    } else {
                        start->rightNode = create_node(x);
                        created_node = true;
                    }
                }
            }
        }
    }
    
    BinarySearchTree<T>* searchKey(T x) {
        // TODO 1.4
        return nullptr;
    }
    
    // Inorder traversal of the BST
    static void __inorderPrint(BinarySearchTree<T>* root)
    {
        if(!root)
            return;
        
        __inorderPrint(root->leftNode);
        std::cout << *((int*)root->pData) << " ";
        __inorderPrint(root->rightNode);
    }

    // Display the nodes in ascending order by value
    void inOrderDisplay() {
        __inorderPrint(this->root);
    }

    // Find the minimum element in the BST
    T findMin() {
        // TODO 2
        return T();
    }
    
    // Find the maximum element in the BST
    T findMax() {
        // TODO 2
        return T();
    }

    int findLevels() {
        // TODO 3
        return 0;
    }
    
    std::vector<T> displayLevel(int level) {
        // TODO 3
        std::vector<T> res;
        return res;
    }
    
    BinarySearchTree<T>* removeKey(T x) {
        // TODO 4
        return nullptr;
    }

    // Inorder traversal of the BST
    static void __postorderCleanUp(BinarySearchTree<T>* root)
    {
        if(!root)
            return;
        
        __postorderCleanUp(root->leftNode);
        __postorderCleanUp(root->rightNode);
        delete root->pData;
        delete root;
    }

    // Display the nodes in ascending order by value
    void inOrderCleanUp() {
       __postorderCleanUp(this->root);
    }
};
 
#endif // __BINARY_SEARCH_TREE_H


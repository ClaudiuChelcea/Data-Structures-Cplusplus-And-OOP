#ifndef __BINARY_SEARCH_TREE__H
#define __BINARY_SEARCH_TREE__H

#include <iostream>
#include <vector>
#include <string.h>

template <typename T>
class BinarySearchTree {
private:
    BinarySearchTree<T>* leftNode;
    BinarySearchTree<T>* rightNode;
    BinarySearchTree<T>* root;
    T* pData;

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
    bool isEmpty()
    {
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
        if (!root) {
            root = create_node(x);
        }
        else { // Search the needed position
            BinarySearchTree<T>* start = root;
            bool created_node = false;

            // Exit loop when adding a node
            while (created_node == false) {

                // Pick left or right
                // If we have a neighbour on the left, go there
                // Otherwise create it and leave the loop
                if (x <= *(start->pData)) {
                    if (start->leftNode) {
                        start = start->leftNode;
                    }
                    else {
                        start->leftNode = create_node(x);
                        created_node = true;
                    }
                }
                else if (x > *(start->pData)) {
                    if (start->rightNode) {
                        start = start->rightNode;
                    }
                    else {
                        start->rightNode = create_node(x);
                        created_node = true;
                    }
                }
            }
        }
    }

    // Return the parent of a node
    BinarySearchTree<T>* get_parent_of_node(BinarySearchTree<T>* my_root, int x)
    {
        // Stop condition
        if (!my_root || *(my_root->pData) == x)
            return nullptr; // no parent

        // Parent
        else if (my_root->leftNode && *(my_root->leftNode->pData) == x) {
            return my_root;
        }

        // Parent
        else if (my_root->rightNode && *(my_root->rightNode->pData) == x) {
            return my_root;
        }

        else { // Recursively go down the tree in order to find the value x
            if (x <= *(my_root->pData)) {
                return get_parent_of_node(my_root->leftNode, x);
            }
            else {
                return get_parent_of_node(my_root->rightNode, x);
            }
        }
    }

    // Return wanted key
    BinarySearchTree<T>* found_key(BinarySearchTree<T>* start, T x)
    {
        // Stop condition
        if (!start)
            return nullptr;

        // Check the current node
        if (*(start->pData) == x)
            return start;
        else { // Recursively go down the tree in order to find the value x
            if (x <= *(start->pData)) {
                return found_key(start->leftNode, x);
            }
            else {
                return found_key(start->rightNode, x);
            }
        }
    }

    // Return a pointer to the searched key or nullptr
    BinarySearchTree<T>* searchKey(T x)
    {
        // Create a duplicate
        BinarySearchTree<T>* start = root;
        return found_key(start, x);
    }

    // Return if the wanted node was found
    bool searchAndFoundKey(T x)
    {
        if (searchKey(x) == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }

    // Inorder traversal of the BST
    static void __inorderPrint(BinarySearchTree<T>* root)
    {
        if (!root)
            return;

        __inorderPrint(root->leftNode);
        std::cout << *((T*)root->pData) << " ";
        __inorderPrint(root->rightNode);
    }

    // Display the nodes in ascending order by value
    void inOrderDisplay()
    {
        __inorderPrint(this->root);
    }

    // Return the element on the max left
    BinarySearchTree<T>* get_max_left_element(BinarySearchTree<T>* my_root)
    {
        if (!my_root)
            return nullptr;

        while (my_root->leftNode)
            my_root = my_root->leftNode;

        return my_root;
    }

    // Find the minimum element in the BST
    T findMin()
    {
        BinarySearchTree<T>* my_root = get_max_left_element(root);
        return *(my_root->pData);
    }

    // Return the element on the max right
    BinarySearchTree<T>* get_max_right_element(BinarySearchTree<T>* my_root)
    {
        if (!my_root)
            return nullptr;

        while (my_root->rightNode)
            my_root = my_root->rightNode;

        return my_root;
    }

    // Find the maximum element in the BST
    T findMax()
    {
        BinarySearchTree<T>* my_root = get_max_right_element(root);
        return *(my_root->pData);
    }

    // Remove node with key 'x' from the tree
    void removeKey(T x)
    {
        BinarySearchTree<T>* start = searchKey(x);
        if(!start)
            return;

        // Leaf
        else if(!start->leftNode && !start->rightNode)
        {
            BinarySearchTree<T>* parent = get_parent_of_node(root, x);
            if(parent->leftNode == start)
                parent->leftNode = NULL;
            else if(parent->rightNode = start)
                parent->rightNode = NULL;
        }

        // Only left child
        else if(!start->rightNode && start->leftNode)
        {
            BinarySearchTree<T>* parent = get_parent_of_node(root, x);
            parent->leftNode = parent->leftNode->leftNode;
        } else if(start->rightNode && !start->leftNode) {
            // Only right child
            BinarySearchTree<T>* parent = get_parent_of_node(root, x);
            parent->rightNode = parent->rightNode->rightNode;
        }

        // Both childs
        else if(start->leftNode && start->rightNode) {
            BinarySearchTree<T>* swap = get_max_right_element(start->leftNode);
            BinarySearchTree<T>* parent = get_parent_of_node(root, *(swap->pData));

            *(start->pData) = *(swap->pData);

            if(parent->leftNode == swap)
                parent->leftNode = parent->leftNode->leftNode;
            else if(parent->rightNode == swap)
                parent->rightNode = parent->rightNode->rightNode;
        }

    }

    // Inorder traversal of the BST
    static void __postorderCleanUp(BinarySearchTree<T>* root)
    {
        if (!root)
            return;

        __postorderCleanUp(root->leftNode);
        __postorderCleanUp(root->rightNode);
        delete root->pData;
        delete root;
    }

    // Display the nodes in ascending order by value
    void inOrderCleanUp()
    {
        __postorderCleanUp(this->root);
    }

    // CHeck if BST tree is correct
    static bool check_is_BST(BinarySearchTree<T>* copy)
    {
        if (!copy)
            return true;

        check_is_BST(copy->leftNode);
        if (copy->leftNode && *(copy->leftNode->pData) > *(copy->pData))
            return false;
        if (copy->rightNode && *(copy->rightNode->pData) < *(copy->pData))
            return false;
        check_is_BST(copy->rightNode);

        return true;
    }

    // Check if a tree is BST
    bool isBST()
    {
        return check_is_BST(root);
    }
};

#endif // __BINARY_SEARCH_TREE_H

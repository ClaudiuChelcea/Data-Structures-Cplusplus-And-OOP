#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <vector>
#include <array>
#include <queue>

// Arguments for printing order
enum class print_order {
    preorder,
    inorder,
    postorder,
    BFS
};

template <typename T>
class BinaryTreeNode {

public:
    T data;
    BinaryTreeNode<T>* leftChild;
    BinaryTreeNode<T>* rightChild;

    // Constructor
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }

    // Destructor
    ~BinaryTreeNode() {}

    void setData(T data)
    {
        this->data = data;
    }

    T getData()
    {
        return this->data;
    }

    void setLeftChild(BinaryTreeNode node)
    {
        this->leftChild = new BinaryTreeNode<T>(node);
    }

    BinaryTreeNode* getLeftChild(BinaryTreeNode node)
    {
        return node->leftChild;
    }

    void setRightChild(BinaryTreeNode node)
    {
        this->rightChild = new BinaryTreeNode<T>(node);
    }

    BinaryTreeNode* getRightChild(BinaryTreeNode node)
    {
        return node->rightChild;
    }
};

template <typename T>
class BinaryTree {
private:
    int size;
    BinaryTreeNode<T>* root;

public:
    BinaryTree()
    {
        this->root = nullptr;
        this->size = 0;
    }

    void __postorder_free_nodes(BinaryTreeNode<T>* root)
    {
        if (!root)
            return;

        __postorder_free_nodes(root->leftChild);
        __postorder_free_nodes(root->rightChild);
        delete root;
    }

    ~BinaryTree() {}

    BinaryTreeNode<T>* getRootPointer()
    {
        return this->root;
    }

    // Preorder traversal
    static void __preorder(BinaryTreeNode<T>* root)
    {
        if (!root)
            return;

        std::cout << root->data << " ";
        __preorder(root->leftChild);
        __preorder(root->rightChild);
    }

    // Inorder traversal
    static void __inorder(BinaryTreeNode<T>* root)
    {
        if (!root)
            return;

        __inorder(root->leftChild);
        std::cout << root->data << " ";
        __inorder(root->rightChild);
    }

    // Postorder traversal
    static void __postorder(BinaryTreeNode<T>* root)
    {
        if (!root)
            return;

        __postorder(root->leftChild);
        __postorder(root->rightChild);
        std::cout << root->data << " ";
    }

    // BFS traversal
    static void __BFS(BinaryTreeNode<T>* root)
    {
        // Create visited nodes array
        std::array<int, 100> visited;
        visited.fill(0);

        // Create queue
        std::queue<BinaryTreeNode<T>*> my_queue;
        my_queue.push(root);
        visited[root->data] = 1;

        // Traverse queue
        while (!my_queue.empty()) {
            // Get parent
            BinaryTreeNode<T>* parent = my_queue.front();

            // Pop already visited node
            my_queue.pop();

            // If the neighbors are not visited, visit them
            if (parent->leftChild && visited[parent->leftChild->data] == 0) {
                visited[parent->leftChild->data] = 1;
                my_queue.push(parent->leftChild);
            }

            if (parent->rightChild && visited[parent->rightChild->data] == 0) {
                visited[parent->rightChild->data] = 1;
                my_queue.push(parent->rightChild);
            }

            // Display output
            std::cout << parent->data << " ";
        }
    }

    // BFS add element
    void BFS_add(BinaryTreeNode<T>* root, int data)
    {
        // Create visited nodes array
        std::array<int, 100> visited;
        visited.fill(0);

        // Create queue
        std::queue<BinaryTreeNode<T>*> my_queue;
        my_queue.push(root);
        visited[root->data] = 1;

        // Traverse queue
        while (!my_queue.empty()) {
            // Get parent
            BinaryTreeNode<T>* parent = my_queue.front();

            // Pop already visited node
            my_queue.pop();

            // If the neighbors are not visited, visit them
            if (parent->leftChild && visited[parent->leftChild->data] == 0) {
                visited[parent->leftChild->data] = 1;
                my_queue.push(parent->leftChild);
            }
            else if (!parent->leftChild) {
                // If we dont have node, create it
                parent->leftChild = new BinaryTreeNode<T>(data);
                return;
            }

            if (parent->rightChild && visited[parent->rightChild->data] == 0) {
                visited[parent->rightChild->data] = 1;
                my_queue.push(parent->rightChild);
            }
            else if (!parent->rightChild) {
                // If we dont have node, create it
                parent->rightChild = new BinaryTreeNode<T>(data);
                return;
            }
        }
    }

    void insert(T data)
    {
        // Insert as root
        if (!this->root) {
            this->root = new BinaryTreeNode<T>(data);
        }
        else {
            BFS_add(root, data);
        }
    }

    // Display tree nodes
    void displayTree(enum print_order wanted_order)
    {
        if (wanted_order == print_order::preorder) {
            std::cout << "Preorder print: ";
            __preorder(root);
        }
        else if (wanted_order == print_order::inorder) {
            std::cout << "Inorder print: ";
            __inorder(root);
        }
        else if (wanted_order == print_order::postorder) {
            std::cout << "Postorder print: ";
            __postorder(root);
        }
        else {
            std::cout << "BFS print: ";
            __BFS(root);
        }

        std::cout << "\n";
    }

    // Check if all leaves are on the same level
    // I'll use BFS to calculate the heights and check
    // that all leaves's heights are the same
    bool checkSameLevelLeaves(BinaryTree<T> my_bt)
    {
        // Get root
        BinaryTreeNode<T>* my_root = my_bt.root;

        // If we have only the root, true
        if (!my_root->leftChild && !my_root->rightChild)
            return true;

        // Create queue of node addresses
        std::queue<BinaryTreeNode<T>*> my_queue;
        my_queue.push(my_root);

        // Create queue of terminal nodes
        std::queue<int> terminal_nodes;

        // Get level
        int level[100] = { 0 };

        // Search all elements
        while (!my_queue.empty()) {

            // Get first element from queue
            BinaryTreeNode<T>* front_element = my_queue.front();
            my_queue.pop();

            // Continue searching
            if (front_element->leftChild) {
                my_queue.push(front_element->leftChild);
                level[front_element->leftChild->data] = level[front_element->data] + 1;
            }
            if (front_element->rightChild) {
                my_queue.push(front_element->rightChild);
                level[front_element->rightChild->data] = level[front_element->data] + 1;
            }

            // Leaf
            if (!front_element->leftChild && !front_element->rightChild) {
                terminal_nodes.push(front_element->data);
            }
        }

        // Find last level
        int max_height = level[0];
        for (int i = 0; i < 100; ++i) {
            if (max_height < level[i])
                max_height = level[i];
        }

        // Check if all the terminal nodes are on the last level
        for (int i = 0; i < terminal_nodes.size(); ++i) {
            int my_node = terminal_nodes.front();
            terminal_nodes.pop();
            if (level[my_node] != max_height)
                return false;
        }

        return true;
    }

    // Check if the tree is balanced
    // I'll use BFS to calculate the heights and check
    // that all leaves's heights are the same or
    // at a difference of maximum 1
    bool checkBalancedTree(BinaryTree<T> my_bt)
    {
        // Get root
        BinaryTreeNode<T>* my_root = my_bt.root;

        // If we have only the root, true
        if (!my_root->leftChild && !my_root->rightChild)
            return true;

        // Create queue of node addresses
        std::queue<BinaryTreeNode<T>*> my_queue;
        my_queue.push(my_root);

        // Create queue of terminal nodes
        std::queue<int> terminal_nodes;

        // Get level
        int level[100] = { 0 };

        // Search all elements
        while (!my_queue.empty()) {

            // Get first element from queue
            BinaryTreeNode<T>* front_element = my_queue.front();
            my_queue.pop();

            // Continue searching
            if (front_element->leftChild) {
                my_queue.push(front_element->leftChild);
                level[front_element->leftChild->data] = level[front_element->data] + 1;
            }
            if (front_element->rightChild) {
                my_queue.push(front_element->rightChild);
                level[front_element->rightChild->data] = level[front_element->data] + 1;
            }

            // Leaf
            if (!front_element->leftChild && !front_element->rightChild) {
                terminal_nodes.push(front_element->data);
            }
        }

        // Find last level
        int max_height = level[0];
        for (int i = 0; i < 100; ++i) {
            if (max_height < level[i])
                max_height = level[i];
        }

        // Check if all the terminal nodes are on the last level
        for (int i = 0; i < terminal_nodes.size(); ++i) {
            int my_node = terminal_nodes.front();
            terminal_nodes.pop();
            if (abs(level[my_node] - max_height) > 1)
                return false;
        }

        return true;
    }

	// Release the memory
    void __postorder_clean(BinaryTreeNode<T>* root)
    {
        if (!root)
            return;

        __postorder_clean(root->leftChild);
        __postorder_clean(root->rightChild);
        delete root;
    }
    void clean_memory()
    {
        __postorder_clean(root);
    }
};

#endif // __BINARYTREE_H__
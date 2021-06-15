#include <iostream>
#include <vector>
#include <cmath>
#include "BinaryTree.h"

int main(void)
{
    // Create tree
    BinaryTree<int> my_binary_tree;

    // Insert data
    for (int i = 0; i < 10; ++i) {
        my_binary_tree.insert(i);
    }

    // Display tree nodes
    std::cout << "\n~~~~~~~~~~Displaying tree:~~~~~~~~~~\n";
    my_binary_tree.displayTree(print_order::BFS);
    my_binary_tree.displayTree(print_order::preorder);
    my_binary_tree.displayTree(print_order::inorder);
    my_binary_tree.displayTree(print_order::postorder);

    // Check if all the leaves are on the same level
    std::cout << "\nCheck if all the leaves are on the same level: ";
    std::cout << std::boolalpha << my_binary_tree.checkSameLevelLeaves(my_binary_tree) << "\n";

    // Add 5 nodes and check again
    std::cout << "Add 5 nodes to get all the leaves on the same level...\n";
    for (int i = 10; i <= 14; ++i) {
        my_binary_tree.insert(i);
    }
    std::cout << "Check if all the leaves are on the same level: ";
    std::cout << std::boolalpha << my_binary_tree.checkSameLevelLeaves(my_binary_tree) << "\n\n";

    // Check if the tree is balanced
    std::cout << "Check if the tree is balanced: ";
    std::cout << std::boolalpha << my_binary_tree.checkBalancedTree(my_binary_tree) << "\n\n";

	my_binary_tree.clean_memory();
	
    return 0;
}

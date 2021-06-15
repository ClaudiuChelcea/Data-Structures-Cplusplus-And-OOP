#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "Heap.h"
#include <fstream>
#include <assert.h>

// Read the input from the file and save it in a vector
auto getInputFromFile(std::ifstream& fileIN)
{
	// Declare variables to hold the values
	int nr_nodes { 0 };
	std::vector<int> my_nodes_values;

	// Get the input from the file
	fileIN >> nr_nodes;
	for (int i = 0; i < nr_nodes; ++i) {
		int value { 0 };
		fileIN >> value;
		my_nodes_values.push_back(value);
	}
	
	// Return the vector
	std::cout << "Read values from file, inserting them in BST and HEAP...\n";
	return my_nodes_values;
}

// Create and test BST
void check_BST(std::vector<int> my_nodes_values)
{
	std::cout << "\n==================================== START BST ============================\n\n";

 	// Create BST
    BinarySearchTree<int> *root = new BinarySearchTree<int>();

	// Insert the elements
	for(auto& element : my_nodes_values)
		root->insertKey(element);

	// Display the nodes in ascending order by value
	std::cout << "Display the nodes from the BST in an inorder traversal: ";
	root->inOrderDisplay();


	// Search keys root->searchKey(key)

	// Display ascending sorted nodes (inorder print)

	// root->findmax()

	// root->findmin()

	// root->displayLevels()

	// root->removekeys

	// check is bst

	// Clean memory
	root->inOrderCleanUp();
	delete root;
	std::cout << "\n\n==================================== END BST ============================\n\n";
}

int main(void)
{
	// Open input file
	std::ifstream fileIN;
	fileIN.open("input_file.txt", std::ios::in);
	assert(fileIN.is_open() ==  true && "Input file could not be opened!");

	// Declare vector to hold the nodes's values
	std::vector<int> my_nodes_values = getInputFromFile(fileIN);

	// Close the file
	fileIN.close();

	// Check the BST tree created with these values
	check_BST(my_nodes_values);

	return 0;
}
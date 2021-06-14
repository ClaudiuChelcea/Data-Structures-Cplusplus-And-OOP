#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"

#define STARTING_NODES 7

// Test the implementation for the graph with lists
void ListGraphCheck()
{
    std::cout << "\n=================== START LIST GRAPH ========================\n\n";

    // Create list graph
    ListGraph my_graph(STARTING_NODES);

    // Add edges
    std::cout << "Creating undirected list_graph...\n";
    my_graph.addEdge(0, 1);
    my_graph.addEdge(0, 2);
    my_graph.addEdge(0, 3);
    my_graph.addEdge(1, 4);
    my_graph.addEdge(1, 6);
    my_graph.addEdge(2, 5);
    my_graph.addEdge(2, 6);

    // Display list graph
    my_graph.printListGraph();

    // Remove some edges
    std::cout << "\nRemoving 1-6 and 0-2 edges...\n";
    my_graph.removeEdge(1, 6);
    my_graph.removeEdge(0, 2);

    // Display list graph
    my_graph.printListGraph();

    // Check if we have edge
    std::cout << "\nCheck if we have edge between 0 - 6: ";
    my_graph.hasEdge(0, 6) ? std::cout << "true\n" : std::cout << "false\n";
    std::cout << "Adding edge between 0 - 6...\n";
    my_graph.addEdge(0, 6);
    std::cout << "Check if we have edge between 0 - 6: ";
    my_graph.hasEdge(0, 6) ? std::cout << "true\n" : std::cout << "false\n";

    // Display list graph
    std::cout << "\nNew graph:\n";
    my_graph.printListGraph();

    // Display BFS
    my_graph.print_BFS(0);

    // Display DSF
    my_graph.print_DFS(0);

    std::cout << "\n=================== END LIST GRAPH ========================\n\n";
}

void MatrixGraphCheck()
{
    std::cout << "\n=================== START MATRIX GRAPH ========================\n\n";

    // Create matrix graph
    MatrixGraph my_graph(STARTING_NODES);

    // Add edges
    std::cout << "Creating undirected matrix_graph...\n";
    my_graph.addEdge(0, 1);
    my_graph.addEdge(0, 2);
    my_graph.addEdge(0, 3);
    my_graph.addEdge(1, 4);
    my_graph.addEdge(1, 6);
    my_graph.addEdge(2, 5);
    my_graph.addEdge(2, 6);

    // Display list graph
    my_graph.printMatrixGraph();

    // Remove some edges
    std::cout << "\nRemoving 1-6 and 0-2 edges...\n";
    my_graph.removeEdge(1, 6);
    my_graph.removeEdge(0, 2);

    // Display list graph
    my_graph.printMatrixGraph();

    // Check if we have edge
    std::cout << "\nCheck if we have edge between 0 - 6: ";
    my_graph.hasEdge(0, 6) ? std::cout << "true\n" : std::cout << "false\n";
    std::cout << "Adding edge between 0 - 6...\n";
    my_graph.addEdge(0, 6);
    std::cout << "Check if we have edge between 0 - 6: ";
    my_graph.hasEdge(0, 6) ? std::cout << "true\n" : std::cout << "false\n";

    // Display list graph
    std::cout << "\nNew graph:\n";
    my_graph.printMatrixGraph();

    // Display BFS
    my_graph.print_BFS(0);

    // Display DSF
    my_graph.print_DFS(0);

    std::cout << "\n=================== END MATRIX GRAPH ========================\n\n";
}

int main(void)
{
    // Check the implementation of the list graph
    ListGraphCheck();

    // Check the implementation of the adjacency matrix graph
    MatrixGraphCheck();

    return 0;
}

#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include <fstream>
#include <cassert>
#include <algorithm>
#include <list>

// Display the number of conex components from a graph using breadth-first search
static inline void funct_conex_components(std::ifstream& fileIN)
{
    // Get the number of vertices and create graph
    std::int_fast16_t vertices{ 0 };
    fileIN >> vertices;
    ListGraph my_graph(vertices);

    // Get the number of edges to add
    std::int_fast16_t edges{ 0 };
    fileIN >> edges;

    // Create the graf by getting the edges
    for (int i = 0; i < edges; ++i) {
        int src{ 0 };
        int dst{ 0 };

        // Get nodes
        fileIN >> src >> dst;
        my_graph.addEdge(src, dst);
    }

    // Split the graph in two components
    my_graph.removeEdge(1, 6);
    my_graph.removeEdge(0, 2);

    // Create visited node array
    int visited_array[vertices];
    for (int i = 0; i < vertices; ++i) {
        visited_array[i] = 0;
    }

    // Count the number of conex components
    std::int_fast16_t conex_components{ 0 };
    for (int i = 0; i < vertices; ++i) {
        if (!visited_array[i]) {
            my_graph.print_BFS(i, visited_array);
            ++conex_components;
        }
    }

    // Display the graph and the answer
    std::cout << "My graph for conex components algorithm is:\n\n";
    my_graph.printListGraph();
    std::cout << "\nThe number of conex components is: " << conex_components << "\n\n";
}

// Get the minimum distances from each node to each other node
// (when the cost is the same)
static inline void funct_min_distances(std::ifstream& fileIN)
{
    // Get the number of vertices and create graph
    std::int_fast16_t vertices{ 0 };
    fileIN >> vertices;
    ListGraph my_graph(vertices);

    // Get the number of edges to add
    std::int_fast16_t edges{ 0 };
    fileIN >> edges;

    // Create the graf by getting the edges
    for (int i = 0; i < edges; ++i) {
        int src{ 0 };
        int dst{ 0 };

        // Get nodes
        fileIN >> src >> dst;
        my_graph.addEdge(src, dst);
    }

    // Display the graph and the answer
    std::cout << "My graph for minimum distances with even cost algorithm is:\n\n";
    my_graph.printListGraph();

    // Create array to hold the distances
    int my_distances[vertices];
    for (int i = 0; i < vertices; ++i)
        my_distances[i] = 0;

    // Print the result for all vertices
    std::cout << "\nDistances from each node to all other nodes:\n";

    // Top row
    std::cout << "   ";
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    // Distances
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";

        // Apply algorithm on the node
        my_graph.distances_BFS(i, my_distances);

        // Display distances
        for (auto& element : my_distances) {
            std::cout << element << " ";
            element = 0;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Get topologic sort using DFS
static inline void funct_topo_sort(std::ifstream& fileIN)
{
    // Get the number of vertices and create graph
    std::int_fast16_t vertices{ 0 };
    fileIN >> vertices;
    MatrixGraph my_graph(vertices);

    // Get the number of edges to add
    std::int_fast16_t edges{ 0 };
    fileIN >> edges;

    // Create the graf by getting the edges
    for (int i = 0; i < edges; ++i) {
        int src{ 0 };
        int dst{ 0 };

        // Get nodes
        fileIN >> src >> dst;
        my_graph.addEdge(src, dst);
    }

    // Display the graph and the answer
    std::cout << "My graph for topologic sort algorithm is:\n\n";
    my_graph.printMatrixGraph();

    std::cout << "\n\nExpected output: 7 8 9 4 5 6 0 1 2 3";
    std::cout << "\nOutput: ";

    // Create vector of pairs that pairs a node with it's finish time
    // First int -> finish_time
    // Second int -> node value
    std::list<std::pair<int, int> > my_nodes_finish_time;

    // Create visited node array
    int visited_array[vertices];
    for (int i = 0; i < vertices; ++i) {
        visited_array[i] = 0;
    }

    // Walk through all the components and find the finish times
    for (int i = 0; i < vertices; ++i) {
        if (visited_array[i] == 0) {
            my_graph.topo_DFS(i, visited_array, my_nodes_finish_time);
        }
    }

    // Display output
    for (std::list<std::pair<int, int> >::iterator element = my_nodes_finish_time.begin(); element != my_nodes_finish_time.end(); ++element) {
        std::cout << element->second << " ";
    }

    std::cout << "\n\n";
}

// Get topologic sort using DFS
static inline void funct_check_bipartite(std::ifstream& fileIN)
{
    // Get the number of vertices and create graph
    std::int_fast16_t vertices{ 0 };
    fileIN >> vertices;
    MatrixGraph my_graph(vertices);

    // Get the number of edges to add
    std::int_fast16_t edges{ 0 };
    fileIN >> edges;

    // Create the graf by getting the edges
    for (int i = 0; i < edges; ++i) {
        int src{ 0 };
        int dst{ 0 };

        // Get nodes
        fileIN >> src >> dst;
        my_graph.addEdge(src, dst);
    }

    // Display the graph and the answer
    std::cout << "My graph for checking bipartite algorithm is:\n\n";
    my_graph.printMatrixGraph();

    std::cout << "\nExpected output: true";
    std::cout << "\nOutput: " << std::boolalpha << my_graph.bipartite_BFS(0);

    // Add edge and check again
    std::cout << "\n\nAdding edge to make the graph bipartite and check again...";
    my_graph.addEdge(5, 6);
    std::cout << "\n\nExpected output: false";
    std::cout << "\nOutput: " << std::boolalpha << my_graph.bipartite_BFS(0);

    std::cout << "\n\n";
}

// Separating output
void separation_line()
{
    std::cout << "==================================================================\n\n";
}

int main(void)
{
    // Open input file
    std::ifstream fileIN;
    fileIN.open("input_file.txt", std::ios::in);
    assert(fileIN.is_open() && "File couldn't open!");
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~Using algorithms~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

    // Get the number of conex components
    funct_conex_components(fileIN);
    separation_line();

    // Get the minimum distances from each node to each other node
    // (when the cost is the same)
    funct_min_distances(fileIN);
    separation_line();

    // Get topologic sort
    funct_topo_sort(fileIN);
    separation_line();

    // Check bipartite
    funct_check_bipartite(fileIN);

    // Close file
    fileIN.close();

    return 0;
}

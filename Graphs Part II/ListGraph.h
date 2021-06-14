#ifndef __LISTGRAPH_H__
#define __LISTGRAPH_H__

#include <vector>
#include <iterator>
#include <queue>
#include <stack>

/**
 * Node representation
 */
struct Node {
    std::vector<int> neighbors;
};

/**
 * Neighbors list implementation.
 */
class ListGraph {
private:
    // Vector of vectors
    // Each node has a vector of nodes representing adjacent nodes
    std::vector<Node> nodes;
    int size;

public:
    // Constructor
    ListGraph(int size)
    {
        this->size = size;
        nodes.resize(this->size);
    }

    // Destructor
    ~ListGraph() {}

    /**
     * Adds an edge between two existing nodes.
     */
    void addEdge(int src, int dst)
    {
        nodes[src].neighbors.push_back(dst);
        nodes[dst].neighbors.push_back(src);
    }

    // Remove element from a list
    void removeItem(int src, int dst)
    {
        // Getiterator
        std::vector<int>::iterator element = nodes[src].neighbors.begin();

        // Find element in the list
        for (; element != nodes[src].neighbors.end(); ++element) {
            if (*element == dst) {
                break;
            }
        }

        // Remove element for the list
        nodes[src].neighbors.erase(element, element + 1);
    }
    /**
     * Removes an existing edge from the graph.
     */
    void removeEdge(int src, int dst)
    {
        // Remove edge from the first node
        removeItem(src, dst);

        // Remove edge from the second node
        removeItem(dst, src);
    }

    /**
     * Checks if there is an edge between two existing nodes..
     */
    bool hasEdge(int src, int dst)
    {
        // Getiterator
        std::vector<int>::iterator element = nodes[src].neighbors.begin();

        // Find element in the first list
        for (; element != nodes[src].neighbors.end(); ++element) {
            if (*element == dst) {
                return true;
            }
        }

        return false;
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     */
    std::vector<int> getNeighbors(int node)
    {
        return nodes[node].neighbors;
    }

    /**
     * Gets the graph size.
     *
     * @return Number of nodes in the graph.
     */
    int getSize()
    {
        return size;
    }

    // Print the whole graph
    void printListGraph()
    {
        for (int i = 0; i < size; ++i) {
            std::cout << i << ": ";
            for (int j = 0; j < nodes.at(i).neighbors.size(); j++) {
                if (j != nodes[i].neighbors.size() - 1)
                    std::cout << nodes.at(i).neighbors[j] << "--> ";
                else
                    std::cout << nodes.at(i).neighbors[j];
            }
            std::cout << "\n";
        }
    }

    // BFS algorithm
    // Add the first element in the queue and mark it as visited
    // While the queue is not empty, get the first element, pop it
    // and get the neightbors of the node
    // Add them to the queue if they are not visited
    // Repeat until we fully visited all nodes
    void print_BFS(int root, int visited[])
    {
        // Create queue with the root
        std::queue<int> my_queue;
        my_queue.push(root);

        visited[root] = 1;
        while (!my_queue.empty()) {
            // Get all neighbors of the current element and display our element
            std::vector<int> my_neighbors = getNeighbors(my_queue.front());
            my_queue.pop();

            // For each neighbour, if it is not visited, visit it
            for (auto& element : my_neighbors) {
                if (visited[element] == 0) {
                    visited[element] = 1;
                    my_queue.push(element);
                }
            }
        }
    }

    // BFS minimum distances
    void distances_BFS(int root, int my_distances[])
    {
        // Create queue with the root
        std::queue<int> my_queue;
        my_queue.push(root);
        my_distances[root] = 0;

        // Create visited vector
        int visited[size];
        for (int i = 0; i < size; i++)
            visited[i] = 0;
        visited[root] = 1;

        while (!my_queue.empty()) {
            // Get all neighbors of the current element and display our element
            int parent = my_queue.front();
            std::vector<int> my_neighbors = getNeighbors(my_queue.front());
            my_queue.pop();

            // For each neighbour, if it is not visited, visit it
            for (auto& element : my_neighbors) {
                if (visited[element] == 0) {
                    visited[element] = 1;
                    my_queue.push(element);
                    my_distances[element] = my_distances[parent] + 1;
                }
            }
        }
    }

    // DFS algorithm
    // Start from a root
    // Use a stack to start with the root
    // Find the first not-visited node
    // If we can't, pop the stack
    // Repeat until all nodes have been visited
    void print_DFS(int root)
    {
        // Create visited vector
        int visited[size];
        for (int i = 0; i < size; i++)
            visited[i] = 0;

        // Create stack of elements
        std::stack<int> my_stack;

        // Add root and mark as visited
        visited[root]++;
        my_stack.push(root);

        // Repeat until the stack is empty
        while (!my_stack.empty()) {
            // Get neighbors
            std::vector<int> my_neighbors = getNeighbors(my_stack.top());

            // Find the virst non-visited neighbour
            int my_nonvisited_neighbour = -1;
            for (int i = 0; i < my_neighbors.size(); ++i) {
                if (!visited[my_neighbors[i]]) {
                    my_nonvisited_neighbour = my_neighbors[i];
                    break;
                }
            }

            // Check the first neighbour
            if (my_nonvisited_neighbour != -1) {
                visited[my_nonvisited_neighbour]++;
                my_stack.push(my_nonvisited_neighbour);
            }
            else {
                my_stack.pop();
            }
        }
    }
};

#endif // __LISTGRAPH_H__

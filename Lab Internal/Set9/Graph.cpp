#include <iostream>

const int MAX_VERTICES = 5;

class Graph {
private:
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int v) : vertices(v) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w) {
        adjacencyMatrix[v][w] = 1;
        adjacencyMatrix[w][v] = 1;
    }

    void printGraph() {
        std::cout << "Adjacency matrix representation of the graph:\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency matrix representation of the graph
    graph.printGraph();

    return 0;
}


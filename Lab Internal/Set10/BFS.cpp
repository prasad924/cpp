#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 6;

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
        adjacencyMatrix[w][v] = 1; // For undirected graph
    }

    void BFS(int startVertex) {
        bool visited[MAX_VERTICES] = {false};
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth-First Search starting from vertex " << startVertex << ":\n";

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int neighbor = 0; neighbor < vertices; ++neighbor) {
                if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    // Perform BFS starting from vertex 0
    graph.BFS(0);

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);
    cout<<"Himank Kumar C0/206"<<endl;
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Printing the adjacency list representation of the graph
    graph.printGraph();

    return 0;
}
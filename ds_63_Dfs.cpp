#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int from, int to) {
        adjList[from].push_back(to);
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        DFSUtil(startVertex, visited);
    }
};

int main() {
    int numVertices = 6;
    cout<<"Himank Kumar C0/206"<<endl;
    Graph g(numVertices);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
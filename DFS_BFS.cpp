#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int start, vector<bool> &visited)
    {
        visited[start] = true;
        cout << start << " ";

        for (int i : adj[start])
        {
            if (!visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i : adj[v])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (in the format 'u v'):\n";
    for (int i = 0; i < numEdges; ++i)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    g.DFS(startVertex);
    cout << endl;

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    g.BFS(startVertex);
    cout << endl;

    return 0;
}
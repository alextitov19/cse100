#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge
{
    int dest;
    int weight;
};

struct Vertex
{
    int key;
    int parent;
    bool inMST;
};

int minKey(vector<Vertex> &vertices, int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (!vertices[v].inMST && vertices[v].key < min)
        {
            min = vertices[v].key;
            min_index = v;
        }
    }
    return min_index;
}

void printMST(vector<Vertex> &vertices, int V)
{
    for (int i = 1; i < V; ++i)
        cout << vertices[i].parent << endl;
}

void primMST(vector<vector<Edge>> &graph, int V)
{
    vector<Vertex> vertices(V);
    for (int i = 0; i < V; ++i)
    {
        vertices[i].key = INT_MAX;
        vertices[i].inMST = false;
    }

    vertices[0].key = 0;
    vertices[0].parent = -1;
    for (int count = 0; count < V - 1; ++count)
    {
        int u = minKey(vertices, V);
        vertices[u].inMST = true;

        for (auto &edge : graph[u])
        {
            int v = edge.dest;
            int weight = edge.weight;
            if (!vertices[v].inMST && weight < vertices[v].key)
            {
                vertices[v].parent = u;
                vertices[v].key = weight;
            }
        }
    }

    printMST(vertices, V);
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<Edge>> graph(V);

    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge1 = {v, w};
        Edge edge2 = {u, w};
        graph[u].push_back(edge1);
        graph[v].push_back(edge2);
    }

    primMST(graph, V);

    return 0;
}

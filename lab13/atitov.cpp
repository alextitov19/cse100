#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(vector<Edge> &edges, int V, int E, int src)
{
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; ++i)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v])
        {
            cout << "FALSE" << endl;
            return;
        }
    }

    cout << "TRUE" << endl;
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] == numeric_limits<int>::max())
        {
            cout << "INFINITY" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    bellmanFord(edges, V, E, 0);

    return 0;
}

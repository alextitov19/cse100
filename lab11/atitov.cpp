#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void DFS(vector<int> *G, bool *seen, int *f, int v, stack<int> &order)
{
    seen[v] = true;
    for (int u : G[v])
    {
        if (!seen[u])
        {
            DFS(G, seen, f, u, order);
        }
    }
    order.push(v);
}

void DFS2(vector<int> *GT, bool *seen, vector<int> &scc, int v)
{
    seen[v] = true;
    scc.push_back(v);
    for (int u : GT[v])
    {
        if (!seen[u])
        {
            DFS2(GT, seen, scc, u);
        }
    }
}

int main()
{
    int V; // no. of vertices
    int E; // no. of edges
    cin >> V >> E;

    vector<int> *G = new vector<int>[V];
    vector<int> *GT = new vector<int>[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        GT[v].push_back(u);
    }

    bool *seen = new bool[V];
    fill(seen, seen + V, false);

    stack<int> order;
    for (int i = 0; i < V; i++)
    {
        if (!seen[i])
        {
            DFS(G, seen, nullptr, i, order);
        }
    }

    fill(seen, seen + V, false);
    int *res = new int[V];
    fill(res, res + V, -1);

    int sccid = 0;
    while (!order.empty())
    {
        int v = order.top();
        order.pop();
        if (!seen[v])
        {
            vector<int> scc;
            DFS2(GT, seen, scc, v);
            int minVertex = *min_element(scc.begin(), scc.end());
            for (int u : scc)
            {
                res[u] = minVertex;
            }
            sccid++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << endl;
    }

    delete[] G;
    delete[] GT;
    delete[] seen;
    delete[] res;

    return 0;
}

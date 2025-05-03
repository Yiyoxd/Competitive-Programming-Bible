#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

class Graph
{
    int totalNodes;
    vector<int> *adjList;

public:
    Graph(int n)
    {
        totalNodes = n;
        adjList = new vector<int>[totalNodes];
    }

    void addEdge(int x, int y, bool bidirectional = true)
    {
        adjList[x].push_back(y);
        if (bidirectional)
        {
            adjList[y].push_back(x);
        }
    }

    void dfsHelper(int node, bool *visited)
    {
        visited[node] = true;
        cout << node << ",";

        // make a dfs call on all its unvisited neighbours
        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
        return;
    }

    void dfs(int source)
    {
        bool *visited = new bool[totalNodes]{0};
        dfsHelper(source, visited);
    }
};

int32_t main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.dfs(1);
    return 0;
}
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

    void bfs(int source)
    {

        queue<int> q;
        bool *visited = new bool[totalNodes]{0};

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            // Do some work for every node
            int f = q.front();
            cout << f << ",";
            q.pop();

            // PUsh the nbrs of current node inside q if they are not already visited
            for (auto neighbor : adjList[f])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
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
    g.bfs(1);
    return 0;
}
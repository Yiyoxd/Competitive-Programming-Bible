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

    void printAdjList()
    {
        // Iterate over all the rows
        for (int i = 0; i < totalNodes; i++)
        {
            cout << i << "-->";
            // every element of ith linked list
            for (auto node : adjList[i])
            {
                cout << node << ",";
            }
            cout << endl;
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
    g.printAdjList();
    return 0;
}
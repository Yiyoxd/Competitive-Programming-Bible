#include <bits/stdc++.h>
#define int long long int
#define vec vector<int>
#define vecP vector<pair<int, int>>
using namespace std;

class Node
{
public:
    string name;
    vector<string> neighbors;

    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{
    // Node Name -- Pointer to Node Object
    unordered_map<string, Node *> mp;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            mp[city] = new Node(city);
        }
    }
    void addEdge(string x, string y, bool bidirectional = true)
    {
        mp[x]->neighbors.push_back(y);
        if (bidirectional)
        {
            mp[y]->neighbors.push_back(x);
        }
    }

    void printAdjList()
    {
        for (auto cityPair : mp)
        {
            auto city = cityPair.first;
            cout << city << "-->";
            Node *node = cityPair.second;
            for (auto nbr : node->neighbors)
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int32_t
main()
{
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London", false);
    g.addEdge("New York", "London", false);
    g.addEdge("Delhi", "Paris", false);
    g.addEdge("Paris", "New York", false);
    g.printAdjList();
    return 0;
}
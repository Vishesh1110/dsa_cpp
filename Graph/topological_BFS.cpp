#include <bits/stdc++.h>
using namespace std;

// For cycle detection in a Directed graph, if the toposort has all the vertices then it is
// not having a cycle otherwise yes it is having a cycle

int main()
{
    vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = adj.size();
    vector<int> indegree(V, 0);

    for(int i = 0; i < V; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        // Node is in your topo sort
        // so please remove it from the indegree

        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    for(auto it : topo)
    {
        cout << it << " ";
    }

    return 0;
}
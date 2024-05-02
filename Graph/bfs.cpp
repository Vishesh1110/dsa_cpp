/*Time Complexity: O(N) + O(2E)
  Space Complexity: O(N) (Queue ds, visited[])*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int v, vector<int> adj[], int src)
{
    int visited[v] = {0};
    visited[src] = 1;

    queue<int> q;
    q.push(src);

    vector<int> bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    /*  
        0-------1
        |       |\
        |       | \
        |       |  4
        |       |  /
        |       | / 
        2-------3

        Pair of Nodes with an edge connection
        0 1
        0 2
        1 3
        1 4
        2 3
        3 4

        Space Complexity: O(2E)
    */


    cout << "Enter the total number of nodes and edges of the Graph:\n";
    int v, e;
    cin >> v >> e;

    vector<int> adj[v+1];

    cout << "\nEnter the 2 nodes which are connected:\n";
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);     // In case of Directed graph, this should be omitted
    }

    // Display the adjacency list
    cout << "\nAdjacency List\n";
    for(int i = 0; i < v; i++)
    {
        cout << i << " --> ";
        for(int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    vector<int> traversal;
    traversal = bfs(v, adj, 2);
    cout << "\nBFS traversal\n";
    for(auto it : traversal) cout << it << " ";   
    return 0;
}
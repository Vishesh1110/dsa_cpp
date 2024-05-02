/*Time Complexity : O(N) + O(2E)
  Space Complexity : O(N)
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<int> adj[], int visited[], vector<int>& traverse)
{
    visited[start] = 1;
    traverse.push_back(start);

    for(auto it: adj[start])    // Traversing the neighbours
    {
        if(!visited[it])
        {
            dfs(it, adj, visited, traverse);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[], int src)
{
    int visited[v] = {0};
    vector<int> traverse;
    dfs(src, adj, visited, traverse);
    return traverse;
}

int main()
{
    /*  
            0
            /\
           /  \
          1    2------3
          /\    |     |
         /  \   |     |
        4    5  6-----7

        Nodes = 8
        Edges = 8

        Pair of Nodes with an edge connection
        0 1
        0 2
        1 4
        1 5
        2 3
        2 6
        3 7
        6 7

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

    vector<int> traverse;
    traverse =  dfsOfGraph(8, adj, 0);

    cout << "\nDFS of Graph\n";
    for(auto it : traverse) cout << it << " ";

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

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
    return 0;
}
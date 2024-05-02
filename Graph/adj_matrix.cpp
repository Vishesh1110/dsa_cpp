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

        Space Complexity: O(NxN)
    */


    cout << "Enter the total number of nodes and edges of the Graph:\n";
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj(nodes, vector<int>(nodes, 0));

    cout << "\nEnter the 2 nodes which are connected:\n";
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Display the adjacency matrix
    cout << "\nAdjacency Matrix\n";
    for(int i = 0; i < nodes; i++)
    {
        for(int j = 0; j < nodes; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
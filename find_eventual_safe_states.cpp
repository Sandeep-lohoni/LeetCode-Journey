// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0 - indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges.A node is a safe node if every possible path starting from that node leads to a terminal
// node(or another safe node)
// Return an array containing all the safe nodes of the graph.The answer should be sorted in ascending order.

// Example 1 :

// Illustration of graph Input : graph = [ [ 1, 2 ], [ 2, 3 ], [5], [0], [5], [], [] ] Output : [ 2, 4, 5, 6 ] Explanation : The given graph is shown above.Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.Every path starting at nodes 2,
// 4, 5, and6 all lead to either node 5 or 6. Example 2 :

// Input : graph = [ [ 1, 2, 3, 4 ], [ 1, 2 ], [ 3, 4 ], [ 0, 4 ], [] ] Output : [4] Explanation : Only node 4 is a terminal node,
// and every path starting at node 4 leads to node 4.

// solution

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int start, vector<int> &vis, vector<int> &pathVis, vector<int> &notcycle, vector<vector<int>> &graph)
    {
        vis[start] = 1;
        pathVis[start] = 1;
        notcycle[start] = 0;
        for (auto it : graph[start])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, pathVis, notcycle, graph) == true)
                {
                    notcycle[it] = 0;
                    return true;
                }
            }
            else if (pathVis[it])
            {
                notcycle[it] = 0;
                return true;
            }
        }
        notcycle[start] = 1;
        pathVis[start] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);
        vector<int> notcycle(v, 0);
        for (int i = 0; i < v; ++i)
        {
            if (!vis[i])
            {
                dfs(i, vis, pathVis, notcycle, graph);
            }
        }
        vector<int> ans;
        for (int i = 0; i < v; ++i)
        {
            if (notcycle[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
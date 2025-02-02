// Given an undirected connected graph with V vertices and adjacency list adj.You are required to find all the vertices removing which(and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.Note : Indexing is zero - based i.e nodes numbering from(0 to V - 1).There might be loops present in the graph.

// Your Task : You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int v, vector<int> adj[])
    {
        // Code here
        vector<int> vis(v, 0);
        vector<int> tin(v, 0);
        vector<int> low(v, 0);
        vector<int> mark(v, 0);
        vector<int> ans;
        for (int i = 0; i < v; ++i)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        for (int i = 0; i < v; ++i)
        {
            if (mark[i] == 1)
                ans.push_back(i);
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};
// Given a Directed Graph with V vertices(Numbered from 0 to V - 1) and E edges, check whether it contains any cycle or not .The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i.Specifically, adj[i][j] represents an edge from vertex i to vertex j.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCyclic(int v, vector<vector<int>> adj)
    {
        // code here
        vector<int> indegree(v, 0);
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < v; ++i)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }
        for (int i = 0; i < v; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (cnt == v)
            return false;
        return true;
    }
};
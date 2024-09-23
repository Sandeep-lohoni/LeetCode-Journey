// There are n cities.Some of them are connected, while some are not .If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

//A province is a group of directly or
//indirectly connected cities and no other cities outside of the group.

//You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected,
//and isConnected[i][j] = 0 otherwise.

//Return the total number of provinces.

//Example 1 :

//Input : isConnected = [ [ 1, 1, 0 ], [ 1, 1, 0 ], [ 0, 0, 1 ] ] Output : 2 Example 2 :

//Input : isConnected = [ [ 1, 0, 0 ], [ 0, 1, 0 ], [ 0, 0, 1 ] ] Output : 3

//Constraints :

//1 <= n <= 200 n ==
//isConnected.length
//n == isConnected[i].length isConnected[i][j] is 1 or
//0

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (int &num : adj[node])
        {
            if (!vis[num])
            {
                dfs(num, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<int> vis(V, 0);
        int cnt = 0;
        vector<int> adj[V];
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < isConnected[0].size(); ++j)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};
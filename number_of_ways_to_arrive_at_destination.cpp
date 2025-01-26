// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi - directional roads between some intersections.The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ ui, vi, timei ] means that there is a road between intersections ui and vi that takes timei minutes to travel.You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time.Since the answer may be large,
// return it modulo 109 + 7.

// Example 1 :

// Input : n = 7,
// roads = [ [ 0, 6, 7 ], [ 0, 1, 2 ], [ 1, 2, 3 ], [ 1, 3, 3 ], [ 6, 3, 3 ], [ 3, 5, 1 ], [ 6, 5, 1 ], [ 2, 5, 1 ], [ 0, 4, 5 ], [ 4, 6, 2 ] ] Output : 4 Explanation : The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.The four ways to get there in 7 minutes are : -0 ➝ 6 - 0 ➝ 4 ➝ 6 - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6 - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6 Example 2 :

// Input : n = 2,
// roads = [[ 1, 0, 10 ]] Output : 1 Explanation : There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int mod = 1e9 + 7;
        vector<long long> dist(n, LONG_MAX);
        vector<int> path(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[0] = 0;
        path[0] = 1;
        pq.push({0, 0});
        while (!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int adjdis = it.second;
                if ((long long)(dis + adjdis) < dist[adjnode])
                {
                    dist[adjnode] = (long long)(dis + adjdis);
                    pq.push({dis + adjdis, adjnode});
                    path[adjnode] = path[node];
                }
                else if ((long long)dis + adjdis == dist[adjnode])
                {
                    path[adjnode] = (path[adjnode] + path[node]) % mod;
                }
            }
        }
        return path[n - 1] % mod;
    }
};
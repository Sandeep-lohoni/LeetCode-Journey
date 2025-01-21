// You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

// solution

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
      vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
      {
          vector<int> adj[N]; 
          for (int i = 0; i < M; i++)
          { 
              int u = edges[i][0];
              int v = edges[i][1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          queue<pair<int, int>> q;  
          vector<int> dist(N, 1e9); 
          q.push({src, 0}); 
          dist[src] = 0;    
          while (!q.empty())
          {
              int node = q.front().first;      
              int distance = q.front().second; 
              q.pop();
              for (int neighbour : adj[node])
              {
                  if (distance + 1 < dist[neighbour])
                  {
                      dist[neighbour] = distance + 1;
                      q.push({neighbour, distance + 1});
                  }
              }
          }
          for (int i = 0; i < N; i++)
          {
              if (dist[i] == 1e9)
                  dist[i] = -1;
          }
          return dist;
      }
};
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    DisjointSet ds(9);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}
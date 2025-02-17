// You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).

//                                                                                                                             Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.

// As the answer can be very large, return the output modulo 1000000007.

// Note :

// ‘T’ will represent the operand TRUE.
// ‘F’ will represent the operand FALSE.
// ‘|’ will represent the operator OR.
// ‘&’ will represent the operator AND.
// ‘^’ will represent the operator XOR.Example :

//     Input : 'exp’ = "T|T & F".

//     Output : 1

//     Explanation : There are total 2 ways to parenthesize this expression : (i)(T | T) & (F) = F(ii)(T) | (T & F) = T Out of 2 ways,
// one will result in True,
// so we will return 1. Detailed explanation(Input / output format, Notes, Images)
// Sample Input 1 : T ^ T ^ F Sample Output 1 : 0 Explanation For Sample Input 1 : There are total 2 ways to parenthesize this expression : (i)(T ^ T) ^ (F) = F(ii)(T) ^ (T ^ F) = F Both ways will result in False, so we will return 0. Sample Input 2 : F | T ^ F
// Sample Output 2 : 2 Explanation For Sample Input 2 : For the first test case:
// There are total 2 ways to parenthesize this expression : (i)(F | T) ^ (F) = T(ii)(F) | (T ^ F) = T Both ways will result in True, so we will return 2. Expected time complexity The expected time complexity is O(n ^ 3), where 'n' denotes the length of 'exp'.

// solution

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
class Solution
{
    // memoization
private:
    int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue)
            {
                return exp[i] == 'T';
            }
            else
            {
                return exp[i] == 'F';
            }
        }
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        ll ways = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            ll lt = f(i, k - 1, 1, exp, dp);
            ll lf = f(i, k - 1, 0, exp, dp);
            ll rt = f(k + 1, j, 1, exp, dp);
            ll rf = f(k + 1, j, 0, exp, dp);

            if (exp[k] == '&')
            {
                if (isTrue)
                    ways = (ways + (lt * rt) % mod) % mod;
                else
                    ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
            }
            else if (exp[k] == '|')
            {
                if (isTrue)
                    ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (rt * lf) % mod) % mod;
                else
                    ways = (ways + (lf * rf) % mod) % mod;
            }
            else
            {
                if (isTrue)
                    ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
                else
                    ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
        return dp[i][j][isTrue] = ways;
    }

public:
    int evaluateExp(string &exp)
    {
        // Write your code here.
        int n = exp.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
        return f(0, n - 1, 1, exp, dp);
    }

    
    // tabulation
    int evaluateExp(string &exp)
    {
        // Write your code here.
        int n = exp.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j <= n - 1; ++j)
            {
                if (i > j)
                    continue;
                for (int isTrue = 0; isTrue <= 1; ++isTrue)
                {
                    if (i == j)
                    {
                        if (isTrue)
                            dp[i][j][isTrue] = exp[i] == 'T';
                        else
                            dp[i][j][isTrue] = exp[i] == 'F';
                        continue;
                    }
                    ll ways = 0;
                    for (int k = i + 1; k <= j - 1; k += 2)
                    {
                        ll lt = dp[i][k - 1][1];
                        ll lf = dp[i][k - 1][0];
                        ll rt = dp[k + 1][j][1];
                        ll rf = dp[k + 1][j][0];

                        if (exp[k] == '&')
                        {
                            if (isTrue)
                                ways = (ways + (lt * rt) % mod) % mod;
                            else
                                ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
                        }
                        else if (exp[k] == '|')
                        {
                            if (isTrue)
                                ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (rt * lf) % mod) % mod;
                            else
                                ways = (ways + (lf * rf) % mod) % mod;
                        }
                        else
                        {
                            if (isTrue)
                                ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
                            else
                                ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }
        return dp[0][n - 1][1];
    }
};
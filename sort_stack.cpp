// Given a stack, the task is to sort it such that the top of the stack has the greatest element.


// SOLUTION
#include <bits/stdc++.h>
using namespace std;
/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

void insertCorrectPosition(int x, stack<int> &s)
{
    if (s.size() == 0 || s.top() < x)
    {
        s.push(x);
    }
    else
    {
        int a = s.top();
        s.pop();
        insertCorrectPosition(x, s);
        s.push(a);
    }
}
void reverse(stack<int> &s)
{
    if (s.size() > 0)
    {
        int x = s.top();
        s.pop();
        reverse(s);
        insertCorrectPosition(x, s);
    }
}
void sort(stack<int> &s)
{
  
    reverse(s);
}
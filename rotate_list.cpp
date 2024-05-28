// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

// solution

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *findlast(ListNode *temp, int l)
    {
        int cnt = 1;
        while (temp != NULL)
        {
            if (cnt == l)
                return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || k == 0)
            return head;
        ListNode *tail = head;
        int len = 1;
        while (tail->next != NULL)
        {
            tail = tail->next;
            len += 1;
        }
        if (k % len == 0)
            return head;
        k = k % len;
        tail->next = head;
        ListNode *lastnode = findlast(head, len - k);
        head = lastnode->next;
        lastnode->next = NULL;
        return head;
    }
};
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

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
    ListNode *reversepart(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode *getkthnode(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *prevLast = NULL;
        ListNode *temp = head;
        while (temp != NULL)
        {
            ListNode *kthnode = getkthnode(temp, k);
            if (kthnode == NULL)
            {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }
            ListNode *nextnode = kthnode->next;
            kthnode->next = NULL;
            reversepart(temp);
            if (temp == head)
            {
                head = kthnode;
            }
            else
            {
                prevLast->next = kthnode;
            }
            prevLast = temp;
            temp = nextnode;
        }
        return head;
    }
};
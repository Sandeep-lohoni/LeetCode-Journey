// Given the head of a singly linked list, return true if it is a
// palindrome
//  or false otherwise.

// Example 1:

// Input: head = [1,2,2,1]
// Output: true
// Example 2:

// Input: head = [1,2]
// Output: false

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

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
    ListNode *reverselist(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newhead = reverselist(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead = reverselist(slow->next);
        ListNode *first = head;
        ListNode *second = newhead;
        while (second != NULL)
        {

            if (first->val != second->val)
            {
                reverselist(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverselist(newhead);
        return true;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* curNode = newHead, *lastNthNodeFront = NULL;
        while (curNode->next != NULL)
        {
            n--;
            if (n == 0) 
            {
                lastNthNodeFront = newHead;
            }
            else if (n < 0)
            {
                lastNthNodeFront = lastNthNodeFront->next;
            }
            curNode = curNode->next;
        }
        ListNode *tmp = lastNthNodeFront->next;
        lastNthNodeFront->next = lastNthNodeFront->next->next;
        delete tmp;
        ListNode* ret = newHead->next;
        delete newHead;
        return newHead->next;
        
    }
};

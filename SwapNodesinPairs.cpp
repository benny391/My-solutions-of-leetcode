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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pFront = newHead;

        while (pFront->next != NULL && pFront->next->next != NULL)
        {
            ListNode *pFirst = pFront->next, *pSecond = pFront->next->next;
            ListNode *pThird = pFront->next->next->next;
            pFront->next = pSecond;
            pSecond->next = pFirst;
            pFirst->next = pThird;
            
            pFront = pFirst;
        }
        return newHead->next;
    }
};

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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *l3 = new ListNode(0);
            ListNode *curNode = l3;
            int j = 0;
            while (l1 != NULL || l2 != NULL || j != 0) {

                int l1v = (l1 == NULL) ? 0 : l1->val, l2v = (l2 == NULL) ? 0 : l2->val;
                curNode->val = (l1v + l2v + j) % 10;
                j = (l1v + l2v + j) / 10;

                l1 = (l1 == NULL) ? NULL : l1->next;
                l2 = (l2 == NULL) ? NULL : l2->next;

                if (l1 != NULL || l2 != NULL || j != 0) {

                    curNode->next = new ListNode(0);
                    curNode = curNode->next;
                }
            }
            return l3;
        }
};

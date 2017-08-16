/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class myfunc {
    public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, myfunc > p;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL) {
                p.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *curNode = head;
        while ( !p.empty() ) {
            curNode->next = new ListNode(p.top().first);
            curNode = curNode->next;
            int i = p.top().second;
            p.pop();
            if (lists[i] != NULL) {
                p.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        return head->next;
    }
};

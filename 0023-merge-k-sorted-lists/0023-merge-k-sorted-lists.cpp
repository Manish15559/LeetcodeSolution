/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            curr;
        for (auto it : lists) {
            if (it != NULL)
                curr.push({it->val, it});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!curr.empty()) {
            auto it = curr.top();
            curr.pop();
            temp->next = it.second;
            temp = temp->next;
            if (it.second->next != NULL) {
                curr.push({it.second->next->val, it.second->next});
            }
        }
        return dummy->next;
    }
};
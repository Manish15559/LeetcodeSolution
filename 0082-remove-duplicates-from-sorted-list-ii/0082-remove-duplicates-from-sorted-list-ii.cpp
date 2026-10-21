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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyhead = new ListNode(-1, head);
        ListNode* curr = dummyhead;
        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int duplicateVal = curr->next->val;
                ListNode* temp = curr->next;
                while (temp && temp->val == duplicateVal) {
                    ListNode* nextNode = temp->next;
                    delete temp;
                    curr->next = nextNode;
                    temp = curr->next;
                }

            } else
                curr = curr->next;
        }
        return dummyhead->next;
    }
};
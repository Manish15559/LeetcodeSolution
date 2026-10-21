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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right)
            return head;
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* previousToLeftNode = dummyHead;
        for (int i = 1; i < left; i++) {
            previousToLeftNode = previousToLeftNode->next;      
        }
        ListNode* prev = NULL;
        ListNode* curr = previousToLeftNode->next;
        ListNode* temp = previousToLeftNode->next;
        for (int i = 0; i < (right - left + 1); i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        previousToLeftNode->next = prev;
        temp->next = curr;

        return dummyHead->next;
    }
};
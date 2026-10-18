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
    ListNode *reverse(ListNode *node){
        if(node==NULL||node->next==NULL) return node;
        ListNode *head= reverse(node->next);
        ListNode *front=node->next;
        front->next=node;
        node->next=NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
       return reverse(head);
    }
};
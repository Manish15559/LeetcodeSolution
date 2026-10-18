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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode *headNext= head->next;

       
       while(evenNode!=NULL&&evenNode->next!=NULL){
        
        oddNode->next=oddNode->next->next;
        oddNode=oddNode->next;
        evenNode->next=evenNode->next->next;
        evenNode=evenNode->next;
       }

       oddNode->next=headNext;
       return head;

        return head;
    }
};
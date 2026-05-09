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
    //find kth node
    ListNode* findkthNode(ListNode *node,int k){
        while(k>0&&node!=NULL){
            k--;
            node=node->next;

        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1,head);

        ListNode *curr=dummy;
        while(curr->next!=NULL){
            ListNode *kthNode = findkthNode(curr,k);
            if(kthNode==NULL) break;
            ListNode *nextGroup =kthNode->next;
            kthNode->next = NULL;

            ListNode *temp=curr->next;
            ListNode *prev=NULL;
            while(temp){
                ListNode *nextNode = temp->next;
                temp->next=prev;
                prev=temp;
                temp=nextNode;
            }
            temp = curr->next;
            curr->next=kthNode;
            temp->next=nextGroup;
            curr=temp;
        }
        return dummy->next;

        
    }
};
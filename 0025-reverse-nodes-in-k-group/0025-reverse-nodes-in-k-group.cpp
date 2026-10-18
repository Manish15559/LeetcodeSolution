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
    ListNode* findKthNode(ListNode* node, int k) {
        k--;
        while (node != NULL && k > 0) {
            node = node->next;
            k--;
        }
        return node;
    }
    void reverse(ListNode* node) {
        ListNode* prev = NULL;
        ListNode* curr = node;
        while (curr != NULL) {
            // cout<<curr->val<<" ";
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        // cout<<endl;
        
        // return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* previousGroupNode = NULL;
        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);
            
            if (kthNode == NULL) {
                if(temp!=head) previousGroupNode ->next =  temp;

                break;
            }
            ListNode* nextGroupStartNode = kthNode->next;
            kthNode->next = NULL;
            // cout<<kthNode->val<<endl;
            reverse(temp);
            if (previousGroupNode != NULL) {
                previousGroupNode->next = kthNode;

            } else {
                head = kthNode;
            }
            previousGroupNode = temp;

            temp = nextGroupStartNode;
        }
        return head;
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {            //1 2 3 3 4 4 5    curr=1 currnext=2 currnextmext=3
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* curr = dummyHead;
        while (curr != NULL && curr->next != NULL && curr->next->next != NULL) {
            ListNode* currNext = curr->next;
            ListNode* currNextToNext = curr->next->next;
            cout<<curr->val<<" "<<currNext->val<<" "<<currNextToNext->val<<endl;
            if (currNext->val == currNextToNext->val) {
                ListNode* temp = currNextToNext;
                while (temp != NULL && currNext->val == temp->val) {
                    ListNode* nextNode = temp->next;
                    delete temp;
                    currNext->next = nextNode;
                    temp = nextNode;
                }
                ListNode* nextNode = currNext->next;
                delete currNext;
                curr->next = nextNode;
               

            } else {
              
                curr = currNext;
            }
        }
        return dummyHead->next;
    }
};
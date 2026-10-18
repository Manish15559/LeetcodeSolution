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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        int prevNodePosition = cnt - n;

        if (prevNodePosition == 0) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        temp = head;
        while (temp != NULL) {
            prevNodePosition--;
            if (prevNodePosition == 0) {
                ListNode* deleteNode = temp->next;
                temp->next = temp->next->next;
                delete deleteNode;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
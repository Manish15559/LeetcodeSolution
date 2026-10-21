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
    ListNode* reverseLinkedList(ListNode* head) {

        if (head == NULL)
            return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* curr = dummyHead;
        int count = 0;
        ListNode* leftNode = NULL;
        ListNode* rightNode = NULL;
        while (curr != NULL) {
            if ((left - 1) == count) {
               
                leftNode = curr;
            }
            if (count == right) {
                rightNode = curr;
                break;
            }
            count++;
            curr = curr->next;
        }
        ListNode* startNode = leftNode->next;
        ListNode* nextToRightNode = rightNode->next;
        rightNode->next = NULL;
        leftNode->next=NULL;
        reverseLinkedList(startNode);
        leftNode->next = rightNode;
        startNode->next = nextToRightNode;
        head = dummyHead->next;
        dummyHead->next = NULL;
        delete dummyHead;
        return head;
    }
};
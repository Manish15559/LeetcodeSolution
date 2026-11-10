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
    int count;
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
        ListNode* node = head;
        count = 0;
        while (node != NULL) {
            count++;
            node = node->next;
        }
    }
    int getNodeValue(int kthNode) {
        ListNode* node = head;
        while (kthNode > 0) {
            node = node->next;
            kthNode--;
        }
        return node->val;
    }

    int getRandom() {
        // int n=arr.size();
        int randomIdx = rand() % count;
        return getNodeValue(randomIdx);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
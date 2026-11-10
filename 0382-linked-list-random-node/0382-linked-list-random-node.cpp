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
    vector<int>arr;
    Solution(ListNode* head) {
        ListNode *node=head;
        while(node!=NULL){
            arr.push_back(node->val);
            node=node->next;
        }
        
    }
    
    int getRandom() {
        int n=arr.size();
        int randomIdx= rand()%n;
        return arr[randomIdx];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */